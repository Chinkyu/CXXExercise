// ÈùÆ®ºÃÀ½ : amazing idea....  with ÀÌÇ×

/*
Let A(i) be the prefix sum of nums1 up to position i, and B(i) for nums2.

If the two arrays have the same sum range from i to j, it means:

A(j) - A(i - 1) = B(j) - B(i - 1)

Hence:

A(j) - B(j) = A(i - 1) - B(i - 1)

*/
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
	int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
		int l = nums1.size();

		if (l == 1 && nums1[0] == nums2[0]) return 1;

		vector<int> anum1(l + 1, 0), anum2(l + 1, 0), mnum3(l + 1, 0);

		anum1[0] = 0;
		anum2[0] = 0;
		mnum3[0] = 0;
		for (int i = 1; i < l + 1; ++i) {
			anum1[i] = nums1[i - 1] + anum1[i - 1];
			anum2[i] = nums2[i - 1] + anum2[i - 1];
			mnum3[i] = anum2[i] - anum1[i];
		}

		map<int, int> m;
		int maxd = 0;
		for (int i = 0; i <= l; ++i) {
			if (m.find(mnum3[i]) == m.end()) {
				m[mnum3[i]] = i;
			}
			else {
				maxd = max(maxd, i - m[mnum3[i]]);
			}
		}
		
		return maxd;
	}
};


class _Solution {
public:
	int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
		int l = nums1.size();

		vector<int> anum1(l + 1, 0), anum2(l + 1, 0);

		anum1[0] = 0;
		anum2[0] = 0;
		for (int i = 1; i < l + 1; ++i) {
			anum1[i] = nums1[i-1] + anum1[i - 1];
			anum2[i] = nums2[i-1] + anum2[i - 1];
		}

		int maxd = 0;
		for (int i = 0; i < l + 1; ++i) {
			for (int j = l; j > i + maxd; --j) {
//				if (j - i < maxd) continue;

				int d1 = anum1[j] - anum1[i];
				int d2 = anum2[j] - anum2[i];			
				if (d1 == d2 && maxd < j - i) {
					maxd = j - i;
				}
			}
		}
		
		return maxd;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> nums1 = { 0, 1, 1 }; // { 1, 1, 0, 1 };
	vector<int> nums2 = { 1, 0, 1 };// { 0, 1, 1, 0 };

	cout << sol.widestPairOfIndices(nums1, nums2);

	cin >> c;
}