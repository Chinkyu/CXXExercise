//  easy 
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
	long long waysToBuyPensPencils(int total, int cost1, int cost2) {
		long long ans = 0;
		int d1 = total / cost1;
		int d2 = 0;
		for (int i = 0; i <= d1; ++i) {
			int ttotal = total - (cost1 * i);
			d2 = ttotal / cost2;
			ans += d2 + 1;
		}

		return ans;
	}
};





int main() {
	char c;

	Solution sol;

	cout << sol.waysToBuyPensPencils(20, 10, 5);

	cin >> c;

}