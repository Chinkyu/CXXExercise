//  ´äÂüÁ¶ :
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;

class Solution {
public:
	string reorganizeString(string S) {
		vector<int> cnt(26);
		int mostFreq = 0, i = 0;

		for (char c : S)
			if (++cnt[c - 'a'] > cnt[mostFreq])
				mostFreq = (c - 'a');

		if (2 * cnt[mostFreq] - 1 > S.size()) return "";

		while (cnt[mostFreq]) {
			S[i] = ('a' + mostFreq);
			i += 2;
			cnt[mostFreq]--;
		}

		for (int j = 0; j < 26; j++) {
			while (cnt[j]) {
				if (i >= S.size()) i = 1;
				S[i] = ('a' + j);
				cnt[j]--;
				i += 2;
			}
		}

		return S;
	}
};

int main() {
    char c;
    Solution sol;
    string s = "aaab";

    cout << sol.reorganizeString(s);

    cin >> c;
}