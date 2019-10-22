#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int size = nums.size();
		vector<int> ans(size, 0);
		vector<int> right_accu(size, 0);
		vector<int> left_accu(size, 0);
		int total_product = 1;

		right_accu[0] = nums[0];
		for (int i = 1; i < size; ++i) {
			right_accu[i] = right_accu[i - 1] * nums[i];
		}

		left_accu[size-1] = nums[size-1];
		for (int i = size-2; i >= 0; --i) {
			left_accu[i] = left_accu[i + 1] * nums[i];
		}

		for (int i = 0; i < size; ++i) {
			if (i == 0) {
				ans[i] = left_accu[i + 1];
			}
			else if (i == size - 1) {
				ans[i] = right_accu[i - 1];
			}
			else {
				ans[i] = right_accu[i - 1] * left_accu[i + 1];
			}
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;
	vector<int> v = { 1, -1, 0, 2, 3, 4 };

	vector<int> ans = sol.productExceptSelf(v);

	for (auto it : ans) {
		cout << it << " ";
	}
	
	cin >> c;
}