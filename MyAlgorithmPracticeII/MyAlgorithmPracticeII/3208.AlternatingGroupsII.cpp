//  Ok : tricky because of rounded
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
#include <set>
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int l = colors.size();
        vector<bool> di;

        for (int i = 1; i < l; ++i) {
            di.push_back(colors[i - 1] != colors[i]);
        }
        di.push_back(colors[l - 1] != colors[0]);

        // sliding window 
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < di.size(); ++i) {
            if (di[i] == true) {
                cnt++;
            }
            else {
                cnt = 0;
            }
            if (cnt >= k - 1) ans++;
        }

        for (int i = 0; i < k - 2; ++i) {
            if (di[i] == true) {
                cnt++;
            }
            else {
                cnt = 0;
            }
            if (cnt >= k - 1) ans++;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<int> colors = { 0,1,0,1,0 };
    vector<int> colors = { 0,1,0,0,1,0,1 };

    cout << sol.numberOfAlternatingGroups(colors, 6);

    //for (auto it : ans) {
    //    cout << it << " ";
    //}

    cin >> c;
}