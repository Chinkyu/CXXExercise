#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isSame(vector<int> &a, vector<int> &b, int sz) {
		for (int i = 0; i < sz; ++i) {
			if (a[i] != b[i]) return false;
		}
		return true;
	}

	vector<int> findAnagrams(string s, string p) {
		int sl = s.size();
		int pl = p.size();

		vector<int> r(26, 0), c(26, 0);
		vector<int> ans;

		if (sl <= 0 || pl <= 0 || sl < pl) return ans;

		for (int i = 0; i < pl; ++i) r[p[i] - 'a']++;
		for (int i = 0; i < pl; ++i) c[s[i] - 'a']++;

		int i = 0;
		do {
			if (true == isSame(r, c, 26)) {
				ans.push_back(i);
			}

			c[s[i] - 'a']--;
			if (i + pl < sl) c[s[i + pl] - 'a']++;
			i++;
		} while (i + pl <= sl);

		return ans;
	}
};

int main() {
	char c;
//	string s = "cbaebabacd";
//	string p = "abc";
	string s = "abab";
	string p = "ab";
	Solution sol;

	vector<int> ans = sol.findAnagrams(s, p);
	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;
}