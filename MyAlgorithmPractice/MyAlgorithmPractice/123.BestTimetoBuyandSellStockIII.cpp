﻿// 답봤음... : 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // Array to store maximum profit from day i to the end
        std::vector<int> maxProfitFromRight(n);
        int maxPriceFromRight = 0;
        int maxProfit = 0;

        // Calculate the maximum profit that can be obtained by one transaction
        // starting from each day to the end
        for (int i = n - 1; i >= 0; --i) {
            maxPriceFromRight = std::max(maxPriceFromRight, prices[i]);
            maxProfit = std::max(maxProfit, maxPriceFromRight - prices[i]);
            maxProfitFromRight[i] = maxProfit;
        }

        // Minimum price from the left
        int minPriceFromLeft = INT_MAX;
        int totalMaxProfit = 0;

        // Calculate the maximum profit with at most two transactions
        for (int i = 0; i < n; ++i) {
            minPriceFromLeft = std::min(minPriceFromLeft, prices[i]);
            int profitWithCurrentTransaction = prices[i] - minPriceFromLeft;
            totalMaxProfit = std::max(totalMaxProfit, profitWithCurrentTransaction + maxProfitFromRight[i]);
        }

        return totalMaxProfit;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> heights = { 2,1,5,6,2,3 };

    cout << sol.largestRectangleArea(heights);

    cin >> c;
}