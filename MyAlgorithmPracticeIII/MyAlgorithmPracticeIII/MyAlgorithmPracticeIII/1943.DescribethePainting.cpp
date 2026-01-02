// tricky in debugging 

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

using namespace std;

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<int>> sw;

        for (auto& it : segments) {
            sw.push_back({ it[0], it[2] });
            sw.push_back({ it[1], it[2] * -1 });
        }

        sort(sw.begin(), sw.end());

        vector<vector<long long>> ans;

        long long precolor = 0, color = 0;
        int preidx = 1;
        for (int i = 0; i < sw.size(); ++i) {
            color += sw[i][1];
            // if next show same 
            if (i + 1 < sw.size() && sw[i][0] == sw[i+1][0]) {
                continue;
            }

            // 여기 같은 color check 안하는것는 좀 이상함.... 
            //if (color != precolor /* && preidx != sw[i][0] && precolor != 0 */) {
                if (preidx != sw[i][0] && precolor != 0) {
                    ans.push_back({ preidx, sw[i][0], precolor });
                }
                
                precolor = color;
                preidx = sw[i][0];
            //}
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> segments = {{1, 4, 5}, {4, 7, 7}, {1, 7, 9}};

    vector<vector<long long>> ans =  sol.splitPainting(segments);
    for (auto& it : ans) {
        cout << it[0] << " " << it[1] << " " << it[2] << endl;
    }

    cin >> c;
}
