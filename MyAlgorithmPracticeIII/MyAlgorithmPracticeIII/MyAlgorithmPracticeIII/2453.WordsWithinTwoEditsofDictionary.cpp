// Ok
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
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int l = queries[0].size();
        vector<string> ans;

        for (auto& it : queries) {
            for (auto& jt : dictionary) {

                int dcount = 0;
                for (int i = 0; i < l; ++i) {
                    if (it[i] != jt[i]) {
                        dcount++;
                    }
                }

                if (dcount <= 2) {
                    ans.push_back(it);
                    break;
                }
            }
        }
    
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "aabcabcab"; // "aaaa"; // "aababcaab";

    cout << sol.maxFreq(s, 2, 2, 3);


    cin >> c;
}
