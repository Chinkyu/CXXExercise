//  easy
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>
#include <cmath>

using namespace std;


// answer from site
class _Solution {
public:
	int dp[101][1024] = {};
	int dfs_h(int h, int prev, const vector<int>& masks) {
		if (h == 0)
			return 1;
		if (dp[h][prev] == 0)
			for (int mask : masks)
				if ((mask & prev) == 0)
					dp[h][prev] = (dp[h][prev] + dfs_h(h - 1, mask, masks)) % 1000000007;
		return dp[h][prev];
	}
	vector<int> dfs_w(int w, int width, vector<int>& bricks, int mask, vector<int> &masks) {
		if (w == width)
			masks.push_back(mask);
		else {
			if (w)
				mask += (1 << (w - 1));
			for (int b : bricks)
				if (w + b <= width)
					dfs_w(w + b, width, bricks, mask, masks);
		}
		return masks;
	}
	int buildWall(int height, int width, vector<int>& bricks) {
		return dfs_h(height, 0, dfs_w(0, width, bricks, 0, vector<int>() = {}));
	}
};


class Solution {
public:
	void findCombination(int width, vector<int> &bricks, set<vector<int>> &s, int cWidth, vector<int> &cBricks) {

		// for safety
		if (cWidth > width) {
			return;
		}

		for (auto &it : bricks) {
			if (cWidth + it > width) {
				break;
			}
			else if (cWidth + it < width) {
				cWidth += it;
				cBricks.push_back(cWidth);
				findCombination(width, bricks, s, cWidth, cBricks);
				cBricks.pop_back();
				cWidth -= it;
			}
			else {  // == 
				s.insert(cBricks);
				for (auto &it : cBricks) {
					cout << it << " ";
				}
				cout << endl;

				break;
			}
		}

	}


	int buildWall(int height, int width, vector<int>& bricks) {

		// find all combinations 
		set<vector<int>>  s;
		int cWidth = 0;
		vector<int> cBricks;

		sort(bricks.begin(), bricks.end());

		vector<int> t = { 1, 2, 3 };
		s.insert(t);

		findCombination(width, bricks, s, cWidth, cBricks);


		return 1;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> bricks = { 1, 2 };

	cout << sol.buildWall( 2, 3, bricks);

	cin >> c;

}