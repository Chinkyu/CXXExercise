//:: XXXX : LIS  유명한 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int l = nums.size();
		if (l <= 0) return 0;
		int ret = 0;
		vector<int> cnt(l, 0);

		for (int i = 0; i < l; ++i) {
			int maxV = 0;
			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i] && maxV < cnt[j]) maxV = cnt[j];
					
			}
			cnt[i] = maxV + 1;
			ret = max(ret, cnt[i]);
		}
		return ret;
	}

	int _lengthOfLIS(vector<int>& nums) {
		int l = nums.size();
		
		int max_acc = 1, acc = 1;
		for (int i = 1; i < l; ++i) {
			if (nums[i] > nums[i - 1]) {
				acc++;
				if (max_acc < acc) max_acc = acc;
			}
			else {
				acc = 1;
			}
		}
		return max_acc;
	}

};

int main() {
	char c;
	Solution sol;
	//vector<int> v = { 10,9,2,5,3,7,101,18 };
	vector<int> v = { 10, 15, 2, 3 };

	cout << sol.lengthOfLIS(v);

	cin >> c;
}