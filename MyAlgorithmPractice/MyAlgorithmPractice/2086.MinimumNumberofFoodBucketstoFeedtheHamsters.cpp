//  easy
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
	int minimumBuckets(string hamsters) {
		int l = hamsters.size();

		if (hamsters == "H" || hamsters == "HH") return -1;
		if (hamsters == "." || hamsters == "..") return 0;
		if (hamsters == "H." || hamsters == ".H") return 1;

		if (hamsters[0] == 'H' && hamsters[1] == 'H') return -1;
		if (hamsters[l-2] == 'H' && hamsters[l-1] == 'H') return -1;

		int ans = 0;
		for (int i = 0; i < l - 1; ++i) {
			if (hamsters[i] == 'H' && hamsters[i + 1] == 'H' && hamsters[i + 2] == 'H') {
				return -1;
			}
		}

		for (int i = 0; i < l - 1; ++i) {
			if (hamsters[i] == 'H' && hamsters[i + 1] == '.' && hamsters[i + 2] == 'H') {
				hamsters[i] = 'S';
				hamsters[i + 1] = 'S';
				hamsters[i + 2] = 'S';
				ans++;
			}
		}

		for (int i = 0; i < l; ++i) {
			if (hamsters[i] == 'H') ans++;
		}

		return ans;

	}
};

int main() {
	char c;

	Solution sol;

	string s = "H.HHH.H";// "H..H";
	cout << sol.minimumBuckets(s);

	cin >> c;
}