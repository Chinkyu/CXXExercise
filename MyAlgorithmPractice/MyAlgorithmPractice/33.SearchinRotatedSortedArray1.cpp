#include <iostream>
#include <vector>
#include <algorithm>

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
		} else if (target < nums[m]) {
			return binary_search(nums, s, m, target);
		}
		else {
			return binary_search(nums, m + 1, e, target);
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

		// make sorted vector
		int pivot = size;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i - 1] > nums[i]) pivot = i;
			if (pivot != size) sv.push_back(nums[i]);
		}

		for (int i = 0; i < pivot; ++i) {
			sv.push_back(nums[i]);
		}

		//binary_search(sv.begin(), sv.end(), target);
		int result = binary_search(sv, 0, size - 1, target);
		return (result == -1) ? -1 : (result+pivot) % size;
	}
};

int main() {
	Solution sol;
	char c;
	vector<int> v = {5, 4}; // { 4, 5, 6, 7, 0, 1, 2 };

	cout << sol.search(v, 5);

	cin >> c;
}