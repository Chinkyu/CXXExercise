// 답 봤음 바깥에서 안쪽으로 들어오면서 머지.. 
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
	int minimumOperations(vector<int>& nums) {
		vector<long long> copy_nums(nums.begin(), nums.end());
		int left = 0;
		int right = nums.size() - 1;
		int count = 0;
		while (left < right) {
			if (copy_nums[left] == copy_nums[right]) {
				left++;
				right--;
			}
			else if (copy_nums[left] > copy_nums[right]) {
				copy_nums[right - 1] += copy_nums[right];
				right--;
				count++;
			}
			else {
				copy_nums[left + 1] += copy_nums[left];
				left++;
				count++;
			}
		}

		return count;
	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> grid = { {6, 2, 1, 3},{4, 2, 1, 5},{9, 2, 8, 7},{4, 1, 2, 9} };

	cout << sol.maxSum(grid);

	cin >> c;
}