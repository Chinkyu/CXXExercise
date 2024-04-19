// easy : string sort
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
	string kthLargestNumber(vector<string>& nums, int k) {
		int l = nums.size();
		vector<string> v;

		for (auto &it : nums) v.push_back(it);

		sort(v.begin(), v.end(), [](string &l, string &r) {
					if (l.size() == r.size()){
						return l < r;
					}
					else if(l.size() < r.size()) {
						return true;
					}
					else {
						return false;
					}
			});

		return v[l - k];
	}
};

int main() {
	char c;
	Solution sol;

	vector<string> nums = { "2", "21", "12", "1" };

	cout << sol.kthLargestNumber(nums, 3);

	cin >> c;
}