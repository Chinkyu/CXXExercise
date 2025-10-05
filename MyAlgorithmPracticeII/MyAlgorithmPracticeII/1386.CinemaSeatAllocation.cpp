// tricky : momory limit -> modify -> debug tricky
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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

// memory limit
class _Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        vector<uint16_t> v(n + 1, 0xFFFF);

        for (auto& it : reservedSeats) {
            v[it[0]] = v[it[0]] ^ (0x01 << it[1]);
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int score = 0;
            if ((v[i] & 0x3C0) == 0x3C0) score++;
            if ((v[i] & 0x0F0) == 0x0F0) score++;
            if ((v[i] & 0x03C) == 0x03C) score++;
            if (score >= 3) {
                ans += 2;
            }
            else if(score > 0) {
                ans++;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {


        sort(reservedSeats.begin(), reservedSeats.end());


        int line = 0;
        int l = reservedSeats.size();
        int idx = 0;
        int ans = 0;
        while (line <= n && idx < l) {
            int cline = reservedSeats[idx][0];

            if (line < cline) {
                ans += (cline - line - 1) * 2;
                line = cline;
            }

            uint16_t pattern = 0xFFFF;
            while (idx < l && reservedSeats[idx][0] == cline) {
                pattern = pattern ^ (0x01 << reservedSeats[idx][1]);
                idx++;
            }

            int score = 0;
            if ((pattern & 0x3C0) == 0x3C0) score++;
            if ((pattern & 0x0F0) == 0x0F0) score++;
            if ((pattern & 0x03C) == 0x03C) score++;
            if (score >= 3) {
               ans += 2;
            }
            else if (score > 0) {
                ans++;
            }
        }

        if (line <= n) {
            ans += (n - line) * 2;
        }

        return ans;
    }
};


int main() {
    Solution sol;
    char c;
    //vector<vector<int>> reservedSeats = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    //vector<vector<int>> reservedSeats = { {4, 3}, {1, 4}, {4, 6}, {1, 7} };
    //vector<vector<int>> reservedSeats = { {2, 1}, {1, 8}, {2, 6} };
    vector<vector<int>> reservedSeats = { {2, 3}};

    cout << sol.maxNumberOfFamilies(3, reservedSeats);

    cin >> c;
}
