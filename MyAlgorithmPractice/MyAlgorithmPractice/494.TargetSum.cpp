#include <iostream>
#include <set>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
	//int sum;
	int target;
	int cnt;
	void iterate(vector<int> & nums, int idx, int sum) {
		int l = nums.size();

		if (idx >= l) {
			if (sum == target) {
				cnt++;
				cout << "hit" << endl;
			}
			return;
		}

		// +
		//sum += nums[idx];
		iterate(nums, idx + 1, sum + nums[idx]);
		//sum -= nums[idx];

		// -
		//sum -= nums[idx];
		iterate(nums, idx + 1, sum - nums[idx]);
		//sum += nums[idx];
	}

	int findTargetSumWays(vector<int>& nums, int S) {
		//sum = 0;
		cnt = 0;
		target = S;

		iterate(nums, 0, 0);

		return cnt;
	}
};



int main() {
	char c;
	vector<int> v = { 1, 1, 1, 1, 1};
	Solution sol;

	cout << sol.findTargetSumWays(v, 3);

	cin >> c;
}