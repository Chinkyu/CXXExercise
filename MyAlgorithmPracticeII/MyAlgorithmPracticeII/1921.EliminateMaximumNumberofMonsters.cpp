// ok : remember previous way
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
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int l = dist.size();
        vector<double> td(l, 0);

        for (int i = 0; i < l; ++i) {
            td[i] = (double)dist[i] / speed[i];
        }

        sort(td.begin(), td.end());

        for (int i = 0; i < l; ++i) {
            if (td[i] <= i) {
                return i;
            }
        }

        return l;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> dist = { 3, 2, 4 };
    vector<int> speed = { 5, 3, 2 };

    cout << sol.eliminateMaximum( dist, speed);

    cin >> c;
}