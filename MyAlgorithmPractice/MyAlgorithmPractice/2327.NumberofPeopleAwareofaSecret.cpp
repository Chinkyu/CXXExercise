//  dp  ¥‰∫√¿Ω. 
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
	int help(int delay, int forget, int n, vector<int> &dp) {
		int mod = 1e9 + 7;
		int a = forget;
		a -= delay;
		if (dp[n] != -1) return dp[n];
		int j = 0;
		int sum = 0;
		while (a > 0 && n - delay - j > 0) {
			a--;
			sum += ((long)help(delay, forget, n - delay - j, dp) % mod);
			sum = sum % mod;
			j++;
		}
		if (n - forget > 0) {
			dp[n] = (sum%mod);
		}
		else {
			dp[n] = ((sum + 1) % mod);
		}
		return dp[n];
	}
	int peopleAwareOfSecret(int n, int delay, int forget) {
		vector<int> dp(n + 1, -1);
		return help(delay, forget, n, dp);
	}
};

int main() {
	char c;

	Solution sol;

	//vector<int> nums1 = { 1, 2, 3, 4 };
	//vector<int> nums2 = { 2, 10, 20, 19 };

//	vector<int> nums1 = { 1, 4, 10, 12 };
//	vector<int> nums2 = { 5, 8, 6, 9 };
//	cout << sol.minSumSquareDiff(nums1, nums2, 10, 5);

//	vector<int> nums1 = { 10, 10, 10, 11, 5 };
//	vector<int> nums2 = { 1, 0, 6, 6, 1 };
//	cout << sol.minSumSquareDiff(nums1, nums2, 11, 27);

	vector<int> nums1 = { 18,4,8,19,13,8 };
	vector<int> nums2 = { 18,11,8,2,13,15 };
	cout << sol.minSumSquareDiff(nums1, nums2, 16, 8);

	cin >> c;

}