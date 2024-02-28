// tricky in method :
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
	long long largestEvenSum(vector<int>& nums, int k) {
		int l = nums.size();
		sort(nums.begin(), nums.end(), greater<int>());

		long long sum = 0, isum = 0;
		for (int i = 0; i < k; ++i) isum += nums[i];

		sum = isum;
		if (isum % 2 == 1) {
			int insideSmallOdd = k - 1;
			while (nums[insideSmallOdd] % 2 == 0) insideSmallOdd--;

			//int outsideLargeEven = k;
			for (int i = k; i < l; ++i) {
				if (nums[i] % 2 == 0) {
					long long tsum = isum;
					tsum -= nums[insideSmallOdd];
					tsum += nums[i];
					sum = tsum;
					break;
				}
			}

			int insideSmallEven = k - 1;
			while (insideSmallEven >= 0 && nums[insideSmallEven] % 2 == 1)	insideSmallEven--;

			// Change with outsideLargeOdd
			for (int i = k; i < l && insideSmallEven >= 0; ++i) {
				if (nums[i] % 2 == 1) {
					long long tsum = isum;
					tsum -= nums[insideSmallEven];
					tsum += nums[i];
					if (sum % 2 == 0) { // sum is already even
						sum = max(sum, tsum);
					}
					else {
						sum = tsum;
					}
					break;
				}
			}
		}

		sum = (sum % 2 == 1) ? -1 : sum;
		return sum;
	}
};


int main() {
	char c;

	Solution sol;

	vector<int> nums = { 20,17,0,2,7 }; // { 1, 5, 5, 5, 4 };

	cout << sol.largestEvenSum(nums, 2);

	cin >> c;
}