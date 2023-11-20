//  답봤음..  abulation dp 를 쓴다는데.... 
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

using namespace std;

class Solution {
public:
	int countTexts(string k) {
		int dp[5] = { 1, 1, 1, 1, 1 }, n = k.size();
		for (int i = n - 1; i >= 0; --i) {
			dp[i % 5] = 0;
			int max_j = min(n, i + (k[i] == '7' || k[i] == '9' ? 4 : 3));
			for (int j = i; j < max_j && k[i] == k[j]; ++j)
				dp[i % 5] = (dp[i % 5] + dp[(j + 1) % 5]) % 1000000007;
		}
		return dp[0];
	}
};

class _Solution {
public:
	int factorial(int n) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) ans += i;
		return ans;
	}

	long long myPow(int d1, int num) {
		long long powR = 1;
		for (int i = 0; i < num; ++i) {
			powR *= d1;
			//powR %= 1000000007;
		}
		return powR;
	}

	int countTexts(string pressedKeys) {
		long long ans = 0;
		int preNum = 0;
		int cNum = 0;
		for (auto it : pressedKeys) {
			if (it != preNum) {
				if (cNum > 0) {
					if (it == 9) { // 4 factorial
						int div = cNum / 4;
						int rem = cNum % 4;

						ans += pow(factorial(4), div) + factorial(rem);
						//ans %= 1000000007;
					}
					else {  // 3 factori
						int div = cNum / 3;
						int rem = cNum % 3;
						ans += pow(factorial(4), div) + factorial(rem);
						//ans %= 1000000007;
					}
				}
				preNum = it;
				cNum = 1;
			}
			else {
				cNum++;
			}
		}

		if (cNum > 0) {
			if (pressedKeys[pressedKeys.size() - 1] == 9) { // 4 factorial
				int div = cNum / 4;
				int rem = cNum % 4;

				ans += pow(factorial(4), div) + factorial(rem);
				//ans %= 1000000007;
			}
			else {  // 3 factori
				int div = cNum / 3;
				int rem = cNum % 3;
				ans += pow(factorial(3), div) + factorial(rem);
				//ans %= 1000000007;
			}
		}

		return ans % 1000000007;
	}
};

int main() {
	char c;

	Solution sol;

	string pressedKeys = "222222222222222222222222222222222222"; // "22233";
	cout << sol.countTexts(pressedKeys);

	cin >> c;

}