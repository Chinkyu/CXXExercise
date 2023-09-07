//  Easy... Check nature of XOR... if odd  xor other array.. 
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
	int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
		int ans = 0;
		
		if (nums1.size() % 2 == 1) {
			for (auto it : nums2) {
				ans ^= it;
			}
		}

		if (nums2.size() % 2 == 1) {
			for (auto it : nums1) {
				ans ^= it;
			}
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;
	vector<vector<int>> grid = { {6, 2, 1, 3},{4, 2, 1, 5},{9, 2, 8, 7},{4, 1, 2, 9} };

	cout << sol.maxSum(grid);

	cin >> c;
}