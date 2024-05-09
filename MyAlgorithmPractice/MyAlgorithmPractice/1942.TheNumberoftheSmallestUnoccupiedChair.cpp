// OK
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
	int smallestChair(vector<vector<int>>& times, int targetFriend) {
		int l = times.size();
		vector<vector<int>> h;

		for (int i = 0; i < l; ++i) {
			h.push_back({ times[i][0], i, 1 });
			h.push_back({ times[i][1], i, -1 });
		}

		sort(h.begin(), h.end(), 
			[](vector<int> &l, vector<int> &r) {
				if (l[0] == r[0]) {
					return l[2] < r[2];
				}
				else {
					return l[0] < r[0];
				}
			});

		multiset<int> empty;
		map<int, int> m;
		for (int i = 0; i < l; ++i) empty.insert(i);

		for (auto &it : h) {
			if (it[2] == 1) { // come
				int newChair = *empty.begin();

				if (it[1] == targetFriend) return newChair;

				empty.erase(empty.find(newChair));
				m[it[1]] = newChair;
			}
			else {			// leave
				int chairNum = m[it[1]];
				empty.insert(chairNum);
			}
		}

		return -1;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<int>> times = {{1, 4}, {2, 3}, {4, 6}};

	cout << sol.smallestChair(times, 1);

	cin >> c;
}