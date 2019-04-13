#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i, j, temp;
		// find right most sink
		int size = nums.size();
		if (size <= 1) return;

		int sink = -1;

		for (i = size - 1; i > 0; --i) {
			if (nums[i - 1] < nums[i]) {
				sink = i - 1;
				break;
			}
		}

//		int sw = size - 1;
		if (sink >= 0) {
			for (i = sink+1; i < size; ++i) {
				if (nums[i] <= nums[sink]) {
//					sw = i-1;
					break;
				}
			}

			temp = nums[sink];
			nums[sink] = nums[i-1];
			nums[i-1] = temp;
		}

		for (i = sink + 1, j = size -1; i < sink + 1 + ((size - 1) - (sink + 1) + 1) / 2; ++i, --j) {
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
};

void dump(vector<int> & v) {

	for (auto i : v) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	Solution sol;
	char c;
//	vector<int> v = { 5, 6, 3, 7, 4, 2, 1 };
//	vector<int> v = { 1, 2, 3, 6, 8, 7, 9, 10};
//	vector<int> v = { 1, 3, 2};
//	vector<int> v = { 1, 3};
	vector<int> v = { 1, 5, 1 };

	sol.nextPermutation(v);

	dump(v);

	cin >> c;
}
