// ¥‰ ∫√¿Ω.. 
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
#include <cmath>

using namespace std;

class Solution {
public:
	bool checkArray(vector<int>& nums, int k) {
		int n = nums.size();
		vector<long long> pre(n + 2, 0);
		for (int i = 1; i <= n; i++) {
			pre[i] += pre[i - 1];
			int val = nums[i - 1];
			val += pre[i];
			// as negative val(means element<0) can't update elements ahead
			if (i <= (n - k + 1) && val > 0) {
				pre[i] -= val;
				pre[i + k] += val;
			}
		}

		for (int i = 0; i < n; ++i) {
			nums[i] += pre[i + 1];
			if (nums[i] != 0) return false;
		}
		return true;
	}
};

// Timeout 
class _Solution {
public:
	bool checkArray(vector<int>& nums, int k) {
		int n = nums.size();

		for (int i = 0; i <= n - k; ++i) {
			if (nums[i] > 0) {
				int decrease = nums[i];
				for (int j = i; j < i + k; ++j) {
					nums[j] -= decrease;
				}
			}

			if (nums[i] < 0) return false;
		}

		for (int i = 0; i < n; ++i) {
			if (nums[i] != 0) return false;
		}
		return true;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 60,72,87,89,63,52,64,62,31,37,57,83,98,94,92,77,94,91,87,100,91,91,50,26 };
	cout << sol.checkArray(nums, 4);

	cin >> c;
}
