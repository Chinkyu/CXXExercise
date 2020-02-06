dp[i][j] refers to the answer of elements[i + 1, j + 1]

class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
		for (int i = 0; i < n; i++) dp[i][i] = 0;
		for (int len = 2; len <= n; len++) {
			for (int i = 0; i + len - 1 < n; i++) {
				int j = i + len - 1;
				for (int k = i; k <= j; k++) {
					if (k == i) {
						dp[i][j] = min(dp[i][j], dp[k + 1][j] + k + 1);
					}
					else if (k == j) {
						dp[i][j] = min(dp[i][j], dp[i][k - 1] + k + 1);
					}
					else {
						dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k + 1);
					}
				}
			}
		}
		return dp[0][n - 1];
	}
};


#include <iostream>

using namespace std;

class Solution {
public:
	int getmin(int l, int r) {
		int ansl = 0, ansr = 0, ans = 0;

		if (l + 2 == r) {
			return (l + r) / 2;
		}
		else if (l + 1 == r) {
			return l;
		}

		int m = 0;
		if ((r - l + 1) % 2 == 0) { // even -> reculsive
			m = (l + r) / 2;
			ansl = getmin(m + 1, r);
			ansr = getmin(m + 2, r);

			if (ansl > ansr) {
				ans += ansr;
				l = m + 2;
			}
			else {
				ans += ansl;
				l = m + 1;
			}
		}
		else {
			m = (l + r) / 2;
			ans += m;
			l = m + 1;
		}
		return ans;
	}


	int getMoneyAmount(int n) {
		return getmin(1, n);
	}
};

int main() {
	char c;
	Solution sol;

	cout << sol.getMoneyAmount(10);

	cin >> c;
}
