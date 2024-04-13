// easy : combination calculator 
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
	long long NCR(int n, int k)
	{
		if (k > n) return 0;
		if (k * 2 > n) k = n - k;
		if (k == 0) return 1;

		long long result = n;
		for (int i = 2; i <= k; ++i) {
			result *= (n - i + 1);
			result /= i;
		}
		return result;
	}

	long long interchangeableRectangles(vector<vector<int>>& rectangles) {
		unordered_map<double, int> m;

		for (auto &it : rectangles) m[(double)it[0] / it[1]]++;

		long long ans = 0;
		for (auto it : m) {
			ans += NCR(it.second, 2);
		}

		return ans;
	}
};

int main() {
	char c;
	Solution sol;

	vector<vector<int>> rectangles = {{4, 8}, {3, 6}, {10, 20}, {15, 30}}; // { {4, 5}, { 7, 8 } };

	cout << sol.interchangeableRectangles(rectangles);

	cin >> c;
}