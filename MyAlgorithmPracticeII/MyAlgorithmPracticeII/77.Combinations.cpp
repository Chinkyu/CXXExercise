// ok : simple... have more margin to enhance 
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
    vector<vector<int>> ans;

    void traverse(vector<int>& v, int n, int ni, int k, int ki) {

        if (n + 1 < ni) return;
        if (k == ki) {
            ans.push_back(v);

            //for (auto& it : v) cout << it << " ";
            //cout << endl;

            return;
        }

        // use 
        v[ki] = ni;
        traverse(v, n, ni + 1, k, ki + 1);
        // not use
        traverse(v, n, ni + 1, k, ki);

    }

    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        int ni = 1, ki = 0;
        vector<int> v(k, 0);
        traverse(v, n, ni, k, ki);

        return ans;
    }
};

int main() {
    Solution sol;
    char c;

    sol.combine(4, 2);

    cin >> c;
}
