// No easy.. - after optimization...  pass 
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

//   타임아웃.. !!!   안무식하게  나라시 하는 방법 찾아야함. 
class Solution_v1 {
public:
	long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
		vector<int> diff;

		diff.push_back(0);

		for (int i = 0; i < nums1.size(); ++i) {
			diff.push_back(abs(nums1[i] - nums2[i]));
		}
		int l = diff.size();
		int ol = l - 1;

		// flattening
		sort(diff.begin(), diff.end());

		int rnum = k1 + k2;
		
		long long ans = 0;
		if (rnum == 0) {
			for (int i = 0; i < l; ++i) {
				ans += pow(diff[i], 2);
			}
			return ans;
		}

		for (int i = l - 2; i >= 0; --i) {
			int sum = 0;
			for (int j = i; j < l; ++j) {
				sum += abs(diff[j] - diff[i]);
			}

			if(sum >= rnum) {
				int r = sum - rnum;
				int c = ol - i;

				int h = r / c;
				r = r % c;

				for (int k = l - 1; k > i; --k) {
					diff[k] = diff[i] + h;
					if (r-- > 0) diff[k]++;
				}
				break;
			}

			if (i == 0 && sum <= rnum) {
				return 0;
			}
		}

		for (int i = 1; i < l; ++i) {
			ans += pow(diff[i], 2);
		}
		return ans;

	}
};

class Solution {
public:
	long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
		vector<long long> diff;

		diff.push_back(0);

		for (int i = 0; i < nums1.size(); ++i) {
			diff.push_back(abs(nums1[i] - nums2[i]));
		}
		int l = diff.size();
		int ol = l - 1;

		// flattening
		sort(diff.begin(), diff.end());

		int rnum = k1 + k2;

		long long ans = 0;
		if (rnum == 0) {
			for (int i = 0; i < l; ++i) {
				ans += pow(diff[i], 2);
			}
			return ans;
		}

		long long bsum = diff[l-1];
		for (int i = l - 2; i >= 0; --i) {
			long long sum = 0;
			int bnum = l - i;

			bsum += diff[i];
			sum = bsum - (diff[i] * bnum);
			//for (int j = i; j < l; ++j) {
			//	sum += abs(diff[j] - diff[i]);
			//}

			if (sum >= rnum) {
				int r = sum - rnum;
				int c = ol - i;

				int h = r / c;
				r = r % c;

				for (int k = l - 1; k > i; --k) {
					diff[k] = diff[i] + h;
					if (r-- > 0) diff[k]++;
				}
				break;
			}

			if (i == 0 && sum <= rnum) {
				return 0;
			}
		}

		for (int i = 1; i < l; ++i) {
			ans += pow(diff[i], 2);
		}
		return ans;

	}
};

int main() {
	char c;

	Solution sol;

	//vector<int> nums1 = { 1, 2, 3, 4 };
	//vector<int> nums2 = { 2, 10, 20, 19 };

//	vector<int> nums1 = { 1, 4, 10, 12 };
//	vector<int> nums2 = { 5, 8, 6, 9 };
//	cout << sol.minSumSquareDiff(nums1, nums2, 10, 5);

//	vector<int> nums1 = { 10, 10, 10, 11, 5 };
//	vector<int> nums2 = { 1, 0, 6, 6, 1 };
//	cout << sol.minSumSquareDiff(nums1, nums2, 11, 27);

	vector<int> nums1 = { 18,4,8,19,13,8 };
	vector<int> nums2 = { 18,11,8,2,13,15 };
	cout << sol.minSumSquareDiff(nums1, nums2, 16, 8);

	cin >> c;

}