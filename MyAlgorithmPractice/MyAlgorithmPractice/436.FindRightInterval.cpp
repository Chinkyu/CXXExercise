#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		vector<vector<int>> sv = intervals;
		int l = intervals.size();
		vector<int> ans(l, -1);

		for (int i = 0; i < l; ++i) {
			sv[i][1] = i;
		}

		auto comp = [](vector<int>& i1, vector<int>& i2) { return i1[0] < i2[0]; };
		sort(sv.begin(), sv.end(), comp);

		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < l; ++j) {
				if (intervals[i][1] <= sv[j][0]) {
					ans[i] = sv[j][1];
					break;
				}
			}
		}
		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	//vector<vector<int>> v = {{3, 4},{2, 3},{1, 2}};
	vector<vector<int>> v = { {1, 4}, {2, 3}, {3, 4} };
	vector<int> ans = sol.findRightInterval(v);

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}