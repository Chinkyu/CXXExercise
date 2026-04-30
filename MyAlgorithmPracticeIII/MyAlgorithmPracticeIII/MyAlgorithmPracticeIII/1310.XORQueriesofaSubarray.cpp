// ok : accumulate.. 
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
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int l = arr.size();

        vector<int> ac = { arr[0] };
        int acuxor = arr[0];
        for (int i = 1; i < l; ++i) {
            acuxor = acuxor ^ arr[i];
            ac.push_back(acuxor);
        }

        vector<int> ans;
        for (auto& it : queries) {
            int lval = (it[0] <= 0) ? 0 : ac[it[0] - 1];
            ans.push_back(ac[it[1]] ^ lval);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> arr = { 1,3,4,8 };
    vector<vector<int>> queries = {{0, 1}, { 1, 2 }, { 0, 3 }, { 3, 3 }};

    vector<int> ans = sol.xorQueries(arr, queries);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
