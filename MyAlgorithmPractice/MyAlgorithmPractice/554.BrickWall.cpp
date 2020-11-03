#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		int ans = 0;
		int max_num = 0;
		// make accumulate array
		for (int i = 0; i < wall.size(); ++i) {
			int inc = 0;
			for (int j = 0; j < wall[i].size(); ++j) {
				wall[i][j] = wall[i][j] + inc;
				inc = wall[i][j];
			}
			if (inc > max_num) max_num = inc;
		}

#if 0
		// print 
		for (auto it : wall) {
			for (auto jt : it) {
				cout << jt << " ";
			}
			cout << endl;
		}
#endif 

		int xl = wall.size();
//		vector<int> ca(max_num+1, 0);
		map<int, int> m;

		for (auto it : wall) {
			for (auto jt : it) {
				m[jt]++;
			}
		}
		
		// find largest & less than xl
		vector<int> ca;
		int max_acc = 0;
		for (auto it : m) {
			//if (it.second > max_acc && it.second < xl) max_acc = it.second;
			ca.push_back(it.second);
		}

		sort(ca.begin(), ca.end());

		if (ca.size() <= 1) return xl;
		return ca[ca.size() - 1] - ca[ca.size() - 2];

//		return ca[max_num] - ca[max_num -1];
//		return xl - max_acc;
	}
};

int main() {
	char c;
	Solution sol;
#if 0
	vector<vector<int>> m =
	{ {1, 2, 2, 1},
	{3, 1, 2},
	{1, 3, 2},
	{2, 4},
	{3, 1, 2},
	{ 1, 3, 1, 1} };
#endif

	vector<vector<int>> m =
	{ {100000000},{100000000},{100000000} };

	cout << sol.leastBricks(m);


	cin >> c;
}