#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		int l = nums.size();
		vector<int> ans;

		if (l <= 0) return ans;

		vector<int> c(l+1, 0);

		for (auto it : nums) {
			c[it]++;
		}

		for (int i = 0; i <= l; ++i) {
			if (c[i] > 1) ans.push_back(i);
		}
		return ans;
	}
};


int main() {
	char c;
	vector<int>  v = { 2, 2 };// {4, 3, 2, 7, 8, 2, 3, 1};
	Solution sol;

	vector<int> ans = sol.findDuplicates(v);

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}