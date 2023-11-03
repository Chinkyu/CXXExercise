//   binary search  ÀÀ¿ë
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
		vector<int> ans;

		// use binary search to find fist number larger or equal thdn success
		sort(potions.begin(), potions.end());

		for (int i = 0; i < spells.size(); ++i) {
			// binary search 
			int li = 0, ri = potions.size() - 1;
			int mi = (li + ri) / 2;
			while (li < ri) {
				mi = (li + ri) / 2;
				if (spells[i] * (long long)potions[mi] < success) {
					li = mi;
				}
				else if (success <= spells[i] * (long long)potions[mi]) {
					ri = mi;
				}
				if (li + 1 == ri) break;
			}

			if (success <= spells[i] * (long long)potions[li]) {
				ans.push_back(potions.size() - li);
			}
			else if (spells[i] * (long long)potions[li] < success && success <= spells[i] * (long long)potions[ri]) {
				ans.push_back(potions.size() - ri);
			}
			else {
				ans.push_back(0);
			}
		}
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<int> spells = { 5, 1, 3 };
	//vector<int> potions = { 1, 2, 3, 4, 5 };

	vector<int> spells = { 3, 1, 2 };
	vector<int> potions = { 8, 5, 8 };
	vector<int> ans = sol.successfulPairs(spells, potions, 16);

	for (auto it : ans) {
		cout << it << " ";
	}

	cin >> c;

}