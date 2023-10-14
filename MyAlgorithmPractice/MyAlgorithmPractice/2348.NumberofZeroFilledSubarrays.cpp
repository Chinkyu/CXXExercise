//  not hard
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

using namespace std;

class Solution {
public:
	long long zeroFilledSubarray(vector<int>& nums) {
		unordered_map<int, int> m;
		int l = nums.size();

		int znum = 0;
		int zmax = 0;
		bool isZStart = false;
		for (int i = 0; i < l; ++i) {
			if (nums[i] == 0) {
				isZStart = true;
				znum++;
			}
			else {
				if (isZStart == true) {
					m[znum]++;
					zmax = max(zmax, znum);
					isZStart = false;
					znum = 0;
				}
			}
		}

		if (znum > 0) {
			m[znum]++;
			zmax = max(zmax, znum);
		}

		long long ans = 0;

		// print 
//		for (auto it : m) {
//			cout << it.first << " " << it.second << endl;
//		}

		long long fact = 0;
		for (int i = 1; i <= zmax; ++i) {
			fact += i;

			if (m[i] > 0) ans += fact * m[i];
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 0,0,0,2,0,0 };
	cout << sol.zeroFilledSubarray(nums);

	cin >> c;

}