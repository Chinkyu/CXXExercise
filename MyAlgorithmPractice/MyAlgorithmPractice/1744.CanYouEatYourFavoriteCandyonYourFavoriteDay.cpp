//	요거는 답을 봤음... 
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
#include <cmath>

using namespace std;


class Solution {
public:
	vector<bool> canEat(vector<int>& candies, vector<vector<int>>& queries) {
		int n = candies.size();
		vector<long long> prefix(n + 1, 0);
		for (int i = 1; i < n + 1; ++i) prefix[i] = prefix[i - 1] + candies[i - 1];

		vector<bool> ans;
		for (auto &query : queries) {
			long long type = query[0], day = query[1], capacity = query[2];
			long long maxDay = prefix[type + 1] - 1;
			long long minDay = prefix[type] / capacity;

			if (day <= maxDay && day >= minDay) ans.push_back(true);
			else ans.push_back(false);
		}

		return ans;
	}
};
int main() {
	char c;

	Solution sol;
	cout << sol.countHousePlacements(7);

	cin >> c;
}




