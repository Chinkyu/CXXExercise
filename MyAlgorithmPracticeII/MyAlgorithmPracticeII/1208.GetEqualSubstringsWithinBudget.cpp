// OK
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

using namespace std;

class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		int l = s.size();
		int cost = 0;
		int maxLen = 0;

		int st = 0, ed = 0;

		while (ed < l && cost <= maxCost) {
			//cost += abs(s[ed] - t[ed]);
			if (cost + abs(s[ed] - t[ed]) > maxCost) break;
			cost += abs(s[ed] - t[ed]);
			ed++;
		}
		maxLen = ed - st;

		for (int i = 0; i < l; ++i) {
			cost -= abs(s[i] - t[i]);
			st = i + 1;
			while (ed < l &&  cost <= maxCost) {
				//cost += abs(s[ed] - t[ed]);
				if (cost + abs(s[ed] - t[ed]) > maxCost) break;
				cost += abs(s[ed] - t[ed]);
				ed++;
			}

			maxLen = max(maxLen, ed - st);
		}

		return maxLen;
	}
};

int main() {
	char c;
	Solution sol;

//	string s = "krpgjbjjznpzdfy";
//	string t = "nxargkbydxmsgby";

	string s = "abcd";
	string t = "bcdf";


	cout << sol.equalSubstring(s, t, 3);

	cin >> c;
}