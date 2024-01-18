// easy
#include <iostream>
#include <vector>
#include <unordered_map>
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
	int minMoves(int target, int maxDoubles) {

		int ans = 0;
		
		while (target > 1) {
			ans++;
			if (target % 2 == 0 && maxDoubles > 0) {
				target = target / 2;
				maxDoubles--;
				continue;
			}
			else {
				if (maxDoubles > 0) {
					target--;
				}
				else {
					ans += target - 2;
					target = 1;
				}
			}
		};

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.minMoves(19, 2);

	cin >> c;
}