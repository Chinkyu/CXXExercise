// OK : tricky in duplication 
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

class Solution {
public:
    string customSortString(string order, string s) {

        vector<int> order_visit(order.size(), 0);
        unordered_map<char, int> m;

        for (int i = 0; i < order.size(); ++i) {
            m[order[i]] = i;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (m.find(s[i]) != m.end()) {
                order_visit[m[s[i]]]++;
                s[i] = '0';
            }
        }

        string ans = s;
        int v_idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (ans[i] != '0') continue;
            while (order_visit[v_idx] == 0) v_idx++;
            ans[i] = order[v_idx];
            if (order_visit[v_idx] == 0) {
                v_idx++;
            }
            else {
                order_visit[v_idx]--;
            }
        }

        return ans;

    }
};

int main() {
    char c;
    Solution sol;
    string order = "kqep";
    string s = "pekeq";
    
    cout << sol.customSortString(order, s);

    cin >> c;
}