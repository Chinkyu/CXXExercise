// understand wrongly - check answer.. 

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
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        map<int, double> m;
        for (int i = 0; i < pos.size(); i++) m[-pos[i]] = (double)(target - pos[i]) / speed[i];
        int res = 0; double cur = 0;
        for (auto it : m) if (it.second > cur) cur = it.second, res++;
        return res;
    }
};

class _Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int l = position.size();
        vector<pair<int, int>> v;

        for (int i = 0; i < l; ++i) {
            v.push_back({ position[i], speed[i] });
        }

        sort(v.begin(), v.end(), [](pair<int, int>& l, pair<int, int>& r) { return l.first < r.first;});

        int ans = 0;
        for (int i = l - 1; i >= 0; --i) {
            int nxt = v[i].first + v[i].second;
            if (i < l - 1) {
                if (nxt > position[i + 1]) {
                    nxt = position[i + 1];
                }
            }
            position[i] = nxt;

            if (nxt >= target) ans++;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> position = { 10,8,0,5,3 };
    vector<int> speed = { 2,4,1,1,3 };

    cout << sol.carFleet(12, position, speed);

    cin >> c;
}