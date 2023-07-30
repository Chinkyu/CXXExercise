// Just easy... min gap after sorting 
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
#include <cmath>

using namespace std;

class Solution {
public:
	int findValueOfPartition(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		int min_gap = INT_MAX;
		for (int i = 1; i < nums.size(); ++i) {
			min_gap = min(min_gap, nums[i] - nums[i - 1]);
		}
		return min_gap;
	}
};

int main() {
	char c;

	Solution sol;

	string s = "abab"; //"ooo"; //  "abcd";
	cout << sol.numberOfSpecialSubstrings(s);
	//cout << sol.longestString(3, 25, 48);

	cin >> c;
}
