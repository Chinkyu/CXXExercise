#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class _Solution {
	int ASum = 0;
	int BSum = 0; 
	bool isFound = false;

public:

	void iterate(vector<int> & v, int s, int e, int user) {

		if (isFound == true) return;

		if (s == e) {
			if (user == 1) {
				ASum += v[s];
				if (ASum > BSum) {
					isFound = true;
				}
				ASum -= v[s];
			}
			else {
				BSum += v[s];
				if (ASum > BSum) {
					isFound = true;
				}
				BSum -= v[s];
			}

			return;
		}

		if (user == 1) {
			ASum += v[s];
			iterate(v, s + 1, e, 2);
			ASum -= v[s];

			ASum += v[e];
			iterate(v, s, e - 1, 2);
			ASum -= v[e];
		}
		else {
			if (v[s] > v[e]) {
				BSum += v[s];
				iterate(v, s+1, e, 1);
				BSum -= v[s];
			} else if (v[s] < v[e]) {
				BSum += v[e];
				iterate(v, s, e - 1, 1);
				BSum -= v[e];
			}
			else {
				BSum += v[s];
				iterate(v, s + 1, e, 1);
				BSum -= v[s];

				BSum += v[e];
				iterate(v, s, e - 1, 1);
				BSum -= v[e];
			}
		}

	}

	bool PredictTheWinner(vector<int>& nums) {
		ASum = 0;
		BSum = 0;
		isFound = false;

		if (nums.size() == 1) return true;

		iterate(nums, 0, nums.size() - 1, 1);
		return isFound;
	}
};

class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n)); // use to keep the score gap between player1 and player2
		for (int i = 0; i < n; i++) dp[i][i] = nums[i];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j + i < n; j++) {
				dp[j][j + i] = max(nums[j + i] - dp[j][j + i - 1], nums[j] - dp[j + 1][j + i]);
			}
		}
		return dp[0][n - 1] >= 0; // player1 get more score points than player2
	}
};


int main() {
	char c;
	Solution sol;

//	vector<int> v = { 1, 5, 2 };
	vector<int> v = { 1, 5, 233, 7 };
	cout << sol.PredictTheWinner(v);

	cin >> c;
}

