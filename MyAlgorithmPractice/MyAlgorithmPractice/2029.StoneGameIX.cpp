//  ¥‰∫√¿Ω : 
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
	bool stoneGameIX(vector<int>& stones) {
		int cnt[3] = {};
		for (int a : stones)
			cnt[a % 3]++;
		if (min(cnt[1], cnt[2]) == 0)
			return max(cnt[1], cnt[2]) > 2 && cnt[0] % 2 > 0;
		return abs(cnt[1] - cnt[2]) > 2 || cnt[0] % 2 == 0;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> nums = //{ 0,1,1,0,1 };
};

cout << sol.subarraysWithMoreZerosThanOnes(nums);

cin >> c;
}