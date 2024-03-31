//  답봤음 : 그냥 count array로는 timeout남 
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
	constexpr int static n = 200000;
	int bt[n + 1] = {};
	int bitSum(int i)
	{
		int sum = 0;
		for (i = i + 1; i > 0; i -= i & (-i))
			sum += bt[i];
		return sum;
	}
	void bitUpdate(int i, int val)
	{
		for (i = i + 1; i <= n; i += i & (-i))
			bt[i] += val;
	}
	int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
		int res = 0, bal = 0;
		bitUpdate(n / 2, 1);
		for (int num : nums) {
			bal += num ? 1 : -1;
			bitUpdate(bal + n / 2, 1);
			res = (res + bitSum(bal + n / 2 - 1)) % 1000000007;
		}
		return res;
	}
};

class _Solution {
public:
	int subarraysWithMoreZerosThanOnes(vector<int>& nums) {
		int l = nums.size();
		vector<int> c(l+1, 0);

		int oneC = 0;
		for (int i = 0; i < l; ++i) {
			if (nums[i] == 1) {
				 ++oneC;
			}
			c[i] = oneC;
		}

		// all subarray
		int ans = 0;
		for (int i = 0; i < l; ++i) {
			for (int j = i; j < l; ++j) {
				int size = j - i + 1;
				int stC = (i - 1< 0) ? 0: c[i - 1];
				int oneNumber = c[j] - stC/*c[i-1]*/;
				if (oneNumber > size - oneNumber) {
					ans++;
					ans %= 1000000007;
				}
			}
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> nums = //{ 0,1,1,0,1 };
};

	cout << sol.subarraysWithMoreZerosThanOnes(nums);

	cin >> c;
}