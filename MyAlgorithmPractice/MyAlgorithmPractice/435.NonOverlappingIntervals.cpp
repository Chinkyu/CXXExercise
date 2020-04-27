// Using method of swap wipe?? 

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Eason Solution 

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int sz = intervals.size();

		if (sz <= 0) return 0;

		auto comp = [](vector<int>& i1,  vector<int>& i2) { return i1[0] < i2[0]; };
		sort(intervals.begin(), intervals.end(), comp);

		int res = 0, pre = 0;
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] < intervals[pre][1]) {
				res++;
				if (intervals[i][1] < intervals[pre][1]) pre = i;
			}
			else pre = i;
		}
		return res;
	}
};


class _Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		map<int, int> m;
		int sz = intervals.size();

		if (sz <= 0) return 0;

		for (int i = 0; i < sz; ++i) {
			int st = intervals[i][0];
			int ed = intervals[i][1];

			if (m.size() == 0) {
				m[st] = 1;
				m[ed + 1] = 0;
				continue;
			}

			int level = 0;
			int state = 0;
			for (auto it : m) {
				if (state == 0) {
					if (st < it.first) {
						m[st] = level + 1;
						level = m[st];
						state = 1;
					}
					else if (st == it.first) {
						m[st]++;
						level = m[st];
						state = 1;
					}
				}
				
				if(state == 1) {
					if (it.first < ed+1) {
						it.second++;
						level = it.second;
						state = 2;
					} else if (it.first == ed+1) {
						//it.second--;
						level = it.second;
						state = 2;
						break;
					}
					else {  // ed+1 < it.first
						m[ed + 1] = level - 1;
						level = m[ed + 1];
						state = 2;
						break;
					}
				}
			}

//			if ((m.end())  < ed+1) {
//				m[ed + 1] = 0;
//			}
		}

		int max = 0;
		for (auto it : m) {
			if (it.second > max) max = it.second;
		}
		return max - 1;
	}
};


int main() {
	char c;
	Solution sol;
	//vector<vector<int>> v = { {1, 2},{1, 2},{1, 2} };
	//vector<vector<int>> v = { {1, 100},{11, 22},{1, 11},{2, 12} };
	vector<vector<int>> v = { {1, 2},{1, 2},{1, 2}, {100, 200}, {110, 190}, {120, 180}, {130, 170} };
	cout << sol.eraseOverlapIntervals(v);

	cin >> c;
}