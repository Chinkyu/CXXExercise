// ok : 그냥 되네... 타임 아웃 될것 같은데...  Can improve logic to find min index 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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

    int min_idx(string& num, int st, int ed) {
        int tmin = num[st];
        int tidx = st;
        for (int i = st; i <= ed; ++i) {
            if (num[i] < tmin) {
                tmin = num[i];
                tidx = i;
            }
        }
        return tidx;
    }

    string removeKdigits(string num, int k) {
        int l = num.size();
        
        if (k >= l) return "0";

        int pre_idx = -1;
        string ans;
        for (int i = k; i < l; ++i) {
            pre_idx = min_idx(num, pre_idx + 1, i);
            ans.push_back(num[pre_idx]);
        }
        
        while (ans.size() > 1 && ans[0] == '0') ans.erase(ans.begin());

        return ans;
    }
};

int main() {
    Solution sol;
    char c;

    string num = "10";

    cout << sol.removeKdigits(num, 1);

    cin >> c;
}
