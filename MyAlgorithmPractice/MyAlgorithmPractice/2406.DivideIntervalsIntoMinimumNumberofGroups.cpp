//  sliding window  and  careful  when overlap
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
	int minGroups(vector<vector<int>>& intervals) {
		vector<vector<int>> sw;

		for (auto it : intervals) {
			sw.push_back({ it[0], 1 });
			sw.push_back({ it[1], -1 });
		}

		sort(sw.begin(), sw.end(), [](vector<int> &l, vector<int> &r) {
			if (l[0] == r[0]) return l[1] > r[1];

			return l[0] < r[0];
		});

		int level = 0, tmax = 0;

		for (int i = 0; i < sw.size(); ++i) {
			if (sw[i][1] == 1) {
				level++;
			}
			else {
				level--;
			}
				
			tmax = max(tmax, level);
		}


		return tmax;
	}
};

int main() {
	char c;
	
	Solution sol;

	vector<vector<int>> intervals = { {5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10} };
	cout << sol.minGroups(intervals);

	cin >> c;
}