// Ok - easy 
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
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int l = word.size();
        unordered_map<string, int> m;

        for (int i = 0; i * k < l; ++i) {
            string substr = word.substr(i * k, k);
            m[substr]++;
        }

        int total = 0, max_cnt = 0;
        for (auto& it : m) {
            if (max_cnt < it.second) max_cnt = it.second;
            total += it.second;
        }
        return total - max_cnt;
    }
};

int main() {
    char c;
    Solution sol;
    string word = "leetcodeleet";

    cout << sol.minimumOperationsToMakeKPeriodic(word, 4);

    std::cin >> c;
}