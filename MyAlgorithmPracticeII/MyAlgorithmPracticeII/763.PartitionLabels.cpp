// ok : sliding window direct to mapping vector.. 
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
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int l = s.size();
        unordered_map<char, pair<int, int>> um;

        for (int i = 0; i < s.size(); ++i) {
            if (um.find(s[i]) == um.end()) {
                um[s[i]].first = i;
                um[s[i]].second = -1;
            }
            else { // already have start
                um[s[i]].second = i;
            }
        }

        vector<int> v(l, 0);
        for (auto& it : um) {
            if (it.second.second == -1) continue;
            v[it.second.first]++;
            v[it.second.second]--;
        }

        // accumulate
        for (int i = 1; i < l; ++i) {
            v[i] = v[i - 1] + v[i];
        }

        vector<int> ans;
        int pre = -1;
        // count zero become answer
        for (int i = 0; i < l; ++i) {
            if (v[i] == 0) {
                ans.push_back(i - pre);
                pre = i;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "eccbbbbdec";


    vector<int> ans = sol.partitionLabels(s);
    for (auto& it : ans) {
        cout << it << " ";
    }


    cin >> c;
}