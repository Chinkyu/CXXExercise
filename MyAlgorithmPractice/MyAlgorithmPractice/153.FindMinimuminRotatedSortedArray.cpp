//  간단한데.. 이진써치... 예외 케이스가 많아서...  깔끔하지 않음.. 
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
	int findMin(vector<int>& nums) {

		if (nums.size() <= 5) {
			int ans = nums[0];
			for (int i = 1; i < nums.size(); ++i) {
				if (nums[i] < ans) ans = nums[i];
			}
			return ans;
		}

		int sti = 0, edi = nums.size() - 1;
		int mdi = (sti + edi) / 2;
		while (sti < edi && sti != mdi) {
			if (nums[sti] < nums[mdi]) {
				sti = mdi;
				mdi = (edi + sti) / 2;
			}
			else {
				edi = mdi;
				mdi = (edi + sti) / 2;
			}
		}

		if (edi == nums.size() - 1 && nums[edi-1] < nums[edi]) return nums[0];
		if (nums[sti] < nums[sti + 1]) {
			return nums[sti];
		}
		else {
			return nums[sti+1];
		}
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 2, 3, 1}; //  { 11, 13, 15, 17 }; //  3, 4, 5, 1, 2 };

	cout << sol.findMin(nums);

	cin >> c;
}