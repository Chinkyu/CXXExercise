//  직관적인 솔루션으로 보여 Discussion 을 참조함. 


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp1(n, 0);
		vector<int> dp2(n, 0);
		dp1[0] = nums[0];
		dp2[0] = nums[0];

		int res = dp1[0];
		for(int i = 1; i < n; ++i) {
			dp1[i] = max(nums[i], max(dp1[i-1]*nums[i], dp2[i-1]*nums[i]));
			dp2[i] = min(nums[i], min(dp1[i-1]*nums[i], dp2[i-1]*nums[i]));
			res = max(dp1[i], res);
		}
		return res;
	}
};

int main() {
	Solution sol;
	char c;
	vector<int> v = {2, 3, -2, 4, 7};

	cout << sol.maxProduct(v);

	cin >> c;
}
