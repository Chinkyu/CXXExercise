#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

	vector<vector<int>> threeSum(vector<int>& nums) {
		int len = nums.size();
		unordered_map<int, int> m;   // key, index map
		vector<vector<int>> ans;

		for (int i = 0; i < len; ++i) {
			m[nums[i]] = i;
		}


		for (int i = 0; i < len; ++i) {
			for (int j = i + 1; j < len; ++j) {

				// find -(nums[i] + nums[j])
				int toFind = -(nums[i] + nums[j]);
				if (m.find(toFind) != m.end()) {  // exist
					// check index i or j 
					if (m[toFind] != i && m[toFind] != j) {
						// We found ig 
						ans.push_back({ nums[i], nums[j], -toFind });
					}
				}
			}
		}
		return ans;
	}
};

int main() {
	char c;

	Solution s;

	//vector<int> nums = { -1,0,1,2,-1,-4 };
	vector<int> nums = { -1,0,1,2,-1,-4 };

	vector<vector<int>> ans = s.threeSum(nums);

	for (auto it : ans) {
		for (auto jt : it) {
			cout << jt << ",";
		}
		cout << endl;
	}

	cin >> c;
}