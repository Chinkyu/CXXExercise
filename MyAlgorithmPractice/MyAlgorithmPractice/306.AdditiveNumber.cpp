// 그냥 카피했음... 다음에 보자...!!
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
	bool isAdditiveNumber(string num)
	{
		return helper(num, 0, -1, -1, LONG_MAX / 100);
	}
	bool helper(string num, int inx, long first, long second, long mx)
	{
		int n = num.length();
		long val = 0;
		for (int i = inx; i < n; i++)
		{
			val = val * 10 + (num[i] - '0');
			if (i > inx && num[inx] == '0' || val > mx) break;
			if (first == -1)
			{
				if (helper(num, i + 1, val, second, mx)) return true;
			}
			else if (second == -1)
			{
				if (helper(num, i + 1, first, val, mx)) return true;
			}
			else
			{
				if (first + second == val)
				{
					if (i == n - 1) return true;
					return helper(num, i + 1, second, val, mx);
				}
				if (first + second < val) break;
			}
		}
		return false;
	}
};

class _Solution {
public:

	bool findAdditive(vector<int> &n, int fst, int snd, int &ssize, int &sum_size) {
		int fsize = snd - fst;

		for (int i = 1; i <= 35; ++i) {
			vector<int> v(max(fsize, i), 0);

			
		}
	}

	bool isAdditiveNumber(string num) {
		vector<int> n(num.size(), 0);

		for (int i = 0; i < num.size(); ++i) n[i] = num[i] = '0';




	}
}

int main() {
	char c;

	Solution sol;
	//vector<int> data = { 1,0,1,0,1,0,0,1,1,0,1 };
	cout << sol.getHint("1807", "7810");
	//vector<vector<int>> clips = {{0, 5}, {1, 6}, {2, 7}, {3, 8}, {4, 9}, {5, 10}, {6, 11}, {7, 12}, {8, 13}, {9, 14}, {10, 15}, {11, 16}, {12, 17}, {13, 18}, {14, 19}, {15, 20}, {16, 21}, {17, 22}, {18, 23}, {19, 24}, {20, 25}, {21, 26}, {22, 27}, {23, 28}, {24, 29}, {25, 30}, {26, 31}, {27, 32}, {28, 33}, {29, 34}, {30, 35}, {31, 36}, {32, 37}, {33, 38}, {34, 39}, {35, 40}, {36, 41}, {37, 42}, {38, 43}, {39, 44}, {40, 45}, {41, 46}, {42, 47}, {43, 48}, {44, 49}, {45, 50}, {46, 51}, {47, 52}, {48, 53}, {49, 54}};
	//cout << sol.videoStitching(clips, 50);


	cin >> c;
}