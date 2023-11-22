//   easy  
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
	int minimumCardPickup(vector<int>& cards) {
		int ans = INT_MAX;
		unordered_map<int, int> m;

		for (int i = 0; i < cards.size(); ++i) {
			if (m.find(cards[i]) == m.end()) {
				m[cards[i]] = i;
			}
			else {
				int gap = i - m[cards[i]] + 1;
				ans = min(ans, gap);
				m[cards[i]] = i;
			}
		}
		if (ans == INT_MAX) ans = -1;
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> cards = { 3,4,2,3,4,7 };

	cout << sol.minimumCardPickup(cards);

	cin >> c;

}