//  답봣음..   DP  라는데.. 일반적으로는 
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
	int maximumProfit(vector<int>& pre, vector<int>& fut, int budget) {

		int n = pre.size();
		vector<vector<int>> dp(n + 1, vector<int>(budget + 1));

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= budget; j++) {

				dp[i][j] = dp[i - 1][j];
				if (j - pre[i - 1] >= 0 && fut[i - 1] > pre[i - 1])
					dp[i][j] = max(dp[i][j], (fut[i - 1] - pre[i - 1]) + dp[i - 1][j - pre[i - 1]]);
			}
		}

		return dp[n][budget];
	}

	int _maximumProfit(vector<int>& present, vector<int>& future, int budget) {

		//if (budget == 0) return 0;

		//int l = present.size();
		vector<vector<int>> sv; // (l, vector<int>(2, 0));

		for (int i = 0; i < present.size(); ++i) {
			if (future[i] < present[i]) continue;
			//sv[i][0] = present[i];
			//sv[i][1] = future[i] - present[i];
			sv.push_back( vector<int>{ present[i], future[i] - present[i] });
		}

		int l = sv.size();
		sort(sv.begin(), sv.end(), [](vector<int> &l, vector<int> &r) {
			if (l[1] == r[1]) return l[0] < r[0];
			return l[1] > r[1];
		});


		// from start check max
		int ans = 0;
		for (int i = 0; i < l; ++i) {
			int psum = 0, vsum = 0;
			for (int j = i; j < l; ++j) {
				psum += sv[j][0];
				if (psum > budget) {
					ans = max(ans, vsum);
					break;
				}
				vsum += sv[j][1];
				if (psum <= budget && j == l - 1) {
					ans = max(ans, vsum);
				}
			}
		}

		return ans;
	}
};



int main() {
	char c;

	Solution sol;

	//vector<int> present = { 5,4,6,2,3 };
	//vector<int> future = { 8,5,4,3,5 };

	vector<int> present = { 2,11,20,15,10,9,1,19,7 };
	vector<int> future = { 11,11,18,7,17,12,5,6,17 };

	cout << sol.maximumProfit(present, future, 10);

	cin >> c;

}