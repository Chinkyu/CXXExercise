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
	int maxConsecutive(int bottom, int top, vector<int>& special) {

		sort(special.begin(), special.end());
		special.push_back(top + 1);

		int maxGap = special[0] - (bottom - 1) - 1;
		for (int i = 1; i < special.size(); ++i) {
			int gap = special[i] - special[i - 1] - 1;
			maxGap = max(maxGap, gap);
		}
		return maxGap;
	}
};


int main() {
	char c;

	Solution sol;

	vector<int> special = { 7, 6, 8 };
	cout << sol.maxConsecutive(6, 8, special);

	cin >> c;

}