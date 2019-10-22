#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int size = nums.size();
		unordered_map<int, int> um;
		vector<int> ans;

		for (auto it : nums) {
			if (um.find(it) != um.end()) {
				um[it]++;
			}
			else {
				um[it] = 1;
			}
		}

		for (auto it : um) {
			if (it.second > size / 3) ans.push_back(it.first);
		}
	
		return ans;
	}
};

int main() {
	Solution sol; 
	char c;
	vector<int> v = { 1, 1, 1, 3, 3, 2, 2, 2 };
	
	vector<int> ans = sol.majorityElement(v);
	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}