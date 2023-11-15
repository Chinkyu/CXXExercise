// easy with remained Cap and sort 
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
	int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
		vector<int> rCap;

		for (int i = 0; i < capacity.size(); ++i) {
			rCap.push_back(capacity[i] - rocks[i]);
		}

		sort(rCap.begin(), rCap.end());

		int sum = 0;
		for (int i = 0; i < rCap.size(); ++i) {
			sum += rCap[i];
			if (sum > additionalRocks) {
				return i;
			}
		}
		return rCap.size();
	}
};


int main() {
	char c;

	Solution sol;

	vector<int> candidates = { 16,17,71,62,12,24,14 };
	cout << sol.largestCombination(candidates);

	cin >> c;

}