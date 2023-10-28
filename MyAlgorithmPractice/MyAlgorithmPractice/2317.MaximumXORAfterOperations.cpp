//  잘 안되서.. 답봤고... 어이 없는데... 
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
	int maximumXOR(vector<int>& nums) {
		int ans = 0;;
		for (auto &i : nums) {
			ans |= i;
		}
		return ans;
	}

	int _maximumXOR(vector<int>& nums) {
		int l = nums.size();

		int all_xor = 0;
		for (auto it : nums) {
			all_xor ^= it;
		}

		int max_xor_with_all_xor = 0;
		for (auto it : nums) {
			max_xor_with_all_xor = max(max_xor_with_all_xor, (all_xor | it));// (all_xor ^ it) | it);
		}

		return max_xor_with_all_xor;
	}
};


int main() {
	char c;

	Solution sol;

	//vector<int> nums = { 3, 2, 4, 6 };
	vector<int> nums = { 772,45,1,297,549,549,301,805,297,261,36,772,37,548,300,545,773,549,268,32,41,521,44,516,256,45,549 };
	cout << sol.maximumXOR(nums);


	cin >> c;

}