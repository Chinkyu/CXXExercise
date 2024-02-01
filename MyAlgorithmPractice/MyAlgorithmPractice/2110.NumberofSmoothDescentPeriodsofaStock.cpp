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

	long long factorial(int f) {
		long long ans = 0;
		for (int i = 1; i <= f; ++i) ans += i;
		return ans;
	}

	long long getDescentPeriods(vector<int>& prices) {
		int l = prices.size();

		vector<int> group;

		int gCount = 1, gCountSum = 0;
		for (int i = 1; i < l; ++i) {
			if (prices[i - 1] == prices[i] + 1) {
				gCount++;
			}
			else {
				if (gCount > 1) {
					group.push_back(gCount);
					gCountSum += gCount;
					gCount = 1;
				}
			}
		}

		if (gCount > 1) {
			group.push_back(gCount);
			gCountSum += gCount;
			gCount++;
		}

		long long ans = 0;
		ans += l - gCountSum;
		for (auto &it : group) {
			ans += factorial(it);
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> prices = { 8, 6, 7, 7 }; //{ 3, 2, 1, 4 };

	cout << sol.getDescentPeriods(prices);

	cin >> c;
}