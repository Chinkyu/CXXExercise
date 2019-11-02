#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
F(3)= min{ F(3−c1),F(3−c2),F(3−c3)}+1
	= min{ F(3−1),F(3−2),F(3−3) }+1
	= min{ F(2),F(1),F(0) }+1
	= min{ 1,1,0 }+1
	= 1
*/
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		int max = amount + 1;
		vector<int> dp(amount + 1, max);

		dp[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			for (int j = 0; j < coins.size(); ++j) {
				if (coins[j] <= i) {
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}
};

class _Solution {
public:
	int min = INT_MAX;

	void traverse(vector<int>& coins, int amount, int level) {
		if (amount < 0) return;

		for (auto it : coins) {
			if (amount - it == 0) {
				if (min > level + 1) min = level + 1;
			}
			else if (amount - it > 0) {
				traverse(coins, amount - it, level + 1);
			}
		} 
	}

	int coinChange(vector<int>& coins, int amount) {

		if (amount == 0) return 0;
		min = INT_MAX;
		traverse(coins, amount, 0);
		if (min == INT_MAX) min = -1;
		return min;
	}
};

int main() {
	char c;
	vector<int> coins = { 1, 2, 5 };
	Solution sol;

	cout << sol.coinChange(coins, 11);

	cin >> c;
}