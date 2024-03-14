// ¥‰∫√¿Ω :  sliding window
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
	int equalCountSubstrings(string s, int count) {
		int res = 0, max_unique = unordered_set(begin(s), end(s)).size();
		for (int unique = 1; unique <= max_unique; ++unique) {
			int cnt[26] = {}, len = count * unique, has_count = 0;
			for (int i = 0; i < s.size(); ++i) {
				if (++cnt[s[i] - 'a'] == count)
					++has_count;
				if (i >= len && --cnt[s[i - len] - 'a'] == count - 1)
					--has_count;
				res += has_count == unique;
			}
		}
		return res;
	}
};

int main() {
	char c;
	Solution sol;

	pair<int, int> p1, p2;

	string encodedText = "ch   ie   pr";
	cout << sol.decodeCiphertext(encodedText, 3);

	cin >> c;
}