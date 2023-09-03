//  답봤음.  dp로 풀어야 된다네...
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


class Solution
{
	int dp[101][1001][6] = {};
public:
	int maxTastiness(vector<int> &price, vector<int> &taste, int maxAmount, int maxCoupons, int k = 0)
	{
		if (maxAmount < 0 || maxCoupons < 0)
			return -1e9;

		if (k >= price.size())
			return 0;

		if (!dp[k][maxAmount][maxCoupons])
		{
			int r0 = taste[k] + maxTastiness(price, taste, maxAmount - price[k], maxCoupons, k + 1);
			int r1 = taste[k] + maxTastiness(price, taste, maxAmount - price[k] / 2, maxCoupons - 1, k + 1);
			int r2 = maxTastiness(price, taste, maxAmount, maxCoupons, k + 1);
			dp[k][maxAmount][maxCoupons] = max({ r0, r1, r2, 0 }) + 1;
		}

		return dp[k][maxAmount][maxCoupons] - 1;
	}
};

class _Solution {
public:
	int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
		int l = price.size();
		vector<pair<int, int>> v(l);

		for (int i = 0; i < l; ++i) {
			v[i] = make_pair(price[i], tastiness[i]);
		}

		sort(v.begin(), v.end(), [](pair<int, int> l, pair<int, int> r) {
			if (l.first == r.first) return l.second > r.second; return l.first < r.first; });


		int maxTaste = 0;

		for (int i = 0; i < l; ++i) {
			int r_coupons = maxCoupons;
			int taste = 0;
			int cost = 0;
			for (int j = i; j >= 0; --j) {
				taste += v[j].second;
				if (r_coupons > 0) {
					cost += v[j].first/2;
					r_coupons--;
				}
				else {
					cost += v[j].first;
				}
			}
			if (cost <= maxAmount && maxTaste < taste) maxTaste = taste;
		}


		return maxTaste;
	}
};

int main() {
	char c;

	Solution sol;
	vector<int> price = { 10, 20, 20 };
	vector<int> tastiness = { 5, 8, 8 };


	cout << sol.maxTastiness(price, tastiness, 20, 1);

	cin >> c;
}