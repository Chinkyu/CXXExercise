#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
	int _findUnsortedSubarray(vector<int>& nums) {
		int ans = 0, LM = 0, RM = 0;
		int l = nums.size();

		// find  L2, L1,  R1, R2
		int L1 = -1, L2 = -1, R1 = -1, R2 = -1;
		for (int i = 0; i < l - 1; ++i) {
			if (nums[i] > nums[i + 1]) {
				L2 = i;
				L1 = i + 1;
				break;
			}
		}

		if (L2 == -1) return 0;

		for (int j = l - 1; j > 0; --j) {
			if (nums[j - 1] > nums[j]) {
				R2 = j;
				R1 = j - 1;
				break;
			}
		}

		// Two item
		if (L2 == R1) {
			ans = 2;
			LM = L2; RM = R2;
		}

		// three items
		else if (L2 + 1 == R1) {
			ans = 3;
			LM = L2; RM = R2;
		}
		else {

			// More than four
			int min = nums[L2], max = nums[R2];
			for (int i = L2; i <= R2; ++i) {
				if (min > nums[i]) {
					min = nums[i];
				}
				if (max < nums[i]) {
					max = nums[i];
				}
			}

			LM = L2, RM = R2;
			ans = R2 - L2 + 1;
			if (min == nums[L2]) { 
				LM = L2 + 1;  --ans; 
			}
			if (max == nums[R2]) { 
				RM = R2 - 1;  --ans;

			}
		}

		// check left same number
		for (int i = LM - 1; 0 <= i; --i) {
			if (nums[i] == nums[LM]) {
				ans++;
			}
			else {
				break;
			}
		}
		// check right same number
		for (int i = RM + 1; i < l; ++i) {
			if (nums[RM] == nums[i]) {
				ans++;
			}
			else {
				break;
			}
		}
		return ans;
	}


	int findUnsortedSubarray(vector<int>& nums) {
		int l = nums.size();
		vector<int> snums = nums;

		sort(snums.begin(), snums.end());

		int st = -1, ed = -1;
		for (int i = 0; i < l; ++i) {
			if (nums[i] != snums[i]) {
				st = i;
				break;
			}
		}

		for (int i = l - 1; i >= 0; --i) {
			if (nums[i] != snums[i]) {
				ed = i;
				break;
			}
		}

		if (ed == -1 || st == -1) return 0;
		return ed - st + 1;
	}
};

int main() {
	char c;
	Solution sol;

	//vector<int> nums = { 2, 6, 4, 8, 10, 9, 15 };
	//vector<int> nums = { 1, 3, 2, 2, 2 };
	vector<int> nums = { 1, 2, 4, 5, 3 };

	int ans = sol.findUnsortedSubarray(nums);
	cout << "test : " << ans << endl;

	cin >> c;
}