// 답봤슴  - 다따져보는건데... 좀 신박하게 짰네.... 
// 다 따져보는데 Sliding window 로 하면 될것 같음. 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

//  다따져보는 sliding window 
class Solution {
public:
	int minSwaps(vector<int>& nums) {
		int ones = count(begin(nums), end(nums), 1), n = nums.size(), res = n;
		for (int i = 0, j = 0, cnt = 0; i < n; ++i) {
			while (j - i < ones)
				cnt += nums[j++ % n];
			res = min(res, ones - cnt);
			cnt -= nums[i];
		}
		return res;
	}
};

// wrong approach
class Solution {
public:
	int minSwaps(vector<int>& nums) {

		// identify zero group in circular way 
		vector<int> zero;
		int l = nums.size();

		int pre = (nums[0] == 0)? 1 : 0;
		int zCount = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != pre) {
				if (nums[i] == 0) {
					zCount = 1;
				}
				else {   // Become 1 from zero
					zero.push_back(zCount);
					zCount = 0;
				}
			}
			else {  // same with previous
				if (nums[i] == 0) {
					zCount++;
				}
			}
			pre = nums[i];
		}

		// the last zero 
		if (zCount > 0) {
			if (nums[0] == 0) {  // add into 0 idx
				if (zero.size() == 0) zero.push_back(zCount);
				else zero[0] += zCount;
			}
			else {
				zero.push_back(zCount);
			}
		}

		// Add up except max zero
		int sum = 0, tmax = 0;
		for (auto &it : zero) {
			sum += it;
			tmax = max(tmax, it);
		}
		sum -= tmax;

		return sum;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> nums = { 0, 0, 0 }; // { 0, 1, 1, 1, 0, 0, 1, 1, 0 }; // { 0, 1, 0, 1, 1, 0, 0 };

	cout << sol.minSwaps(nums);

	cin >> c;
}