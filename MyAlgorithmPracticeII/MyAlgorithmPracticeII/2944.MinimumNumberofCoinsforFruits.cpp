// see answer : dp

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n + 1, 0);
        deque<int> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && (q.front() + 1) * 2 < i + 1)
                q.pop_front();
            while (!q.empty() && dp[q.back()] + A[q.back()] >= dp[i] + A[i])
                q.pop_back();
            q.push_back(i);
            dp[i + 1] = dp[q.front()] + A[q.front()];
        }
        return dp[n];
    }
};

int main() {
	char c;
	Solution sol;

	vector<int> nums = { 2,10,7,5,4,1,8,6 };

	cout << sol.minimumDeletions(nums);

	cin >> c;
}