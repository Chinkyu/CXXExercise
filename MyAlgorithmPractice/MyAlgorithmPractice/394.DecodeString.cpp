#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string decodeString(string s) {
		string ans;
		int l = s.size();

		if (l <= 0) return "";


		while (true) {
			int p = 0, q = 0, count = 0;

			l = s.size();
			for (int i = 0; i < l; ++i) {
				if (s[i] == '[') {
					count++;
					q = p;
					p = i;
				}
			}

			if (count <= 0) return s;

			ans = "";
			if (q != 0) {
				ans = s.substr(0, q + 1);
				++q;
			}

			for (int i = q; i < l; ++i) {
				if (s[i] < '0' || '9' < s[i]) {
					ans.push_back(s[i]);
					continue;
				}

				int st = i;
				// find [
				while (s[++i] != '[');
				int op = i;


				while (s[++i] != ']');
				int ed = i;

				int num = stoi(s.substr(st, op - st));
				for (int k = 0; k < num; ++k) {
					ans.append(s.substr(op + 1, ed - op - 1));
				}
			}
			s = ans;
		}
		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	string s = "leetcode"; //"3[a2[c]]";//"2[abc]3[cd]ef";//s = "3[a]2[bc]";

	cout << sol.decodeString(s);

	cin >> c;
}