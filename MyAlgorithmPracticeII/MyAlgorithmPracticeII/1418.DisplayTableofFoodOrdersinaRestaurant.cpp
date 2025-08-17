// ok... two map
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

class Solution {
public:

    enum {
        BeefBurrito = 0,
        Ceviche = 1,
        FriedChicken = 2,
        Water = 3
    };



    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string, int>> m;
        vector<vector<string>> ans;
        map<string, int> menu;

        for (auto& it : orders) {
            int table = stoi(it[1]);
            m[table][it[2]]++;
            menu[it[2]]++;
        }

        vector<string> head = { "Table" };
        for (auto& it : menu) {
            head.push_back(it.first);
        }
        ans.push_back(head);


        for (auto& it : m) {
            vector<string> tuple;
            tuple.push_back(to_string(it.first));
            for (auto& jt : menu) {
                tuple.push_back(to_string(it.second[jt.first]));
            }
            ans.push_back(tuple);
        }

        return ans;
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