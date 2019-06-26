#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<string>> ans;
	vector<string> cur;

	bool isPalindrom(string s) {
		int n = s.size();

		for (int i = 0; i < n / 2; ++i) {
			if (s[i] != s[n - i - 1]) return false;
		}
		return true;

	}

	void iteration(string s) {

		for (int i = 1; i <= s.size(); ++i) {
			string ss = s.substr(0, i);

			if (isPalindrom(ss)) {
				cur.push_back(ss);
			}
			else {
				continue;
			}

			if (s.size() - i != 0) {
				iteration(s.substr(i, s.size() - i));
			}
			else {
				ans.push_back(cur);

			}
			cur.pop_back();
		}

	}
	
	vector<vector<string>> partition(string s) {
		ans.clear();
		cur.clear();

		//if (s.size() == 0) return ans;
		iteration(s);

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<string>> ans = sol.partition("");

	for (auto it : ans) {
		for (auto jt : it) {
			cout << jt.c_str() << " ";
		}
		cout << endl;
	}

	cin >> c;
}
