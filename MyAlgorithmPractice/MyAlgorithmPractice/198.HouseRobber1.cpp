// Need to solve with DP....... 
// DP로 해결책 생각해 내지 못하면.. 아주 아려운 문제임... !!
//. dp[j] = max of
//               dp[j - 1]    // M[j] 미포함
//               dp[j - 1] + M[j]  // M[j] 포함
//
//. dp[0] = M[0]
//.dp[1] = max(M[0], M[1])


#include <iostream>
#include <vector>
#include <algorithm>  // std::max

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int size = nums.size();
		vector<int> dp(size, 0);

		if (size == 0) return 0;
		else if (size == 1) return nums[0];
		else if (size == 2) return(max(nums[0], nums[1]));

		dp[0] = nums[0];
		dp[1] = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
		}

		return dp[size - 1];
	}
};

int main() {
	char c;
	Solution sol;
	vector<int> v = { 2,7,9,3,1 }; // { 1, 2, 3, 1 };
	cout << sol.rob(v);
	cin >> c;
}




// candicate stock 
/*
class Solution_NOT_Solution {
public:
int rob(vector<int>& nums) {
int sum_odd, sum_even;

sum_odd = 0;
sum_even = 0;

for (int i = 0; i < nums.size(); i++) {
if (i % 2 == 1) sum_odd += nums[i];
else sum_even += nums[i];
}

if (sum_odd > sum_even) return sum_odd;
else return sum_even;

}
};
*/
