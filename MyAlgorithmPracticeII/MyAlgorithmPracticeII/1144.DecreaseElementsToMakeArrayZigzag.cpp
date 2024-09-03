// OK... 
// 줄이는것 만가능하다는구만... 

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	int movesToMakeZigzag(vector<int>& nums) {
		int l = nums.size();

		vector<int> nums2 = nums;

		// count +-+-+-
		int pcount = 0;
		for (int i = 0; i < nums.size(); i += 2) {
			int tmin = INT_MAX;
			if (0 <= i - 1) {
				tmin = min(tmin, nums[i - 1]);
			}
			if (i + 1 < l) {
				tmin = min(tmin, nums[i + 1]);
			}
			tmin--;

			if (tmin < nums[i]) {
				pcount += nums[i] - tmin;
			}
		}

		// count -+-+
		int ncount = 0;
		for (int i = 1; i < nums.size(); i += 2) {
			int tmin = INT_MAX;
			if (0 <= i - 1) {
				tmin = min(tmin, nums[i - 1]);
			}
			if (i + 1 < l) {
				tmin = min(tmin, nums[i + 1]);
			}
			tmin--;

			if (tmin < nums[i]) {
				ncount += nums[i] - tmin;
			}
		}

		return (pcount > ncount) ? ncount : pcount;

	}
};


class _Solution {
public:
	int movesToMakeZigzag(vector<int>& nums) {
		int l = nums.size();
		vector<int> v;

		for (int i = 1; i < l; ++i) {
			v.push_back(nums[i] - nums[i - 1]);
		}

		vector<int> v2 = v;

		// count +-+-+-
		int pcount = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i] <= 0) {
				pcount += v[i] * -1 + 1;
				if (i + 1 < v.size()) v[i + 1] -= v[i] * -1 + 1;
				v[i] = 1;
			}
			i++;
			if (i < v.size() && v[i] >= 0) {
				pcount += v[i] + 1;
				if (i + 1 < v.size()) v[i + 1] += v[i] + 1;
				v[i] = -1;
			}
		}

		// count -+-+
		v = v2;
		int ncount = 0;
		for (int i = 0; i < l - 1; ++i) {
			if (v[i] >= 0) {
				ncount += v[i] + 1;
				if (i + 1 < v.size()) v[i + 1] += v[i] + 1;
				v[i] = -1;
			}
			i++;
			if (i < v.size() && v[i] <= 0) {
				ncount += v[i] * -1 + 1;
				if (i + 1 < v.size()) v[i + 1] -= v[i] * -1 + 1;
				v[i] = 1;
			}
		}

		return (pcount > ncount) ? ncount : pcount;

	}
};

int main() {
	char c;
	Solution sol;
	vector<int> nums = { 9,6,1,6,2 };
	//vector<int> nums = { 10,4,4,10,10,6,2,3 };

	cout << sol.movesToMakeZigzag(nums);

	cin >> c;
}