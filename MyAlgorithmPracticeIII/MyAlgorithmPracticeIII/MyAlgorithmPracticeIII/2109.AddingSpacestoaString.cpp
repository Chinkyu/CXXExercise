// ok : using copy
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

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;

        int idx = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (idx < spaces.size() && i == spaces[idx]) {
                ans.push_back(' ');
                idx++;
            }

            ans.push_back(s[i]);
            
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "LeetcodeHelpsMeLearn";
    vector<int> spaces = { 8, 13, 15 };

    cout << sol.addSpaces(s, spaces);

    cin >> c;
}
