//  ¥‰îf¿Ω..    stack ??
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

class _Solution {
public:
	int totalSteps(vector<int>& nums) {
		int max_step = 0;

		int pNum = nums[0], pIdx = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] >= pNum) {
				max_step = max(max_step, i - pIdx - 1);
				pIdx = i;
				pNum = nums[i];
			}
		}
		return max_step;
	}
};

class __Solution {
public:
	int totalSteps(vector<int>& nums) {
		int max_step = 0;
		vector<int> m;

		int pIdx = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i - 1] > nums[i]) {
				max_step = max(max_step, i - pIdx - 2);
				pIdx = i - 1;
				m.push_back(nums[pIdx]);
			}
		}

		for (int i = 1; i < m.size(); ++i) {
			if (m[i - 1] > m[i]) max_step++;
		}
		return max_step;
	}
};

class Solution {
public:
	int totalSteps(vector<int>& nums) {
		stack<pair<int, int>>st;
		int n = nums.size();
		int ans = 0;
		st.push({ nums[n - 1],0 });
		for (int i = n - 2; i >= 0; i--) {
			int cnt = 0;
			while (!st.empty() && st.top().first < nums[i]) {

				cnt = max(cnt + 1, st.top().second);
				st.pop();
			}
			ans = max(cnt, ans);
			st.push({ nums[i],cnt });
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 5,3,4,4,7,3,6,11,8,5,11 };

	cout << sol.totalSteps(nums);

	cin >> c;

}