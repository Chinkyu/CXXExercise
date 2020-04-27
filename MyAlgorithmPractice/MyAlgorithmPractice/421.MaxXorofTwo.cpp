#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		int l = nums.size();

		if (l <= 0) return 0;

		int max = 0;
		for (int i = 0; i < l-1; ++i) {
			for (int j = i + 1; j < l; ++j) {
				if (max < (nums[i] ^ nums[j])) max = (nums[i] ^ nums[j]);
			}
		}
		return max;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> v = { 3, 10, 5, 25, 2, 8 };
	cout << sol.findMaximumXOR(v);

	cin >> c;
}
