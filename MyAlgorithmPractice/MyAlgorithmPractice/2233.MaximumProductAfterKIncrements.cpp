//  easy : trick for some condition... 
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;


// timeout
class Solution {
public:
	int maximumProduct(vector<int>& nums, int k) {
		int l = nums.size();
		sort(nums.begin(), nums.end());

		for (int i = 1; i < l; ++i) {
			if (nums[i] == nums[i - 1]) continue;
			if ((nums[i] - nums[i - 1]) * i <= k) {
				for (int j = 0; j <= i - 1; ++j) {
					k -= nums[i] - nums[j];
					nums[j] = nums[i];
				}
			}
			else {
				int div = k / i;
				int rem = k % i;
				if (div > 0) {
					for (int j = 0; j <= i - 1; ++j) {
						k -= div;
						nums[j] += div;
					}
				}
				// may add from last 
				for (int j = 0; j < rem; ++j) {
					nums[j]++;
					k--;
				}
			}
		}

		if (k > 0) {
			int div = k / l;
			int rem = k % l;
			if (div > 0) {
				for (int j = 0; j <= l - 1; ++j) {
					k -= div;
					nums[j] += div;
				}
			}
			// may add from last 
			for (int j = 0; j < rem; ++j) {
				nums[j]++;
			}
		}

		long long ans = nums[0];
		for (int i = 1; i < l; ++i) {
			ans *= nums[i];
			ans %= 1000000007;
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = {6, 3, 3, 2 };
	cout << sol.maximumProduct(nums, 2);


	cin >> c;

}