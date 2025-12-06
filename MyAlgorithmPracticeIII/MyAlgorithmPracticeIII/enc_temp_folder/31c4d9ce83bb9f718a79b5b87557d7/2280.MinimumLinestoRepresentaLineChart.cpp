// see answer : hamming distance 구하는게 생각보다 쉽네.  a ^ b   -> __biltin_popcount()  
//   
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
    int minimumLines(vector<vector<int>>& stockPrices) {
        int l = stockPrices.size();
        int ans = 1;

        if (l <= 1) return 0;

        // need to sort sirst. 
        sort(stockPrices.begin(), stockPrices.end());

        double ang = ((double)stockPrices[1][1] - stockPrices[0][1]) / ((double)stockPrices[1][0] - stockPrices[0][0]);

        for(int i = 2; i < l; ++i) {
            double nang = ((double)stockPrices[i][1] - stockPrices[i-1][1]) / ((double)stockPrices[i][0] - stockPrices[i - 1][0]);
            if (ang != nang) {
                ans++;
                ang = nang;
            }
        }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<vector<int>> stockPrices = { {1, 7}, {2, 6}, {3, 5}, {4, 4}, {5, 4}, {6, 3}, {7, 2}, {8, 1} };
    vector<vector<int>> stockPrices = { {1, 1},{500000000, 499999999},{1000000000, 999999998} };

    cout << sol.minimumLines(stockPrices);

    cin >> c;
}
