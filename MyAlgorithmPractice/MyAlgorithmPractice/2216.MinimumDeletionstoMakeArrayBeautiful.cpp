//  easy -  처음부터 뒤로 하는게 답이네... 놀라움
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

class Solution {
public:
	int minDeletion(vector<int>& nums) {
		int l = nums.size();

		int ans = 0;
		for (int i = 0; i + 1 < l; i += 2 ) {
			if (nums[i] == nums[i + 1]) {
				i -= 1;
				ans++;
				continue;
			}
		}

		if ((l - ans) % 2 != 0) ans++;
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 1, 1, 2, 2, 3, 3 };
	cout << sol.minDeletion(nums);
	cin >> c;

}