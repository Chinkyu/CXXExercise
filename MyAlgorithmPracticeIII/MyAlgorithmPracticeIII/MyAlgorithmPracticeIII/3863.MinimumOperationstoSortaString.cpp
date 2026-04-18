// Very Low performance : there is better way 
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
    int minOperations(string s) {
        int l = s.size();
        string ss = s;

        sort(ss.begin(), ss.end());

        if(s == ss) return 0;
        if (s.size() == 2 && s != ss) return -1;

        //int ans = 0;
        //if (s[0] != ss[0]) ans++;    // left diff
        //if (s[l-1] != ss[l-1]) ans++;   // right diff
        //if ((s[0] == ss[l - 1])  && (s[l - 1] == ss[0])) ans++;   // left, right switch

        // lsoft, rsort   not match  ++
        int ans = 0, lans = 0, rans = 0;
        string ls = s, rs = s;
        if (ls != ss) {
            lans++;
            sort(ls.begin(), ls.end() - 1);
        }
        if (ls != ss) {
            lans++;
            sort(ls.begin() + 1, ls.end());
        }
        
        if (rs != ss) {
            rans++;
            sort(rs.begin() + 1, rs.end());
        }
        if (rs != ss) {
            rans++;
            sort(rs.begin(), rs.end() - 1);
        }
        
        ans = min(lans, rans);

        if (ans == 2 && ls != ss && rs != ss) {
            ans++;
        }

        //if (ls != ss && rs != ss) ans++;
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<vector<int>> buildings = {{1, 3}, {3, 2}, {3, 3}, {3, 5}, {5, 3}};
    string s = "dog";

    cout << sol.minOperations(s);

    cin >> c;
}
