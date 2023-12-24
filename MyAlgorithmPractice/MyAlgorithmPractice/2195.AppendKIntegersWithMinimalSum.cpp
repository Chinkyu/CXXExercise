// ¥‰∫√¿Ω    : 1 + 2 + 3 +4  ... = (n(n+1))/2
// from n1 to n2   gap = (n2(n2+1))/2 = (n1(n1 + 1))/2
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;


class Solution
{
public:
	long long minimalKSum(vector<int> &nums, int k)
	{
		long long sum = 0, num = 0;
		int ind = 0;
		sort(nums.begin(), nums.end());

		while (k > 0 && ind < nums.size())
		{

			long long n = nums[ind] - num - 1;
			if (n >= 0)
			{
				long long a;
				if (k >= n)  // if k>=n we will take whole n
				{
					k = k - n;
					a = nums[ind] - 1;
				}

				else if (k < n)  // if k<n , then we only take required value of k
				{
					a = num + k;
					k = 0;
				}

				if (a >= num)
				{
					// here we want sum of elements in between a and num
					sum += ((a * (a + 1)) / 2) - ((num * (num + 1)) / 2);
				}
			}

			num = nums[ind];
			ind++;
		}

		// this will be useful when we have traversed whole array
		long long a = k + nums.back();
		long long last = nums.back();

		sum += ((a * (a + 1)) / 2) - ((last * (last + 1)) / 2);

		return sum;
	}
};

// timeout 
class _Solution {
public:
	long long minimalKSum(vector<int>& nums, int k) {
		int l = nums.size();
		sort(nums.begin(), nums.end());

		int idx = 0;
		int num = 1;
		long long sum = 0;
		do {
			// duplication skip
			if (0 < idx && idx < l && nums[idx] == nums[idx - 1]) {
				idx++;
				continue;
			}

			if ((idx < l && num < nums[idx]) || (idx >= l)) {
				sum += num;
				cout << num << " ";
				k--;
			}
			else {
				idx++;
			}
			num++;
		} while (k > 0);

		return sum;
	}
};

int main() {
	char c;

	Solution sol;


	vector<int> nums = { 96,44,99,25,61,84,88,18,19,33,60,86,52,19,32,47,35,50,94,17,29,98,22,21,72,100,40,84 }; // { 1, 4, 25, 10, 25 };
	cout << sol.minimalKSum(nums, 35);

	cin >> c;

}