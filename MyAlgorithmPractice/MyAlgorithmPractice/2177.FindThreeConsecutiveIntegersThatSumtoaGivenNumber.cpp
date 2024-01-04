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
#include <cmath>

using namespace std;

class Solution {
public:
	vector<long long> sumOfThree(long long num) {
		vector<long long> ans;
		long long mid = num / 3;

		if (mid * 3 != num) return ans;

		ans.push_back(mid - 1);
		ans.push_back(mid);
		ans.push_back(mid + 1);

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<long long> ans = sol.sumOfThree(33);

	for (auto &it : ans) {
		cout << it << " ";
	}

	cin >> c;

}