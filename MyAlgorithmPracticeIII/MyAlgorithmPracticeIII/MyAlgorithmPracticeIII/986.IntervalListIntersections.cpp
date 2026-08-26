// ok... sliding window....  up/down check 
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
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        map<int, int> sw;

        for (auto& it : firstList) {
            sw[it[0]]++;
            sw[it[1]]--;
        }

        for (auto& it : secondList) {
            sw[it[0]]++;
            sw[it[1]]--;
        }

        int level = 0;
        vector<vector<int>> ans;
        vector<int> block(2, -1);
        for (auto& it : sw) {
            if (it.second == 0) {
                ans.push_back({ it.first, it.first });
            }

            level += it.second;

            if (level == 2) {
                block[0] = it.first;
            }
            else if (block[0] != -1 && level <= 1) {
                block[1] = it.first;
                ans.push_back(block);
                block = { -1, -1 };
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "aabca";

    cout << sol.mergeCharacters(s, 2);
    cin >> c;
}
