//  easy, a bit debugging effort needed 
// matter of factorial 
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

class Solution {
public:
	long long countSubarrays(vector<int>& nums) {
		vector<int> inc;
		int l = nums.size();

		if (l == 1) return 1;

		int inc_cnt = 1;
		for (int i = 1; i < l; ++i) {
			if (nums[i - 1] < nums[i]) {
				inc_cnt++;
			}
			else {
				if(inc_cnt >= 2) inc.push_back(inc_cnt);
				inc_cnt = 1;
			}
		}
		if (inc_cnt >= 2) inc.push_back(inc_cnt);

		sort(inc.begin(), inc.end());
		int incl = inc.size();
		long long ans = l;

		long long factorial = 0;
		int inc_idx = 0;
		for (int i = 1; i <= inc[incl - 1]; ++i) {
			factorial += i;
			while (inc_idx < incl && inc[inc_idx] == i) {
				ans += factorial - inc[inc_idx];
				inc_idx++;
			}
		}
		
		return ans;
	}
};


int main() {
	char c;

	Solution sol;
	vector<int> nums = { 1, 3, 5, 4, 4, 6 };

	cout << sol.countSubarrays(nums);

	cin >> c;
}