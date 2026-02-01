// ok : using vector and map
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
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int l = s.size();
        vector<int> v(l, 1);
        unordered_map<int, string> m;

        for (int i = 0; i < indices.size(); ++i) {
            if (s.compare(indices[i], sources[i].size(), sources[i]) == 0) {
                for (int j = indices[i]; j < indices[i] + sources[i].size(); ++j) {
                    v[j] = 0;
                }

                m[indices[i]] = targets[i];
            }
        }

        string ans;
        for (int i = 0; i < l; ++i) {
            if (v[i] == 1) {
                ans.push_back(s[i]);
            }
            else {
                if (m.find(i) != m.end()) {
                    ans.append(m[i]);
                }
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "abcd";
    vector<int> indices = { 0, 2 };
    vector<string> sources = { "ab", "cd" };
    vector<string> targets = { "eee", "ffff" };

    cout << sol.findReplaceString(s, indices, sources, targets);


    cin >> c;
}
