// 답 봤음... 그런데 이렇게 풀린다는게.. 좀 이해 안됨.. 
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
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		priority_queue<pair<int, int>> pq;

		for (int i = 0; i < profit.size(); i++) {
			pq.push({ profit[i],difficulty[i] });
		}
		sort(worker.begin(), worker.end());
		int i = worker.size() - 1;
		int ans = 0;
		while (i >= 0 && !pq.empty()) {
			if (worker[i] >= pq.top().second) {
				ans += pq.top().first;
				i--;
			}
			else {
				pq.pop();
			}
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> ages = { 16, 17, 18 };

	cout << sol.numFriendRequests(ages);


	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}