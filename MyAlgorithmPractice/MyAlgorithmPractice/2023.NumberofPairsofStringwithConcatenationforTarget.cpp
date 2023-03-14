//  이상한테..  timeout 날꺼라 생각했는데.. 안나고 그냥 pass 되네.. . 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

using namespace std;

class Solution {
public:
	int numOfPairs(vector<string>& nums, string target) {
		int l = nums.size();
		int ans = 0;

		for (int i = 0; i <= l - 1; ++i) {
			for (int j = 0; j <= l - 1; ++j) {
				if (i == j) continue;
				if (target.compare(nums[i] + nums[j]) == 0) ans++;
			}
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<string> nums = { "777", "7", "77", "77" };

	//	string t = "ete";
	//	if (true == sol.isPalandrom(t)) cout << "true" << endl;

	cout << sol.numOfPairs(nums, "7777");

	//cout << sol.minimumSwap(s1, s2);

	cin >> c;
}