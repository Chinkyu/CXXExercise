//  ???
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
	int longestNiceSubarray(vector<int>& nums) {
		int j = 0;
		int i = 1;
		int lul = nums[0];
		int ans = 1;
		int cnt = 0;
		while (i < nums.size()) {
			while (j <= i && (nums[i] & lul)) {
				lul ^= nums[j++];
				ans = max(ans, i - j + 1);
			}
			lul |= nums[i];
			ans = max(ans, i - j + 1);
			i++;
		}
		return ans;
	}
};


class _Solution {
public:
	int longestNiceSubarray(vector<int>& nums) {
		int l = nums.size();

		if (l == 1) return 1;
		int oR = 0, anD = 0;

		oR = nums[0] | nums[1];
		anD = nums[0] & nums[1];
		if (l == 2) {
			if (anD == 0) return 2;
			return 1;
		}
		int tmax = 1, clen = 1;
		for (int i = 2; i < l; ++i) {
 			if ((oR & nums[i]) == 0) {
				clen++;
				tmax = max(tmax, clen);
				oR |= nums[i];
			}
			else {
				clen = 1;
				oR = nums[i];
			}
		}

		return tmax;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> nums = { 84139415,693324769,614626365,497710833,615598711,264,65552,50331652,1,1048576,16384,544,270532608,151813349,221976871,678178917,845710321,751376227,331656525,739558112,267703680 };
	//{ 3, 1, 5, 11, 13 }; // {1, 3, 8, 48, 10};

	cout << sol.longestNiceSubarray(nums);

	cin >> c;
}