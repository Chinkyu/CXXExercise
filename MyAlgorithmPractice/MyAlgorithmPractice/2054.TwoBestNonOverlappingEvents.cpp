// 타임아웃나서 답봤음 : 다익스트라??
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
	int maxTwoEvents(vector<vector<int>>& events) {
		int n = events.size();
		sort(events.begin(), events.end());
		multiset<int> s;
		vector<int> maxi(n + 1, INT_MIN);
		maxi[n] = 0;
		s.insert(events[n - 1][2]);
		maxi[n - 1] = events[n - 1][2];
		vector<int> next(n, -1);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for (int i = 0; i < n; i++)
		{
			while (pq.size())
			{
				auto pr = pq.top();
				if (pr.first < events[i][0])
				{
					pq.pop();
					next[pr.second] = i;
				}
				else
					break;
			}
			pq.push({ events[i][1],i });
		}
		int ans = events[n - 1][2];
		while (pq.size())
		{
			auto pr = pq.top();
			pq.pop();
			next[pr.second] = n;
		}
		for (int i = n - 2; i >= 0; i--)
		{
			int index = next[i];
			ans = max(ans, events[i][2] + maxi[index]);
			maxi[i] = max(events[i][2], *(--s.end()));
			s.insert(events[i][2]);
		}
		return ans;

	}
};
// timeout 
class _Solution {
public:
	int maxTwoEvents(vector<vector<int>>& events) {
		//int l = events.size();
		int ans = 0;

		set<vector<int>> s;
		vector<vector<int>> mevents;
		for (auto &it : events) s.insert(it);
		for (auto &it : s) mevents.push_back(it);

		sort(mevents.begin(), mevents.end());

		int l = mevents.size();
		for (int i = 0; i < l; ++i) {
			ans = max(ans, mevents[i][2]);
			for (int j = i + 1; j < l; ++j) {
				if (mevents[i][1] < mevents[j][0]) {
					ans = max(ans, mevents[i][2] + mevents[j][2]);
				}
			}
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	//vector<vector<int>> events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
	vector<vector<int>> events = { {1, 1, 1}, {1, 1, 1}};

	cout << sol.maxTwoEvents(events);

	cin >> c;
}