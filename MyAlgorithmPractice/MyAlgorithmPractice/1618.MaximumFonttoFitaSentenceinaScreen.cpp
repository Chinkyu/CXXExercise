// 한꺼번에 돌릴려고 하다가 오래 걸림... high 찾고 width 찾으면 됨 
// 그리고 그 값을 찾은것이 아니라 변위를 찾아야 되서....  조금 다르게 하면 됨.. 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */

class FontInfo {
public:
	// Return the width of char ch when fontSize is used.
	int getWidth(int fontSize, char ch);
	
	// Return Height of any char when fontSize is used.
	int getHeight(int fontSize);
};

class Solution {
public:

	int getAllWidth(int fontSize, string &text, FontInfo &fontInfo) {
		int w = 0;
		for (auto it : text) {
			w += fontInfo.getWidth(fontSize, it);
		}
		return w;
	}

	int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
		int l = fonts.size();

		int sidx = 0, eidx = l - 1;
		int midx = (sidx + eidx) / 2;


		while (sidx + 1 < eidx) {
			int mHight = fontInfo.getHeight(fonts[midx]);
			if (mHight <= h) {
				sidx = midx;
				midx = (sidx + eidx) / 2;
			}
			else if (h < mHight) {
				eidx = midx;
				midx = (sidx + eidx) / 2;
			}
		}

		int sHigh = fontInfo.getHeight(fonts[sidx]);
		int eHigh = fontInfo.getHeight(fonts[eidx]);

		if (sHigh < h && eHigh <= h) {
			eidx = eidx;
		}
		else if (sHigh <= h && h < eHigh) {
			eidx = sidx;
		}
		else if (h < sHigh && h < eHigh) {
			return -1;
		}

		sidx = 0;
		midx = (sidx + eidx) / 2;


		while (sidx + 1  < eidx) {

			int mAllWidth = getAllWidth(fonts[midx], text, fontInfo);

			if (mAllWidth <= w) {
				sidx = midx;
				midx = (sidx + eidx) / 2;
			}
			else if (h < mAllWidth) {
				eidx = midx;
				midx = (sidx + eidx) / 2;
			}
		}

		// only two sidx, eidx
		int sAllWidth = getAllWidth(fonts[sidx], text, fontInfo);
		int eAllWidth = getAllWidth(fonts[eidx], text, fontInfo); 


		if (sAllWidth < w && eAllWidth <= w) {
			return (fonts[eidx]);
		}
		else if (sAllWidth <= w && w < eAllWidth) {
			return (fonts[sidx]);
		}
		else if (w < sAllWidth && w < eAllWidth) {
			return -1;
		}

		return -1;
	}
};

int main() {
	char c;

	Solution sol;


	cout << sol.maxFont("helloword", 80, 20, { 6, 8, 10, 12,14, 16,24, 36 });
	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}