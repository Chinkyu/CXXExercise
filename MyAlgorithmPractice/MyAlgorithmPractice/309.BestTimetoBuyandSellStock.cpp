/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75957/An-8ms-C%2B%2B-DP-solution-easy-to-understand
Define buy[i] as the max profit when you buy the stock at day i.sell[i] as the max profit when you sell the stock at day i.Therefore set buy[0] = -prices[0], that if you buy the stock at first day, the profit is - prices[0], also set sell[0] = 0, that you do nothing in the first day.

sell[i] = max(buy[i - 1] + prices[i], sell[i - 1] - prices[i - 1] + prices[i]);
buy[i - 1] + prices[i] represents buy the stock on day i - 1 and sell it on day i; sell[i - 1] - prices[i - 1] + prices[i] represents you didn't sell the stock on day i-1 but sell it on day i (bought stock back and sell it on day i).

buy[i] = max(sell[i - 2] - prices[i], buy[i - 1] + prices[i - 1] - prices[i]);
sell[i - 2] - prices[i] means sold the stock on day i - 2 and buy it on day i(day i - 1 is cooldown).buy[i - 1] + prices[i - 1] - prices[i] means you didn't buy the stock on day i-1 but buy it on day i.

No doubt that the max profit would appear in sell[i].
*/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum STATE {
	BUY, 
	SELL, 
	COOLDOWN
};

class Solution {
public:
	enum STATE state;
	int max = 0;

	void iteration(vector<int>& prive, enum STATE st, int idx, int buy_price, int acc_income) {
		if (idx >= prive.size()) return;
		switch (st) {
		case BUY:
			iteration(prive, SELL, idx + 1, prive[idx], acc_income);
			iteration(prive, COOLDOWN, idx + 1, prive[idx], acc_income);
			break;
		case SELL:
			if (prive[idx] - buy_price <= 0) return;
			acc_income = acc_income + prive[idx] - buy_price;
			if (max < acc_income) max = acc_income;
			iteration(prive, COOLDOWN, idx + 1, -1, acc_income);
			break;
		case COOLDOWN:
			if (buy_price == -1) {  // didn't buy
				iteration(prive, BUY, idx+1, buy_price, acc_income);
				iteration(prive, COOLDOWN, idx + 1, buy_price, acc_income);
			}
			else {                  // bought before
				iteration(prive, SELL, idx + 1, buy_price, acc_income);
				iteration(prive, COOLDOWN, idx + 1, buy_price, acc_income);
			}
			break;
		}

	}


	int _maxProfit(vector<int>& prices) {
		int l = prices.size();
		if (l <= 0) return 0;

		max = 0;
		iteration(prices, BUY, 0, prices[0], 0);
		iteration(prices, COOLDOWN, 0, -1, 0);

		return max;
	}

	int maxProfit(vector<int>& p)
	{
		if (p.size() < 2)
			return 0;
		int i, sz = p.size();
		int ret = 0;
		vector<int> buy(sz, 0);
		vector<int> sell(sz, 0);
		buy[0] = -p[0];
		for (i = 1; i < sz; ++i)
		{
			sell[i] = std::max(buy[i - 1] + p[i], sell[i - 1] - p[i - 1] + p[i]);
			if (ret < sell[i]) //record the max sell[i]
				ret = sell[i];
			if (1 == i)
				buy[i] = buy[0] + p[0] - p[1];
			else
				buy[i] = std::max(sell[i - 2] - p[i], buy[i - 1] + p[i - 1] - p[i]);
		}
		return ret;
	}
};

int main() {
	char c;
	Solution sol;
	//vector<int> v = { 1, 2, 3, 0, 2 };
	vector<int> v = { 6,1,3,2,4,7 };

	cout << sol.maxProfit(v);
	cin >> c;
}