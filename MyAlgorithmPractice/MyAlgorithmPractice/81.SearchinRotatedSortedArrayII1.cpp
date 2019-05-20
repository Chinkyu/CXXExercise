#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

	int binary_search(vector<int>& nums, int s, int e, int target) {

		if (s == e) {
			return (nums[s] == target) ? s : -1;
		}


		int m = (s + e) / 2;
		if (target == nums[m]) {
			return m;
		}

		bool isLeft = false;
		if (nums[s] == nums[m]) {
			// need to find pivot is left or right 
			// 왼쪽 모두 찾아보기.... 
			for (int i = s + 1; i <= m; i++) {      // :XXXX: Can be peformance degradation cuase .. !!! 
				if (nums[i] != nums[s]) {
					isLeft = true;
					break;
				}
			}
		}

		if ((nums[s] < nums[m]) ||
			(nums[s] == nums[m] && isLeft == false)) {  // pivot is after m
			if (nums[s] <= target && target <= nums[m]) {  // left search
				return binary_search(nums, s, m, target);
			}
			else {                   // right search
				return binary_search(nums, m + 1, e, target);
			}
		}
		else {                    // pivot is before m
			if (nums[m] <= target && target <= nums[e]) {  // right search
				return binary_search(nums, m + 1, e, target);
			}
			else {                   // left search
				return binary_search(nums, s, m, target);
			}
		}

		return -1;
	}


	bool search(vector<int>& nums, int target) {
		vector<int> sv;

		//		if (nums == null) return -1;
		int size = nums.size();

		if (size <= 0) return false;
		if (size == 1) {
			if (nums[0] == target) {
				return true;
			}
			else {
				return false;
			}
		}

		int result = binary_search(nums, 0, size - 1, target);
		return  (result == -1) ? false : true;
	}
};

int main() {
	Solution sol;
	char c;
	
	//vector<int> v = { 0, 0, 1, 2, 2, 5, 6 };
	//vector<int> v = {2, 5, 6, 0, 0, 1, 2 };
	vector<int> v = { 1, 3, 1, 1, 1};

	cout << sol.search(v, 2);

	cin >> c;
}