//  ???
#include <iostream>
#include <vector>
#include <unordered_map>
// ?? 
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

int dp[1001][1001] = {}, mod = 1000000007;
class Solution {
public:
	int dfs(int k, int d) {
		if (d >= k)
			return d == k;
		if (dp[k][d] == 0)
			dp[k][d] = (1 + dfs(k - 1, d + 1) + dfs(k - 1, abs(d - 1))) % mod;
		return dp[k][d] - 1;
	}
	int numberOfWays(int startPos, int endPos, int k) {
		return dfs(k, abs(startPos - endPos));
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> nums = { 84139415,693324769,614626365,497710833,615598711,264,65552,50331652,1,1048576,16384,544,270532608,151813349,221976871,678178917,845710321,751376227,331656525,739558112,267703680 };
	//{ 3, 1, 5, 11, 13 }; // {1, 3, 8, 48, 10};

	cout << sol.longestNiceSubarray(nums);

	cin >> c;
}