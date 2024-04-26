// easy with multi set 
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
	int binarySearchableNumbers(vector<int>& nums) {
		multiset<int> sl, sr;

		for (int i = 0; i < nums.size(); ++i) sr.insert(nums[i]);

		int ans = 0;
		for (int i = 0; i < nums.size(); ++i) {
			int c = nums[i];
			sr.erase(c);
			bool l = true, r = true;
			if (sl.size() > 0 && c < *sl.rbegin()) l = false;
			if (sr.size() > 0 && *sr.begin() < c) r = false;

			if (l == true && r == true) ans++;

			sl.insert(c);
		}

		return ans;

	}
};

int main() {
	char c;
	Solution sol;

	vector<int> nums = { -1, 5, 2 };

	cout << sol.binarySearchableNumbers(nums);

	cin >> c;
}