// too easy.. 
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

using namespace std;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        set<double> st;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                double db = (double)i / j;
                if (st.find(db) == st.end()) {
                    st.insert(db);
                    string s = to_string(i) + "/" + to_string(j);
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;


    vector<string> ans = sol.simplifiedFractions(4);

    for (auto& it : ans) {
        cout << it << " ";
    }


    cin >> c;
}
