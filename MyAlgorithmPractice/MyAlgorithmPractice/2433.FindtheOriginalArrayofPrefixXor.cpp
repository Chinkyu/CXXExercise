//  easy
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
	vector<int> findArray(vector<int>& pref) {
		vector<int> ans;
		int l = pref.size();

		int acc_xor = pref[0];
		ans.push_back(pref[0]);
		for (int i = 1; i < l; ++i) {
			int next = acc_xor ^ pref[i];
			ans.push_back(next);
			acc_xor ^= next;
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> nums = { 5,2,0,3,1 };

	vector<int> ans = sol.findArray(nums);

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}