#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		vector<int> idx(nums.size(), 0);
		int size = nums.size();

		if (size <= 0) return false;
		if (size == 1) return true;

		idx[0] = 1;

		int idxSum = 0;
		do {
			idxSum = 0;
			for (int i = 0; i < size; ++i) {
				if (idx[i] != 0) {
					if (nums[i] == 0) continue;
					for (int j = 1; j <= nums[i]; ++j) {
						if (i + j == size - 1) return true;
						idx[i + j] = 1;
					}
				}
				idx[i] = 0;
			}
		} while (idxSum != 0);
		return false;
	}
};

int main() {
	Solution sol;
	char c;
	//vector<int> v = { 2, 3, 1, 1, 4 };
	//vector<int> v = { 3, 2, 1, 0, 4};
	vector<int> v = { 1, 2};

	cout << sol.canJump(v);

	cin >> c;
}