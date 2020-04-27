#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		int l = nums.size();
		if (l <= 0) return false;

		int max = nums[0];
		for (int i = 1; i < l; ++i) {
			if (max > nums[i]) {
				int prelarge = i - 1;
				while (nums[prelarge] <= nums[i]) prelarge--;
				
				// Check all previous 


				for (int j = 0; j < prelarge; ++j) {
					if (nums[j] < nums[i]) return true;
				}
			}
			else if (max < nums[i]) {
				max = nums[i];
			}
			//pre = nums[i];
		}
		return false;
	}
};

int main() {
	char c;
	Solution sol;
	vector<int> v = { 3,1,2,2 }; // {1, 0, 1, -4, -3}; //  { 3, 5, 0, 3, 4 }; // {1, 0, 1, -4, -3}; // { -1, 3, 2, 0 }; // { 1, 2, 3, 4 }; //  { 3, 1, 4, 2 };

	cout << sol.find132pattern(v);

	cin >> c;
}