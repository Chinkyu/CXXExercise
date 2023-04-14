//  야구 게임 어렵지 않게 풀림. 
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
	string getHint(string secret, string guess) {
		vector<int> count_secret(10, 0), count_guess(10, 0);

		for (auto it : secret) count_secret[it - '0']++;
		for (auto it : guess) count_guess[it - '0']++;

		// count min
		int ball_num = 0;
		for (int i = 0; i < 10; ++i) {
			ball_num += min(count_secret[i], count_guess[i]);
		}

		// find strike
		int strike_num = 0;
		for (int i = 0; i < secret.size(); ++i) {
			if (secret[i] == guess[i]) strike_num++;
		}

		ball_num -= strike_num;

		string ans;
		ans.append(to_string(strike_num) + "A");
		ans.append(to_string(ball_num) + "B");
		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	//vector<int> data = { 1,0,1,0,1,0,0,1,1,0,1 };
	cout << sol.getHint("1807", "7810");
	//vector<vector<int>> clips = {{0, 5}, {1, 6}, {2, 7}, {3, 8}, {4, 9}, {5, 10}, {6, 11}, {7, 12}, {8, 13}, {9, 14}, {10, 15}, {11, 16}, {12, 17}, {13, 18}, {14, 19}, {15, 20}, {16, 21}, {17, 22}, {18, 23}, {19, 24}, {20, 25}, {21, 26}, {22, 27}, {23, 28}, {24, 29}, {25, 30}, {26, 31}, {27, 32}, {28, 33}, {29, 34}, {30, 35}, {31, 36}, {32, 37}, {33, 38}, {34, 39}, {35, 40}, {36, 41}, {37, 42}, {38, 43}, {39, 44}, {40, 45}, {41, 46}, {42, 47}, {43, 48}, {44, 49}, {45, 50}, {46, 51}, {47, 52}, {48, 53}, {49, 54}};
	//cout << sol.videoStitching(clips, 50);


	cin >> c;
}