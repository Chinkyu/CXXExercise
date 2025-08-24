// trickey for timeout : reduce shifts with map.. 
// unordere_map vs map    : unordered_map can't use vector<int> as key
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
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int l = s.size();
        vector<int> move(l, 0);

        map<vector<int>, int> m;
        // preprocessing of shifts
        for (auto& it : shifts) {
            if (it[2] == 1) {
                m[{it[0], it[1]}]++;
            }
            else {
                m[{it[0], it[1]}]--;
            }
            //m[{it[0], it[1]}] += (it[2] == 1) ? 1 : -1;
        }


        for (auto& it : m) {
            for (int i = it.first[0]; i <= it.first[1]; ++i) {
                move[i] += it.second;
                //move[i] %= 26;
            }
        }

        // processing each char
        for (int i = 0; i < l; ++i) {
            //if (move[i] < 0) move[i] += 26;
            move[i] %= 26;
            int t = s[i];
            t += move[i];

            if (t < 'a') t = 'z' - ('a' - t - 1);
            if ('z' < t) t = 'a' + (t - 'z' - 1);

            s[i] = t;
        }

        return s;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "ksztajnymer";
    vector<vector<int>> shifts =
        {{4, 9, 1}, {2, 5, 1}, {7, 9, 0}, {6, 10, 0}, {1, 7, 1}, {0, 7, 1}, {0, 3, 0}, {3, 3, 1}, {7, 9, 0}, {7, 7, 0}, {6, 7, 0}, {7, 9, 0}, {3, 9, 0}, {10, 10, 1}, {8, 9, 0}, {6, 9, 1}, {1, 2, 1}, {3, 9, 0}, {8, 10, 1}, {4, 7, 1}, {9, 10, 1}, {8, 9, 0}, {5, 8, 0}, {8, 9, 1}, {0, 7, 1}, {2, 2, 1}, {8, 8, 1}, {3, 7, 0}, {1, 10, 1}, {9, 9, 1}, {4, 9, 0}, {5, 6, 1}, {7, 8, 1}, {8, 9, 0}, {7, 7, 1}, {9, 9, 1}};


    cout << sol.shiftingLetters(s, shifts);

    std::cin >> c;
}