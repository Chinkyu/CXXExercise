// see answer : prime factorization
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <stack>
#include <bitset>
#include <set>
#include <list>
#include <cmath>
#include <regex>
#include <memory>

using namespace std;

class Solution
{
public:
    int smallestValue(int n, int s = 0)
    {
        for (int i = 2, m = n; i <= n; i++)
            for (; m % i == 0; s += i, m /= i);
        return s == n ? n : smallestValue(s);
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<string>> orders = { {"David", "3", "Ceviche"}, {"Corina", "10", "Beef Burrito"}, {"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"}, {"Carla", "5", "Ceviche"}, {"Rous", "3", "Ceviche"} };

    vector<vector<string>> ans = sol.displayTable(orders);

    for (auto& it : ans) {
        for (auto& jt : it) {
            cout << jt << " ";
        }
    }

    std::cin >> c;
}