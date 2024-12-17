// 답보고 했음... 
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

    bool isValid(int x, int y, unordered_map<string, int>& map) {

        string ob = to_string(x) + "," + to_string(y);

        if (map.find(ob) != map.end()) return false;

        return true;
    }

    pair<int, int> getCords(pair<int, int> co, int k, unordered_map<string, int>& map, int dir) {

        int x = co.first, y = co.second;
        for (int i = 1; i <= k; i++) {

            if (dir == 0) {
                if (isValid(x, y + 1, map)) y += 1;
                else break;
            }
            else if (dir == 1) {
                if (isValid(x + 1, y, map)) x += 1;
                else break;
            }
            else if (dir == 2) {
                if (isValid(x, y - 1, map)) y -= 1;
                else break;
            }
            else if (dir == 3) {
                if (isValid(x - 1, y, map)) x -= 1;
                else break;
            }

        }

        return { x,y };

    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int dir = 0, ans = 0;
        unordered_map<string, int> map;

        for (auto it : obstacles) {
            string s = to_string(it[0]) + "," + to_string(it[1]);
            map[s] = 1;
        }

        pair<int, int> co = { 0,0 };

        for (int i = 0; i < commands.size(); i++) {

            if (commands[i] == -2) {
                dir -= 1;
                if (dir < 0) dir += 4;
            }
            else if (commands[i] == -1) {
                dir = (dir + 1) % 4;
            }
            else {
                pair<int, int> cords = getCords(co, commands[i], map, dir);
                co = cords;
                ans = max(ans, co.first * co.first + co.second * co.second);
            }
        }

        return ans;

    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> points = { {3, 3}, {5, -1}, {-2, 4} };

    vector<vector<int>> ans = sol.kClosest(points, 2);

    for (auto& it : ans) {
        cout << it[0] << " " << it[1] << endl;
    }

    cin >> c;
}