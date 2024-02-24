// 답봤음 : 참 간단하게 풀리는데....... 
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


// timeout 
class _Solution {
public:
	long long subArrayRanges(vector<int>& nums) {
		int l = nums.size();
		long long ans = 0;

		for (int i = 2; i <= l; ++i) {
			map<int, int> m;
			for (int j = 0; j < i; ++j) m[nums[j]]++;

			ans += m.rbegin()->first - m.begin()->first;

			for (int j = 1; j <= l - i; ++j) {
				m[nums[j - 1]]--;
				m[nums[j + i - 1]]++;
				if (m[nums[j - 1]] == 0) m.erase(nums[j - 1]);
				ans += m.rbegin()->first - m.begin()->first;
			}
		}

		return ans;
	}
};

// 이것도  timeout : 지그제그도 타임아웃
class __Solution {
public:
	long long subArrayRanges(vector<int>& nums) {
		int l = nums.size();
		long long ans = 0;

		map<int, int> m;

		if (l < 2) return 0;

		m[nums[0]]++;

		for (int i = 2; i <= l; ++i) {

			m[nums[i - 1]]++;
			ans += m.rbegin()->first - m.begin()->first;

			for (int j = 1; j <= l - i; ++j) {
				m[nums[j - 1]]--;
				m[nums[j + i - 1]]++;
				if (m[nums[j - 1]] == 0) m.erase(nums[j - 1]);
				ans += m.rbegin()->first - m.begin()->first;
			}

			// next backword
			++i;
			if (i > l) break;
			m[nums[l - i]]++;
			ans += m.rbegin()->first - m.begin()->first;

			for (int j = l - i - 1; j >= 0; --j) {
				m[nums[j]]++;
				m[nums[j + i]]--;
				if (m[nums[j + i]] == 0) m.erase(nums[j + i]);
				ans += m.rbegin()->first - m.begin()->first;
			}
		}

		return ans;
	}
};

class Solution {
public:
	long long subArrayRanges(vector<int>& nums) {
		long long res = 0;
		for (int i = 0; i < nums.size(); i++) {
			int ma = nums[i], mi = nums[i];
			for (int j = i; j < nums.size(); j++) {
				ma = max(ma, nums[j]);
				mi = min(mi, nums[j]);
				res += ma - mi;
			}
		}
		return res;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> nums = { 4, -2, -3, 4, 1 }; // { 1, 2, 3 }; //{ 1, 2, 2, 3, 4, 3 }; //

	cout << sol.subArrayRanges(nums);

	cin >> c;
}