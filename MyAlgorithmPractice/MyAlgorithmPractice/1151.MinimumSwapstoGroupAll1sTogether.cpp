// 답보고 내가 짰음...  이런식의 아이디어를 내는것이 힘듬.. !!
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	int minSwaps(vector<int>& data) {
		int l = data.size();
		vector<int> ac(l, 0);

		ac[0] = data[0];
		for (int i = 1; i < l; ++i) {
			ac[i] += ac[i - 1] + data[i];
		}

		int width = ac[l - 1];
		if (width == 0 || width == 1) return 0;

		int max_ones = ac[width - 1];
		for (int i = 1; i + width < l; ++i) {
			int cur_ones = ac[i + width] - ac[i];
			if (cur_ones > max_ones) max_ones = cur_ones;
		}

		return width - max_ones;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> data = { 1,0,1,0,1,0,0,1,1,0,1 };
	cout << sol.minSwaps(data);

	//vector<vector<int>> clips = {{0, 5}, {1, 6}, {2, 7}, {3, 8}, {4, 9}, {5, 10}, {6, 11}, {7, 12}, {8, 13}, {9, 14}, {10, 15}, {11, 16}, {12, 17}, {13, 18}, {14, 19}, {15, 20}, {16, 21}, {17, 22}, {18, 23}, {19, 24}, {20, 25}, {21, 26}, {22, 27}, {23, 28}, {24, 29}, {25, 30}, {26, 31}, {27, 32}, {28, 33}, {29, 34}, {30, 35}, {31, 36}, {32, 37}, {33, 38}, {34, 39}, {35, 40}, {36, 41}, {37, 42}, {38, 43}, {39, 44}, {40, 45}, {41, 46}, {42, 47}, {43, 48}, {44, 49}, {45, 50}, {46, 51}, {47, 52}, {48, 53}, {49, 54}};
	//cout << sol.videoStitching(clips, 50);


	cin >> c;
}