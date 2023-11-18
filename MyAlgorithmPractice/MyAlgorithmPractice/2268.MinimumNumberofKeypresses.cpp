// easy
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;

class Solution {
public:
	int minimumKeypresses(string s) {
		int ans = 0;
		vector<int> c(26, 0);

		for (auto it : s) {
			c[it - 'a']++;
		}

		// sort reverse order
		sort(c.begin(), c.end(), greater<int>());

		for (int i = 0; i < c.size() && c[i] != 0; ++i) {
			int numPress = i / 9 + 1;
			ans += numPress * c[i];
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	string s = "aaaaaaaabcdefgggghijkllllllllllmmmnoppponono"; // "apple";
	cout << sol.minimumKeypresses(s);

	cin >> c;

}