// 맵으로 쉽게 풀림.. 
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
#include <cmath>

using namespace std;

class Solution {
public:
	vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
		unordered_map<int, int> m;

		for (auto it : nums) m[it]++;

		for (int i = 0; i < moveFrom.size(); ++i) {
			int f = m[moveFrom[i]];
			// remove
			m.erase(moveFrom[i]);
			m[moveTo[i]] += f;
		}

		vector<int> ans;
		for (auto it : m) {
			//for (int i = 0; i < it.second; ++i) {
				ans.push_back(it.first);
			//}
		}
		sort(ans.begin(), ans.end());

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 1, 6, 7, 8 };
	vector<int> moveFrom = { 1, 7, 2 };
	vector<int> moveTo = { 2, 9, 5 };

	vector<int> ans = sol.relocateMarbles(nums, moveFrom, moveTo);

	for (auto it : ans) cout << it << " ";

	cin >> c;
}
