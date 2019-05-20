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

		if (nums[s] <= nums[m]) {  // pivot is after m
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


	int search(vector<int>& nums, int target) {
		vector<int> sv;

		//		if (nums == null) return -1;
		int size = nums.size();

		if (size <= 0) return -1;
		if (size == 1) {
			if (nums[0] == target) {
				return 0;
			}
			else {
				return -1;
			}
		}

		int result = binary_search(nums, 0, size - 1, target);
		return result; //  (result == -1) ? -1 : (result + pivot) % size;
	}
};

int main() {
	Solution sol;
	char c;
	//vector<int> v = { 5, 4 }; // { 4, 5, 6, 7, 0, 1, 2 };
	//vector<int> v = { 4, 5, 6, 7, 0, 1, 2 };
	vector<int> v = { 3, 1 };

	cout << sol.search(v, 1);

	cin >> c;
}