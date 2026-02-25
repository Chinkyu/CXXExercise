// see answer : sequence is matter , use visit vector. 
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
#include <random>
#include <chrono>
#include <iterator>

using namespace std;


// Need to ordring.... !!!!!! 
// Check tomorrow 
class _Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {

        sort(conversions.begin(), conversions.end());

        int n = 0;
        for (auto& it : conversions) {
            n = max(n, it[1]);
        }

        vector<int> ans(n+1, 1);
        for (auto& it : conversions) {
            ans[it[1]] = ans[it[0]] * it[2];
            ans[it[1]] %= 1000000007;
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {

        sort(conversions.begin(), conversions.end());

        int n = 0;
        for (auto& it : conversions) {
            n = max(n, it[1]);
        }

        vector<int> ans(n + 1, 1);
        vector<bool> v(n + 1, false);
        v[0] = true;

        int remain = n + 1;
        int pre_remain = remain;
        do {
            pre_remain = remain;
            for (auto& it : conversions) {
                if (v[it[0]] == true && v[it[1]] == false) {
                    ans[it[1]] = (ans[it[0]] * (long long)it[2]) % 1000000007;
                    //ans[it[1]] %= 1000000007;
                    v[it[1]] = true;
                    remain--;
                }
            }
        } while (remain != pre_remain);

        return ans;
    }
};


int main() {
    char c;
    Solution sol;

    vector<vector<int>> conversions = {{0, 1, 2}, { 1, 2, 3 }};

    vector<int> ans = sol.baseUnitConversions(conversions);

    for (auto& it : ans) {
        cout << it << " ";
    }


    cin >> c;
}
