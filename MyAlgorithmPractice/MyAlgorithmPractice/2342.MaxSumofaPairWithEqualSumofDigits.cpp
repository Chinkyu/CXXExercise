// kinds of easy : set으로 해결 할려고 했는데 중복이 되어서..  vector 로
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

class Solution_v1 {
public:
	int maximumSum(vector<int>& nums) {
		unordered_map<int, set<int>> m;

		for (auto it : nums) {
			string s = to_string(it);

			// digits sum
			int sum = 0;
			for (int i = 0; i < s.size(); ++i) {
				sum += s[i] - '0';
			}

			m[sum].insert(it);
		}

		int ans = -1;
		for (auto it : m) {
			int tsum = 0;
			if (it.second.size() >= 2) {
				set<int>::iterator itr = --it.second.end();
				tsum = *--it.second.end() + *(--itr);
				ans = max(ans, tsum);
			}
		}

		return ans;
	}
};


class Solution {
public:
	int maximumSum(vector<int>& nums) {
		unordered_map<int, vector<int>> m;

		for (auto it : nums) {
			string s = to_string(it);

			// digits sum
			int sum = 0;
			for (int i = 0; i < s.size(); ++i) {
				sum += s[i] - '0';
			}

			m[sum].push_back(it);
		}

		int ans = -1;
		for (auto it : m) {
			int tsum = 0;
			if (it.second.size() >= 2) {
				int tsum = 0;
				sort(it.second.begin(), it.second.end());
				tsum = it.second[it.second.size() - 1] + it.second[it.second.size() - 2];

				ans = max(ans, tsum);
			}
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;


	//vector<int> nums = { 18,43,36,13,7 };
	vector<int> nums = { 4, 6, 10, 6 };

	cout << sol.maximumSum(nums);

	cin >> c;

}