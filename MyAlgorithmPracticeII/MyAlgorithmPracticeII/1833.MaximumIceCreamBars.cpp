// easy 

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
#include <functional>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        sort(costs.begin(), costs.end());

        int acc = 0;
        for (int i = 0; i < costs.size(); ++i) {
            acc += costs[i];
            if (acc > coins) {
                return i;
            }
        }

        return costs.size();
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> costs = { 1,6,3,1,2,5 };

    cout << sol.maxIceCream(costs, 20);

    cin >> c;
}