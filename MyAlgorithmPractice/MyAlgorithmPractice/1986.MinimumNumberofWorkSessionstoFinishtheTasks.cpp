// ¥‰∫√¿Ω  :  dp with bitmap??   napsack?? 
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
	int n, sessionTime;
	int memo[1 << 14][15] = {};
	int minSessions(vector<int>& tasks, int sessionTime) {
		n = tasks.size();
		this->sessionTime = sessionTime;
		memset(memo, -1, sizeof(memo));
		return dp(tasks, (1 << n) - 1, 0);
	}
	int dp(vector<int>& tasks, int mask, int remainTime) {
		if (mask == 0) return 0;
		if (memo[mask][remainTime] != -1) return memo[mask][remainTime];
		int ans = n;  // There is up to N work sessions
		for (int i = 0; i < n; ++i) {
			if ((mask >> i) & 1) {
				int newMask = ~(1 << i) & mask; // clear i th bit
				if (tasks[i] <= remainTime) {
					ans = min(ans, dp(tasks, newMask, remainTime - tasks[i])); // Consume current session
				}
				else {
					ans = min(ans, dp(tasks, newMask, sessionTime - tasks[i]) + 1); // Create new session
				}
			}
		}
		return memo[mask][remainTime] = ans;
	}
};

class _Solution {
public:
	int minSessions(vector<int>& tasks, int sessionTime) {

		int sum = 0;
		for (auto &it : tasks) {
			sum += it;
		}

		return (int)ceil((double)sum / sessionTime);
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> tasks = {3,1,3,1,1};

	cout << sol.minSessions(tasks, 8);

	cin >> c;
}