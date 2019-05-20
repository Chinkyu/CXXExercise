#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n <= 0) return 0;
		if (n <= 1) return 1;

		int idx = 1;
		int pre = nums[0];
		for (int i = 1; i < n;) {
			if (nums[i] == pre) {  // same with previous
				nums[idx++] = nums[i++];
				while (i < n && nums[i] == pre) i++;
			}
			else {                 // different from previous
				pre = nums[i];
				nums[idx++] = nums[i++];
			}
		}
		return idx;
	}
};

int main() {
	Solution sol;
	char c;
	//vector<int> nums = { 1, 1, 1, 2, 2, 3 };
	//vector<int> nums = { 0,0,0,1,1,1,1,1,2,3,3 };
	//vector<int> nums = { 0, 6};
	vector<int> nums = {};
	int n = sol.removeDuplicates(nums);

	cout << "num = " << n << endl;
	for (int i = 0; i < n; ++i) {
		cout << nums[i] << " ";
	}

	cin >> c;
}