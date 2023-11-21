//   easy  with set
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;

class Solution {
public:
	int countDistinct(vector<int>& nums, int k, int p) {
		int l = nums.size();
		set<vector<int>> s;

		// add all combination
		for (int i = 0; i < l; ++i) {
			for (int j = i; j < l; ++j) {
				vector<int> t;
				int count = 0;
				for (int k = i; k <= j; ++k) {
					t.push_back(nums[k]);
					if (nums[k] % p == 0) count++;
				}
				if (s.find(t) == s.end() && count <= k) s.insert(t);
			}
		}

		return s.size();
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 2, 3, 3, 2, 2 };

	cout << sol.countDistinct(nums, 2, 2);

	cin >> c;

}