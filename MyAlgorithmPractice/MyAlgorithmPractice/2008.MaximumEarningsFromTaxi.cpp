// ¥‰∫√¿Ω : recursive and memoization 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	unordered_map<long long, vector<pair<long long, long long>>>mp;
	vector<long long>dp;
	long long maxTaxiEarnings(int n, vector<vector<int>>& A) {
		sort(A.begin(), A.end());
		vector<long long> dp(n + 1);
		int j = 0;
		for (int i = 1; i <= n; ++i) {
			dp[i] = max(dp[i], dp[i - 1]);
			while (j < A.size() && A[j][0] == i)
				dp[A[j++][1]] = max(dp[A[j][1]], dp[i] + A[j][1] - A[j][0] + A[j][2]);
		}
		return dp[n];
	}

};


int main() {
	char c;
	Solution sol;

	vector<int> nums = { 2, 3, 4, 4, 5 }; // { 1, 2, 3};

	cout << sol.sumOfBeauties(nums);

	cin >> c;
}