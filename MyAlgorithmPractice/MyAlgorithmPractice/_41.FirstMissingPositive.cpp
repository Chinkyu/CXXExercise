// 港疑擠.....?????太?太?太?太? 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		map<int, int> m;

		m[0] = INT_MAX;

		for (auto& it : nums) {
			if (it < 0) continue;

			auto itlow = m.lower_bound(it);

			if (itlow->first == it) {
				m[it + 1] = itlow->second;
				m.erase(itlow);
			}
			else if (it < itlow->second) {
				m[it] = it - 1;
				m[it + 1] = itlow->second;
			}
			else if (it == itlow->second) {
				m[it] = it - 1;
			}
		}

		return m.begin()->first;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> nums = { 3,4,-1,1 };

	cout << sol.firstMissingPositive(nums);

	cin >> c;
}