//  ¥‰∫√¿Ω : Making map.........  does it make sense??  
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
#include <functional>

using namespace std;

// Making map........ ????
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        //ans[x] = shortest substring that is x in decimal form 
        map<int, vector<int>> ans;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            //fix the left of the substring 
            int cur = 0;
            //go right until r-l+1 > 30 or end of string 
            for (int j = 0; j < min(31, n - i); ++j) {
                //left shift count, add current bit
                cur <<= 1;
                cur += (int)(s[i + j] - '0');

                if (ans.find(cur) == ans.end()) {
                    ans[cur] = { i, i + j };
                }
                else {
                    if (j < ans[cur][1] - ans[cur][0]) {
                        //modify answer if current is shorter
                        ans[cur] = { i, i + j };
                    }
                }
            }
        }

        vector<vector<int>> ret;
        for (auto u : queries) {
            int z = u[1] ^ u[0];
            //process queries 
            if (ans.find(z) != ans.end()) {
                ret.push_back({ ans[z] });
            }
            else {
                ret.push_back({ -1, -1 });
            }
        }
        return ret;
    }
};

// timout
class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;

        for (auto& it : queries) {
            int v = it[0] ^ it[1];

            string vstr; // = bitset<64>(v).to_string();
            {
                //while (vstr[0] == '0') vstr.erase(0, 1);
                //if (vstr.size() == 0) vstr = "0";
            }

            while (v != 0) {
                if ((v & 0x01) == 0x01) {
                    vstr = "1" + vstr;
                }
                else {
                    vstr = "0" + vstr;
                }
                v = v >> 1;
            }
            if (vstr.size() == 0) vstr = "0";


            int found = s.find(vstr, 0);
            if (found == string::npos) {
                ans.push_back({ -1, -1 });
            }
            else {
                ans.push_back({ found, found + (int)vstr.size() - 1});
            }
        }
        
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "111010110";
    vector<vector<int>> queries = { {3, 3} };

    vector<vector<int>> ans = sol.substringXorQueries(s, queries);

    for (auto it : ans) {
        cout << it[0] << "," << it[1] << " ";
    }

    cin >> c;
}