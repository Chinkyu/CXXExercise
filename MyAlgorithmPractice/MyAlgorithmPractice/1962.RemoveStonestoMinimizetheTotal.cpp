// easy
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
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
	int minStoneSum(vector<int>& piles, int k) {
		multiset<int> ms(piles.begin(), piles.end());

		for (int i = 0; i < k; ++i) {
			int v = *ms.rbegin();
			ms.erase(ms.find(v));
			v = ceil((double)v / 2);
			ms.insert(v);
		}

		int sum = 0;
		for (auto &it : ms) sum += it;

		return sum;
	}
};

int main() {
	char c;
	Solution sol;

	vector<int> piles = { 4, 3, 6, 7 };

	cout << sol.minStoneSum(piles, 3);

	cin >> c;
}