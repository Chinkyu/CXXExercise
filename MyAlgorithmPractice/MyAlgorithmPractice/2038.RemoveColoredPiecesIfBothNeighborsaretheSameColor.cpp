//   easy
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
	bool winnerOfGame(string colors) {

		// find a, b
		vector<int> count(2, 0);
		int l = colors.size();
		
		char c = colors[0];
		int cCount = 1;

		for (int i = 1; i < l; ++i) {
			if (colors[i] == c) {
				cCount++;
			}
			else {
				count[c - 'A'] += (cCount >= 3) ? cCount - 2 : 0;
				cCount = 1;
				c = colors[i];
			}
		}

		if (cCount >= 3) {
			count[c - 'A'] += (cCount >= 3) ? cCount - 2 : 0;
		}

		if (count[0] > count[1]) return true;

		return false;
	}
};


int main() {
	char c;
	Solution sol;

	string colors = "AAAABBBB"; // "AAABABB";

	cout << sol.winnerOfGame(colors);

	cin >> c;
}