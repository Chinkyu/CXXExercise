//  ¥‰∫√¿Ω : kadane's ??? 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	long long maximumAlternatingSubarraySum(vector<int>& nums) {
		long long lastMinus = INT_MIN;
		long long lastPlus = INT_MIN;
		long long res = INT_MIN;
		for (long long num : nums) {
			auto currPlus = max(lastMinus + num, num);
			lastMinus = lastPlus - num;
			lastPlus = currPlus;
			res = max(res, max(lastMinus, lastPlus));
		}
		return res;
	}
};

// timeout 
class _Solution {
public:
	long long maximumAlternatingSubarraySum(vector<int>& nums) {
		int l = nums.size();
		vector<int> vo, ve;

		if (l == 1) return nums[0];

		for (int i = 0; i < l; ++i) vo.push_back((i % 2 == 0) ? nums[i] : nums[i] * -1);
		for (int i = 1; i < l; ++i) ve.push_back((i % 2 == 1) ? nums[i] : nums[i] * -1);

		long long ans = 0; 
		long long sum = 0;
		for (int i = 0; i < l; i += 2) {
			for (int j = i; j < l; j++) {
				sum += vo[j];
				ans = max(ans, sum);
			}

			if (i + 2 >= l) break;
			sum -= vo[i];
			sum -= vo[i + 1];
			i += 2;
			ans = max(ans, sum);

			for (int j = l - 1; j >= i; j--) {
				sum -= vo[j];
				ans = max(ans, sum);
			}

			if (i + 2 >= l) break;
			//sum -= vo[i];
			//sum -= vo[i + 1];
		}

		int le = l - 1;
		sum = 0;
		for (int i = 0; i < le; i += 2) {
			for (int j = i; j < le; j++) {
				sum += ve[j];
				ans = max(ans, sum);
			}

			if (i + 2 >= le) break;
			sum -= ve[i];
			sum -= ve[i + 1];
			i += 2;
			ans = max(ans, sum);

			for (int j = le - 1; j >= i; j--) {
				sum -= ve[j];
				ans = max(ans, sum);
			}

			if (i + 2 >= l) break;
			//sum -= ve[i];
			//sum -= ve[i + 1];
		}

		return ans;
	}
};


int main() {
	char c;
	Solution sol;

	vector<int> nums = { -2,2,4,-1};

	cout << sol.maximumAlternatingSubarraySum(nums);

	cin >> c;
}