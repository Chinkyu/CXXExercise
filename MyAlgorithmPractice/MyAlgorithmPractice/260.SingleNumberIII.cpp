#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> ans;
		unordered_map<int, bool> um;

		for (auto it : nums) {
			if (um.find(it) != um.end()) {
				um.erase(it);
			}
			else {
				um[it] = true;
			}
		}

		for (auto it : um) {
			ans.push_back(it.first);
		}
		return ans;
	}
};

int main() {
	Solution sol;
	char c;
	vector<int> v = { 1, 2, 1, 3, 2, 5 };

	vector<int> ans = sol.singleNumber(v);
	for (auto it : ans) {
		cout << it << " ";
	}
	cin >> c;
}