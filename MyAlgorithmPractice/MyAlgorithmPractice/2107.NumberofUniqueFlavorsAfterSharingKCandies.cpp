// easy : Sliding window
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
	int shareCandies(vector<int>& candies, int k) {
		unordered_map<int, int> m;
		int l = candies.size();

		for (auto &it : candies) {
			m[it]++;
		}

		// from zero
		for (int i = 0; i < k; ++i) {
			m[candies[i]]--;
			if (m[candies[i]] == 0)  m.erase(candies[i]);
		}

		int ans = m.size();


		for (int i = 1; i <= l - k; ++i) {
			m[candies[i - 1]]++;
			//if (m[candies[i-1]] == 0)  m.erase(candies[i-1]);
			m[candies[i+k-1]]--;
			if (m[candies[i+k-1]] == 0)  m.erase(candies[i+k-1]);
			ans = max(ans, (int)m.size());
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> candies =   { 1, 2, 3, 2, 2, 2 }; //{ 1, 2, 2, 3, 4, 3 }; //

	cout << sol.shareCandies(candies, 3);

	cin >> c;
}