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
	vector<int> rearrangeArray(vector<int>& nums) {
		vector<int> minus, plus, ans;

		for (auto &it : nums) {
			if (it < 0) {
				minus.push_back(it);
			}
			else
			{
				plus.push_back(it);
			}
		}

		for (int i = 0; i < minus.size(); ++i) {
			ans.push_back(plus[i]);
			ans.push_back(minus[i]);
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 3,1,-2,-5,2,-4 };

	vector<int> ans = sol.rearrangeArray(nums);

	for (auto &it : ans) {
		cout << it << " ";
	}

	cin >> c;
}