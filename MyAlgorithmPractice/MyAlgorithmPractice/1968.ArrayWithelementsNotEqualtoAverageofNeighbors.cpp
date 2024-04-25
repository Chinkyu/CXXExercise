// 답봤음..:  이게 왜 답이 되는지 모르겠음 ....  
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums)
	{
		int n = nums.size();
		for (int i = 1; i < n - 1; i++)
		{
			if ((nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) || (nums[i - 1] > nums[i] && nums[i] > nums[i + 1]))
				swap(nums[i], nums[i + 1]);
		}
		return nums;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> nums1 = { 0, 1, 1 }; // { 1, 1, 0, 1 };
	vector<int> nums2 = { 1, 0, 1 };// { 0, 1, 1, 0 };

	cout << sol.widestPairOfIndices(nums1, nums2);

	cin >> c;
}