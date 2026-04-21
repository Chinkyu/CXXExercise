// see answer : dp
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
    // int count(int amount, vector<int> &coins, int i){
    //     if(amount ==0){
    //         return 1;
    //     }
    //     if(amount<0 || coins.size() <= i){
    //         return 0;
    //     }
    //     int include = count(amount - coins[i], coins, i);
    //     int exclude =count(amount, coins, i+1);
    //     return include + exclude;
    // }
    int change(int amount, vector<int>& coins) {
        //return count(amount, coins, 0);
        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto coin : coins) {
            if (coin > amount) {
                continue;
            }
            for (auto c = coin; c <= amount; c++) {
                dp[c] += dp[c - coin];
            }
        }
        return (int)dp[amount];
    }
};



// timeout... 
class _Solution {
public:
    int search(int amount, vector<int>& coins, int coin_level) {
        int ans = 0;

        int coin = coins[coin_level];

        // if coin_level == 0, check remainder
        if (coin_level == 0) {
            cout << amount << " ";
            if (amount % coins[0] == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }


        do {
            if (amount == 0) return ans + 1;
            if (amount < 0) return 0;
            if (coin_level > 0) {
                ans += search(amount, coins, coin_level - 1);
            }
            amount -= coin;
        } while (amount >= 0);

        return ans;
    }



    int change(int amount, vector<int>& coins) {

        sort(coins.begin(), coins.end());

        int ans = search(amount, coins, coins.size() - 1);

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
   
    vector<int> coins = { 3,5,7,8,9,10,11 };
    //{ 1, 2, 5 };

    cout << sol.change(1000, coins);

    cin >> c;
}
