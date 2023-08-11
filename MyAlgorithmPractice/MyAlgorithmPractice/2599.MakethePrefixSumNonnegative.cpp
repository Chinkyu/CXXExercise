// ¥‰∫√¿Ω  
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

// wrong answer
class _Solution {
public:
	int makePrefSumNonNegative(vector<int>& nums) {
		int l = nums.size();
		vector<int> s(l, 0);

		s[0] = nums[0];
		for (int i = 1; i < l; ++i) {
			s[i] = s[i - 1];
			s[i] += nums[i];
		}

		int min = 0;
		int min_cnt = 0;
		for (int i = 0; i < l; ++i) {
			if (s[i] < 0) {
				for (int j = i; j < l; ++j) {
					s[j] += nums[i] * -1;
				}
				min_cnt++;
			}
		}
		return min_cnt;
	}
};

class __Solution {
public:
	int makePrefSumNonNegative(vector<int>& nums) {
		int l = nums.size();
		vector<int> s(l, 0);

		vector<vector<int>> n;

		for (int i = 0; i < l; ++i) {
			if (nums[i] < 0) n.push_back({ i, nums[i] });
		}

		sort(n.begin(), n.end(), [](vector<int> &l, vector<int> &r) { return l[1] < r[1]; });

		int nl = n.size();
		int min_cnt = 0;
		for (int i = 0; i < nl; ++i) {
			if (n[i][1] == 0) continue;
			min_cnt++;
			for (int j = i; j < nl; ++j) {
				if (n[j][0] > n[i][0]) n[j][1] = 0;
			}
		}

		return min_cnt;
	}
};

class Solution {
public:
	int makePrefSumNonNegative(vector<int>& nums, long sum = 0) {
		priority_queue <int, vector<int>, greater<int>> pq;
		for (int i : nums) {
			pq.push(i);
			if ((sum += i) < 0)
				sum -= pq.top(), pq.pop();
		}
		return nums.size() - pq.size();
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> nums = { 6,-6,-3,3,1,5,-4,-3,-2,-3,4,-1,4,4,-2,6,0 };

	cout << sol.makePrefSumNonNegative(nums);

	cin >> c;
}