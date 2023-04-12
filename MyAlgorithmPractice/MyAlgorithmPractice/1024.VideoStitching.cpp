// 답봤음....  : 대략 이해는 가는데... 이런 생각을 하는것이 쉽지 않아.. 
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

	/* Approach : Greedy */

	/*

	Observation (1):

	For similar starting point , we will pick that one which has the
	maximum range , [a,b] , [a,d]. If (b>d) we will pick the interval [a,b] for
	sure as it will cover the longest distance towards the right.

	Observation (2):

	Now what we will do , when we reach the end of the choosen interval
	[a,b]. See, if (b==time) , then we are able to reach our destination so
	return the total number of intervals we used so far. Else , we start
	searching an interval , which has its starting point <= b and has the
	maximum covering towards the right .

	*/

	/*

	T.C : O(N + time)
	S.C : O(time)

	*/

	int videoStitching(vector<vector<int>>& clips, int time) {

		vector<int>dp(time + 1, -1);

		for (int i = 0; i < clips.size(); i++) {

			int left = min(clips[i][0], time);
			int right = min(clips[i][1], time);

			dp[left] = max(dp[left], right);

		}

		int currmax = dp[0];
		int nextmax = -1;
		int jumps = 1;
		if (dp[0] == time) return 1;
		for (int i = 0; i <= time; i++) {
			nextmax = max(nextmax, dp[i]);
			if (currmax == i) {
				currmax = nextmax;
				jumps++;
			}

			if (currmax == time) {
				return jumps;
			}
		}

		return -1;

	}
};
class _Solution {
public:
	int min_num_take = INT_MAX;
	void recurse(vector<vector<int>> &clips, int idx, int num_take, int time) {
		int l = clips.size();
		int start = clips[idx][0], end = clips[idx][1];

		if (num_take > min_num_take) return;

		if (clips[idx][0] <= time && time <= clips[idx][1]) {
			if (min_num_take > num_take) min_num_take = num_take;
			cout << num_take << endl;
			return;
		}

		for (int i = idx + 1; i < l; ++i) {
			if (start < clips[i][0] && clips[i][0] <= end && end < clips[i][1]) {
				recurse(clips, i, num_take + 1, time);
			}
			else if (end < clips[i][0]) {  // no overlap after
				break;
			}
		}
	}


	int videoStitching(vector<vector<int>>& clips, int time) {
		int ans = 0;
		min_num_take = INT_MAX;
		sort(clips.begin(), clips.end());

		for (int i = 0; i < clips.size(); ++i) {
			if (clips[i][0] == 0) recurse(clips, i, 1, time);
			else if (clips[i][0] > 0) break;
		}

		if (INT_MAX == min_num_take) return -1;
		return min_num_take;
	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> clips = {{0, 2}, {4, 6}, {8, 10}, {1, 9}, {1, 5}, {5, 9}};
	cout << sol.videoStitching(clips, 10);

	//vector<vector<int>> clips = {{0, 5}, {1, 6}, {2, 7}, {3, 8}, {4, 9}, {5, 10}, {6, 11}, {7, 12}, {8, 13}, {9, 14}, {10, 15}, {11, 16}, {12, 17}, {13, 18}, {14, 19}, {15, 20}, {16, 21}, {17, 22}, {18, 23}, {19, 24}, {20, 25}, {21, 26}, {22, 27}, {23, 28}, {24, 29}, {25, 30}, {26, 31}, {27, 32}, {28, 33}, {29, 34}, {30, 35}, {31, 36}, {32, 37}, {33, 38}, {34, 39}, {35, 40}, {36, 41}, {37, 42}, {38, 43}, {39, 44}, {40, 45}, {41, 46}, {42, 47}, {43, 48}, {44, 49}, {45, 50}, {46, 51}, {47, 52}, {48, 53}, {49, 54}};
	//cout << sol.videoStitching(clips, 50);


	cin >> c;
}