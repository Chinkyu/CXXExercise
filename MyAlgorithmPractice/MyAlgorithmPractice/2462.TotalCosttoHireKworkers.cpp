// debugging 하고 문제 이해 하는데 시간이 좀 걸림. 
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
	long long totalCost(vector<int>& costs, int k, int candidates) {
		int l = costs.size();
		long long ans = 0;

		int st = 0, ed = l - 1;
		priority_queue<int, vector<int>, greater<int>> pq1, pq2;

		if (l < 2 * candidates) {
			for (auto it : costs) {
				pq1.push(it);
			}

			for (int i = 0; i < k; ++i) {
				ans += pq1.top();
				pq1.pop();
			}
			return ans;
		}

		for (int i = 0; i < candidates; ++i) {
			pq1.push(costs[st++]);
			pq2.push(costs[ed--]);
		}


		for (int i = 0; i < k; ++i) {
			int pq1t = (pq1.size() > 0) ? pq1.top() : INT_MAX;
			int pq2t = (pq2.size() > 0) ? pq2.top() : INT_MAX;
			if (pq1t <= pq2t) {
				ans += pq1t;
				pq1.pop();
				if(st <= ed) pq1.push(costs[st++]);
			}
			else {
				ans += pq2t;
				pq2.pop();
				if(st <= ed ) pq2.push(costs[ed--]);
			}

			//if (ed == st) break;
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	//vector<int> costs = { 17,12,10,2,7,2,11,20,8 };
	vector<int> costs = { 57,33,26,76,14,67,24,90,72,37,30 };

	cout << sol.totalCost(costs, 11, 2);

	cin >> c;
}