// 답봤음 - 모든 케이스 ....  case is small 
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


long long singleDivisorTriplet(vector<int>& nums) {
	long long res = 0, cnt[101] = {};
	for (int n : nums)
		++cnt[n];
	for (int i = 1; i <= 100; ++i)
		for (int j = i; cnt[i] && j <= 100; ++j)
			for (int k = j + (i == k); cnt[j] && k <= 100; ++k) {
				int s = i + j + k;
				if (cnt[k] && (!(s % i) + !(s % j) + !(s % k) == 1)) {
					if (i == j)
						res += cnt[i] * (cnt[i] - 1) / 2 * cnt[k];
					else if (j == k)
						res += cnt[i] * cnt[j] * (cnt[j] - 1) / 2;
					else
						res += cnt[i] * cnt[j] * cnt[k];
				}
			}
	return res * 6;
}

// timeout 
class _Solution {
public:
	long long singleDivisorTriplet(vector<int>& nums) {
		int l = nums.size();

		long long ans = 0;
		for (int i = 0; i < l; ++i) {
			for (int j = i + 1; j < l; ++j) {
				//if (i == j) continue;
				for (int k = j + 1; k < l; ++k) {
					//if (k == i || k == j) continue;
					long long sum = nums[i] + nums[j] + nums[k];
					long long si = sum % nums[i];
					long long sj = sum % nums[j];
					long long sk = sum % nums[k];
					if (((si == 0) && (sj != 0) && (sk != 0)) ||
						((si != 0) && (sj != 0) && (sk == 0)) ||
						((si != 0) && (sj == 0) && (sk != 0)))				
					{
						//cout << i << " " << j << " " << k << endl;
						ans += 6;
					}

				}
			}
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;


	vector<int> nums = { 4, 6, 7, 3, 2 };
	cout << sol.singleDivisorTriplet(nums);

	cin >> c;

}