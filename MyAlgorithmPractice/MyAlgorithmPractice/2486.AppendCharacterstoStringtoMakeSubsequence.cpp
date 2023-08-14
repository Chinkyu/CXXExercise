// easy
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
	int appendCharacters(string s, string t) {
		int sl = s.size(), tl = t.size();

		int t_idx = 0;
		for (int i = 0; i < sl; ++i) {
			if (s[i] == t[t_idx]) t_idx++;
		}
		return tl - t_idx;
	}
};

int main() {
	char c;

	Solution sol;
	string s = "coaching", t = "coding";

	cout << sol.appendCharacters(s, t);

	cin >> c;
}