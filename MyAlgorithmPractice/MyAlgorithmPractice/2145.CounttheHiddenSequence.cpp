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
	int numberOfArrays(vector<int>& differences, int lower, int upper) {

		long long num = 0;
		long long l = 0, h = 0;

		for (auto &it : differences) {
			num += it;

			l = min(l, num);
			h = max(h, num);
		}

		int ans = (upper - lower) - (h - l) + 1;
		if (ans < 0) ans = 0;
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> differences = { 1, -3, 4 };

	cout << sol.numberOfArrays(differences, 1, 6);

	cin >> c;
}