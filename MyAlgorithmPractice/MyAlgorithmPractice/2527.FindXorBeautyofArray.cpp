//	이걸 어떻게 처음에 아냐.. 
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

//  하여간 연산에서 뭔가가 있을 줄았았음//
// 이걸 어떻게 야냐... 
class Solution {
public:
	int xorBeauty(vector<int>& nums) {
		int a = 0, b = 0;
		for (auto &i : nums) {
			a |= i, b ^= i;
		}
		return (a&b);
	}
};

//  timeout solution... -> how?? 
class _Solution {
public:

	int traverse(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					ans ^= ((nums[i] | nums[j]) & nums[k]);
				}

			}
		}
		return ans;
	}



	int xorBeauty(vector<int>& nums) {
		return traverse(nums);
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> nums = { 15,45,20,2,34,35,5,44,32,30 };
	cout << sol.xorBeauty(nums);

	cin >> c;
}