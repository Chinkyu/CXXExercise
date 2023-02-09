// Accepted... 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	int totalFruit(vector<int>& fruits) {
		int len = fruits.size();
		int ans = 0;

		if (len <= 2) return len;

		// first two sorts
		int si = 0, ei = 0,  i = 0;

		do {

			// check length of max two num from si
			int sc = fruits[si], ec = -1;
			for (i = si; i < len; ++i) {
				if (fruits[i] != sc && ec == -1) {
					ec = fruits[i];
					ei = i;
				}

				if (fruits[i] == sc || fruits[i] == ec) {
					continue;
				}
				else {
					// check length and continue from next index(ei)
					//ans = max(ans, i - si);
					break;
				}
			}
			ans = max(ans, i - si);
			si = ei;

		}while (i < len);

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> fruits = { 1,2,3,2,2 };

	cout << "total : " << sol.totalFruit(fruits);

	//	cout << "test : " << ans << endl;

	cin >> c;
}