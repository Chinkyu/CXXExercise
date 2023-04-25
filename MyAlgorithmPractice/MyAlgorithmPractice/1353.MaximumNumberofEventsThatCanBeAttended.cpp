// priority queue를 사용해서 어렵지 않게 품
// priority queue사용하는 방법에 익숙해저야 할것 같다.. 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	int maxEvents(vector<vector<int>>& events) {
		sort(events.begin(), events.end());

		int l = events.size();
		int start_day = events[0][0], end_day = 0;
		for (auto it : events) {
			if (it[1] > end_day) end_day = it[1];
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		int idx = 0;
		int cnt = 0;
		for (int i = start_day; i <= end_day; ++i) {
			while (pq.size() != 0 && pq.top().first < i) {
				pq.pop();
			}

			while (idx < l && events[idx][0] == i) {
				pq.push(make_pair(events[idx][1], idx));
				idx++;
			}
			if (pq.size() != 0) {
				pq.pop();
				cnt++;
			}
		}
		return cnt;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> events = { {1, 2},{2, 3},{3, 4},{1, 2} };

	cout << sol.maxEvents(events);
	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}