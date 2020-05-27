
/*
//**This is a combination problem, not permutation problem, so we care about if a type of coin is used or not

let coins[i] = {1,2,5}
let C[i][j] be the # of combinations of i types of coins with amount j
there can be two cases:
1. the ith type of coin has not been used to make up amount j
C[i-1][j]
2. the ith type of coin was used before, and can be used again to make up amount j
C[i][j-coins[i]]

so the dp function:

C[i][j] = C[i-1][j] + C[i][j-coins[i]]

base case:
C[i][0] = 1, because there can be one combination to make up amount 0

*/
//T(n) = O(m*n), where m is the # of types of coins, n is amount
//S(n) = O(m*n)
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		if (amount == 0) { return 1; }
		if (coins.empty()) { return 0; }
		int len = coins.size();
		vector<vector<int>> dp(len + 1, vector<int>(amount + 1, 0));

		for (int i = 0; i < len; i++) {
			for (int j = 0; j <= amount; j++) {
				if (j == 0) {
					dp[i][j] = 1;
					continue;
				}
				if (i == 0) {
					if (coins[i] > j) {
						//the current coin type can not be used if its face value is greater than current amount
						dp[i][j] = 0;
					}
					else {
						dp[i][j] = dp[i][j - coins[i]];
					}
					continue;
				}

				if (coins[i] > j) {
					//the current coin type can not be used if its face value is greater than current amount
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
				}
			}
		}
		return dp[len - 1][amount];
	}

};