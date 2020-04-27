#include <iostream>
#include <string>
#include <vector>

using namespace std;

// find continuous -> n!+  =>연속되면 펙토리얼을 더해주면 됨. 

class Solution {
public:
	int findSubstringInWraproundString(string p) {
		vector<int> letters(26, 0);
		int res = 0, len = 0;
		for (int i = 0; i < p.size(); i++) {
			int cur = p[i] - 'a';
			if (i > 0 && p[i - 1] != (cur + 26 - 1) % 26 + 'a') len = 0;
			if (++len > letters[cur]) {
				res += len - letters[cur];
				letters[cur] = len;
			}
		}
		return res;
	}
};

int main() {
	char c;
	string s = "eabcd"; //  "bcdea";
	Solution sol;

	cout << sol.findSubstringInWraproundString(s);
	cin >> c;
}
