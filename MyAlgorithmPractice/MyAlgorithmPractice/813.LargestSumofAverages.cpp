// 답 봤음.. 
// return  하는것이  시작, 몇개 분배 식으로 recursive 하게 돌아야... 
// memoization이 가능하다.. 그렇게 해야 timeout 이 안남. 
//  나중에 한번더 살펴 보면 좋을듯 하다.. 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution
{
public:
	map<pair<int, int>, double> m;
	double f(int i, vector<int> &nums, int k)
	{
		int n = nums.size();
		if (i != n && k == 0) return INT_MIN;
		if (i == n || k <= 0) return 0;
		if (m.find({ i,k }) != m.end()) return m[{i, k}];
		double sum = 0, count = 0, ans = 0;
		for (int x = i; x <= n - k; x++)
		{
			count++;
			sum += nums[x];
			ans = max(ans, sum / count + f(x + 1, nums, k - 1));
		}
		return m[{i, k}] = ans;
	}
	double largestSumOfAverages(vector<int>& nums, int k)
	{
		double mx = 0;
		for (int x = 1; x <= k; x++)
		{
			mx = max(mx, f(0, nums, x));
		}
		return mx;
	}
};


class _Solution {
public:
	double max_ans;

	double calculate_val(vector<int> &nums, vector<int> &narr, int k) {
		double result = 0;

		int index = 0;
		for (int i = 0; i < k; ++i) {
			double sub_avg = 0; 
			for (int j = 0; j < narr[i]; ++j) {
				sub_avg += nums[index++];
			}
			result += sub_avg/narr[i];
		}

		// print 
		for (auto it : narr) {
			cout << " " << it;
		}
		cout << endl;

		return result;
	}

	void recurse(vector<int> &nums, vector<int> &narr, int idx, int d, int k) {
		int l = nums.size();

		if (d == k) {
			narr[k - 1] = l - idx;
			double sub_ans = calculate_val(nums, narr, k);
			if (sub_ans > max_ans) max_ans = sub_ans;
			return;
		}


		for (int i = 1; i <= l - (k-d) - idx; ++i) {
			narr[d - 1] = i;
			recurse(nums, narr, idx + i, d + 1, k);
		}

	}

	double largestSumOfAverages(vector<int>& nums, int k) {
		int l = nums.size();
		vector<int> num_arr(k, 0);

		// if l is leset or equal with k  do seperately
		max_ans = 0;
		if (l <= k) {
			for (auto it : nums) max_ans += it;
			return max_ans;
		}

		// if l is large than k
		max_ans = 0;
		recurse(nums, num_arr, 0, 1, k);
		return max_ans;
	}
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

int main() {
	char c;

	Solution sol;

	//vector<int> nums = { 9, 1, 2, 3, 9 };
	//cout << sol.largestSumOfAverages(nums, 3);


	//vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	//cout << sol.largestSumOfAverages(nums, 4);


	vector<int> nums = {4663, 3020, 7789, 1627, 9668, 1356, 4207, 1133, 8765, 4649, 205, 6455, 8864, 3554, 3916, 5925, 3995, 4540, 3487, 5444, 8259, 8802, 6777, 7306, 989, 4958, 2921, 8155, 4922, 2469, 6923, 776, 9777, 1796, 708, 786, 3158, 7369, 8715, 2136, 2510, 3739, 6411, 7996, 6211, 8282, 4805, 236, 1489, 7698};
	cout << sol.largestSumOfAverages(nums, 27);

	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}