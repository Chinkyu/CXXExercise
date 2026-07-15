// ok : set, vector, map.. 
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
    string findCommonResponse(vector<vector<string>>& responses) {
        int l = responses.size();
        vector<set<string>> vs(l);

        for (int i = 0; i < responses.size(); ++i) {
            for (auto& jt : responses[i]) {
                vs[i].insert(jt);
            }
        }

        unordered_map<string, int> m;
        for (int i = 0; i < vs.size(); ++i) {
            for (auto& jt : vs[i]) {
                m[jt]++;
            }
        }

        vector<string> ans;
        int cnt = 0;
        for (auto& it : m) {
            if (it.second > cnt) {
                ans.clear();
                ans.push_back(it.first);
                cnt = it.second;
            }
            else if (it.second == cnt) {
                ans.push_back(it.first);
            }
        }

        sort(ans.begin(), ans.end());

        return ans[0];

    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<string>> responses = {{"good", "ok", "good", "ok"}, {"ok", "bad", "good", "ok", "ok"}, {"good"}, {"bad"}};

    cout << sol.findCommonResponse(responses);

    cin >> c;
}
