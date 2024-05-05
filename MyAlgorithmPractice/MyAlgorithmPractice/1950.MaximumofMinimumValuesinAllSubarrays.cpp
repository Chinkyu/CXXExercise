//  ¥‰∫√¿Ω....   monostack...
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
vector<int> findMaximums(vector<int>& n) {
	vector<int> res(n.size()), s;
	n.push_back(0);
	for (int i = 0; i < n.size(); ++i) {
		while (!s.empty() && n[s.back()] >= n[i]) {
			int j = s.back(), k = i - 1;
			s.pop_back();
			if (!s.empty())
				k -= s.back() + 1;
			res[k] = max(res[k], n[j]);
		}
		s.push_back(i);
	}
	for (int i = res.size() - 1; i > 0; --i)
		res[i - 1] = max(res[i - 1], res[i]);
	return res;
}
}

// timeout.. 
class _Solution {
public:
	vector<int> findMaximums(vector<int>& nums) {
		int l = nums.size();
		vector<int> ans(l, 0);

		for (int i = 0; i < l; ++i) {

			multiset<int> ms;
			for (int j = 0; j <= i; ++j) ms.insert(nums[j]);

			int tmax = *ms.begin();
			for (int j = 0; j + i + 1 < l; ++j) {
				ms.erase(ms.find(nums[j]));
				ms.insert(nums[j + i + 1]);
				tmax = max(tmax, *ms.begin());
			}

			ans[i] = tmax;
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> nums = { 0, 1, 2, 4 };

	vector<int> ans = sol.findMaximums(nums);

	for (auto &it : ans) {
		cout << it << " ";
	}

	cin >> c;
}