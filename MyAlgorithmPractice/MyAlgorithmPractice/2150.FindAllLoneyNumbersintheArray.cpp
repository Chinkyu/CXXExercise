// easy 
#include <iostream>
#include <vector>
#include <unordered_map>
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
	vector<int> findLonely(vector<int>& nums) {
		unordered_map<int, int> m;
		vector<int> ans;

		for (auto &it : nums) m[it]++;

		for (auto &it : m) {
			if (it.second == 1
				&& m.find(it.first - 1) == m.end()
				&& m.find(it.first + 1) == m.end())
				ans.push_back(it.first);
		}

		return ans;

	}
};

int main() {
	char c;

	Solution sol;

	//vector<vector<int>> points = {{0, 1}, {2, 3}, {4, 5}, {4, 3}};
	//vector<vector<int>> points = { {0, 2}, {-2, -2}, {1, 4} };
	vector<vector<int>> points = { {0, 0}, {-5, 0}, {4, -2}, {3, -2}, {4, 2}, {1, -2}, {-2, -1}, {5, 0} };

	cout << sol.minimumLines(points);

	cin >> c;
}