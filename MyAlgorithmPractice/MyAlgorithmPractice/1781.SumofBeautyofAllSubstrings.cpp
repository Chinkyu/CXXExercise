//	count variable  가지고는 timeout -> map  가지고 ok.. 
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

//  답 나온.... 
class ans_Solution {
public:
	int res(unordered_map<char, int>&mp) {
		int mf = -1;
		int lf = INT_MAX;
		for (auto &it : mp) {
			mf = max(mf, it.second);
			if (it.second >= 1) {
				lf = min(lf, it.second);
			}

		}
		return mf - lf;
	}
	int beautySum(string s) {
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			unordered_map<char, int>mp;
			for (int j = i; j < s.size(); j++) {
				mp[s[j]]++;
				ans = ans + res(mp);
			}
		}
		return ans;
	}
};


//  map  으로 해서... 
class Solution {
public:

	int getBeauty(unordered_map<char, int> &m) {
		int cmin = INT_MAX, cmax = -1;
		for (auto it : m) {
			if (it.second == 0) continue;
			cmin = min(cmin, it.second);
			cmax = max(cmax, it.second);
		}

		if (cmin == 0 || cmax == 0) return 0;
		return cmax - cmin;
	}



	int beautySum(string s) {
		int n = s.size();
		int ans = 0;

		for (int i = 0; i <= n - 3; i++) {
			unordered_map<char, int> m;
			for (int j = i; j < n; ++j) {
				m[s[j]]++;
				ans += getBeauty(m);
			}
		}
		return ans;
	}
};


// Timeout... !!! 
class _Solution {
public:

	// timeout  -> let's modify it 
	int getBeauty(string &s, int sti, int edi) {
		vector<int> c(26, 0);

		for (int i = sti; i <= edi; ++i) {
			c[s[i] - 'a']++;
		}

		int cmin = INT_MAX, cmax = -1;
		for (int i = 0; i < 26; ++i) {
			if (c[i] == 0) continue;
			cmin = min(cmin, c[i]);
			cmax = max(cmax, c[i]);
		}

		if (cmin == 0 || cmax == 0) return 0;
		return cmax - cmin;
	}



	int beautySum(string s) {
		int n = s.size();
		int ans = 0;

		for (int i = 0; i <= n - 3; i++) {
			for (int j = i + 2; j < n; ++j) {
				ans += getBeauty(s, i, j);
			}
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	string s = "aabcb";
	cout << sol.beautySum(s);

	cin >> c;
}
