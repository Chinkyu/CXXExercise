
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Experience Timeout : XXXX : 
class Solution {
public:
	int smallestDistancePair(vector<int>& nums, int k) {
		int len = nums.size();
		vector<int> du_result, result;

		for (int i = 0; i < len; i++) {
			for (int j = i+1; j < len; j++) {
				du_result.push_back(abs(nums[i] - nums[j]));
			}
		}

		// 
		sort(du_result.begin(), du_result.end());

		// remove duplicate
//		int cur = -1;
//		for (int i = 0; i < du_result.size(); i++) {
//			if (cur != du_result[i]) {
//				cur = du_result[i];
//				result.push_back(cur);
//			}
//		}

		return du_result[k-1];
	}
};

int main() {
	char c;
	vector<int> n = { 1,3,1 };
	Solution sol;

	cout << sol.smallestDistancePair(n, 1);
	cin >> c;

}
