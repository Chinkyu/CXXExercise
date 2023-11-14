// eash  with bitmask count 

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
	int largestCombination(vector<int>& candidates) {
		vector<int> bc(32, 0);

		for (auto it : candidates) {
			int t = it;
			for (int i = 0; t > 0; ++i) {
				if (t % 2 == 1) bc[i]++;
				t /= 2;
			}
		}

		// find max
		int tmax = 0;
		for (int i = 0; i < bc.size(); ++i) {
			tmax = max(tmax, bc[i]);
		}
		return tmax;
	}
};


int main() {
	char c;

	Solution sol;

	vector<int> candidates = { 16,17,71,62,12,24,14 };
	cout << sol.largestCombination(candidates);

	cin >> c;

}