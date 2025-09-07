// saw answer :  생각보다 Intuitive 하게 풀리네...
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
    int earliestFinishTime(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        int ans = INT_MAX;
        // take land first

        int n = a.size();
        int minEnd = INT_MAX;
        for (int i = 0; i < n; i++) {
            minEnd = min(minEnd, a[i] + b[i]);
        }
        int m = c.size();

        for (int i = 0; i < m; i++) {
            ans = min(ans, d[i] + max(minEnd, c[i]));
        }

        // take water first;
        minEnd = INT_MAX;
        for (int i = 0; i < m; i++) {
            minEnd = min(minEnd, c[i] + d[i]);
        }

        for (int i = 0; i < n; i++) {
            ans = min(ans, b[i] + max(minEnd, a[i]));
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> keyName = { "daniel", "daniel", "daniel", "luis", "luis", "luis", "luis" };
    vector<string> keyTime = { "10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00" };

    vector<string> ans = sol.alertNames(keyName, keyTime);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}