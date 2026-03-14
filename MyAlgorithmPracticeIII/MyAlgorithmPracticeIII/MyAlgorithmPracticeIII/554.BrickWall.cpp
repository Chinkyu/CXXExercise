// ok : count number can solve problem 
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
#include <random>
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int l = wall.size();
        unordered_map<int, int> m;
        int length = 0;
        for (int i = 0; i < l; ++i) {
            long long d = 0;
            for (auto& it : wall[i]) {
                d += it;
                m[d]++;
            }
            length = d;
        }

        int t_max = 0;
        for (auto& it : m) {
            if (it.first != length) {
                t_max = max(t_max, it.second);
            }
        }

        return l - t_max;
    }
};


int main() {
    char c;
    Solution sol;

    vector<vector<int>> wall =
        {{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2}, {2, 4}, {3, 1, 2}, {1, 3, 1, 1}};

    cout << sol.leastBricks(wall);

    cin >> c;
}
