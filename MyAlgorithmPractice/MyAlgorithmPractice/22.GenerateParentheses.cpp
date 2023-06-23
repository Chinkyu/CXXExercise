// ( == +1, ) == -1 로 해서 쉽게 해결됨 
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


class Solution {
public:
	vector<string> ans;
	void iterate(string s, int n, int cn, int h) {

		if (cn == n * 2) {
			if (h == 0) {
				// add value
				ans.push_back(s);
				return;
			}
			else {
				return;
			}
		}

		// {
		if (0 <= h + 1 && h + 1 <= n) {
			s.push_back('(');
			iterate(s, n, cn + 1, h + 1);
			s.pop_back();
		}


		// }
		if (0 <= h - 1 && h - 1 <= n) {
			s.push_back(')');
			iterate(s, n, cn + 1, h - 1);
			s.pop_back();
		}
	}



	vector<string> generateParenthesis(int n) {
		ans.clear();
		string s;
		iterate(s, n, 0, 0);

		return ans;
	}
};


int main() {
	char c;

	Solution sol;

	vector<string> ans = sol.generateParenthesis(3);

	for (auto it : ans) {
		cout << it << endl;
	}

	cin >> c;
}