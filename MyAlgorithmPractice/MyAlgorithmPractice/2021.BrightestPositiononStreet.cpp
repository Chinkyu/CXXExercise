//  easy : sliding window
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
	int brightestPosition(vector<vector<int>>& lights) {

		vector<pair<int, int>> v;

		for (auto &it : lights) {
			v.push_back(make_pair(it[0] - it[1], 1));
			v.push_back(make_pair(it[0] + it[1] + 1, -1));
		}

		sort(v.begin(), v.end(), [](pair<int, int> &l, pair<int, int> &r) {
			if (l.first == r.first) {
				return l.second < r.second;
			}

			return l.first < r.first;
		});

		int tmax = 0, tmaxpos = INT_MIN;
		int cBright = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i].second == 1) {
				cBright++;
			}
			else {
				cBright--;
			}
			
			if (cBright > tmax) {
				tmax = cBright;
				tmaxpos = v[i].first;
			}
		}

		return tmaxpos;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<int>> lights = {{-3, 2}, {1, 2}, {3, 3}};

	cout << sol.brightestPosition(lights);

	cin >> c;
}