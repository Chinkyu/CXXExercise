//타임아웃나서  스라이딩 윈도우로 품
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
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
		vector<pair<int, int>> sliding;
		vector<int> seat(n + 1, 0);

		for (auto it : bookings) {
			sliding.push_back(make_pair(it[0], it[2]));
			if (it[1] < n) sliding.push_back(make_pair(it[1] + 1, it[2] * -1));
		}

		// sort in first
 		sort(sliding.begin(), sliding.end());

		int si = 0;
		for (int i = 1; i <= n; ++i) {
			seat[i] = seat[i - 1];
			while (si < sliding.size() && sliding[si].first == i) {
				seat[i] += sliding[si].second;
				si++;
			}
		}

		seat.erase(seat.begin());
		return seat;
	}
};

// timeout : sliding window  로 풀어야 할것 같다.. 
class _Solution {
public:
	vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
		vector<int> s(n+1, 0);

		for (auto it : bookings) {
			for (int i = it[0]; i <= it[1]; ++i) {
				s[i] += it[2];
			}
		}

		s.erase(s.begin());
		return s;
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> bookings = { {1, 2, 10},{2, 3, 20},{2, 5, 25 }};

	vector<int> ans = sol.corpFlightBookings(bookings, 5);

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}