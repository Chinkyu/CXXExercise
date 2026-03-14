// ok : use map
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
    vector<string> findRepeatedDnaSequences(string s) {
        int l = s.size();
        unordered_map<string, int> m;

        for (int i = 0; i < l - 1; ++i) {
            m[s.substr(i, 10)]++;
        }

        vector<string> ans;
        for (auto& it : m) {
            if (it.second >= 2) ans.push_back(it.first);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    vector<string> ans = sol.findRepeatedDnaSequences(s);
    for (auto& it : ans) {
        cout << it << endl;
    }



    cin >> c;
}
