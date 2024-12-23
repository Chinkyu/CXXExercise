// skip : looks OK... 
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
    vector<int> wv, w_;
    map<int, int> m;
    int sum = 0;
    Solution(vector<int>& w) {
        w_ = w;
        wv.push_back(w[0]);
        sum += w[0];
        m[w[0]] = 0;
        for (int i = 1; i < w.size(); ++i) {
            wv.push_back(w[i] + wv[i - 1]);
            m[wv[i]] = i;
            sum += w[i];
        }
    }

    int pickIndex() {
        int r = rand();
        int v = r * ((double)sum / RAND_MAX);
        // handle before - golden
        auto it = m.lower_bound(v);
        if (it == m.end()) --it;

        return it->second;
    }
};


int main() {
    char c;
    vector<int> v = { 3, 14, 1, 7 };
    Solution sol(v);

    cout << sol.pickIndex() << endl;
    cout << sol.pickIndex() << endl;
    cout << sol.pickIndex() << endl;
    cout << sol.pickIndex() << endl;
    cout << sol.pickIndex() << endl;
    cout << sol.pickIndex() << endl;
    cout << sol.pickIndex() << endl;
    cout << sol.pickIndex() << endl;
    cout << sol.pickIndex() << endl;
    cout << sol.pickIndex() << endl;

    cin >> c;
}
