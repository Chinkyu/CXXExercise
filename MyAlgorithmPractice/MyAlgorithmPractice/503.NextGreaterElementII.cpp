#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int l = nums.size();
		vector<int> ans(l, 0);
		map<int, int> m;

		if (l <= 0) return ans;

		// make m
		m[0] = nums[0];
		for (int i = 1; i < l; ++i) {
			m[i] = nums[i];
			for (map<int, int>::iterator it = m.begin(); it != m.end();) {
				if (it->second < nums[i]) {
					ans[it->first] = nums[i];
					m.erase(it++);
					continue;
				}
				++it;
			}
		}

		for (int i = 0; i < l || m.size() > 0; ++i) {
			//for (auto it : m) {
			for (map<int, int>::iterator it = m.begin(); it != m.end();) {
				if (it->first == i) {
					ans[it->first] = -1;
					m.erase(it++);
					continue;
				}
				if (it->second < nums[i]) {
					ans[it->first] = nums[i];
					m.erase(it++);
					continue;
				}
				it++;
			}
		}
		return ans;
	}
};


int main() {
	char c;
	vector<int> v = { 1, 2, 1 };
	Solution sol;

	vector<int> ans = sol.nextGreaterElements(v);
	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}
