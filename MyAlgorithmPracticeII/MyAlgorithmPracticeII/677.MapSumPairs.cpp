// easy
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

class MapSum {
public:
    map<string, int> m;
    MapSum() {
        m.clear();
    }

    void insert(string key, int val) {
        m[key] = val;
    }

    int sum(string prefix) {

        int ans = 0;
        for (auto& it : m) {
            if (it.first.compare(0, prefix.size(), prefix) == 0) {
                ans += it.second;
            }
        }

        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main() {
    char c;
    Solution sol;
    vector<string> world = { "a","banana","app","appl","ap","apply","apple" };

    cout << sol.longestWord(world);

    cin >> c;
}