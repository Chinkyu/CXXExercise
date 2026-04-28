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

class DataStream {
public:
    int gvalue = 0;
    int gk = 0;
    int cnt = 0;
    DataStream(int value, int k) {
        gvalue = value;
        gk = k;
    }

    bool consec(int num) {
        if (num == gvalue) {
            cnt++;
            if (cnt >= gk) return true;
        }
        else {
            cnt = 0;
        }
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

int main() {
    char c;
    Solution sol;

    //vector<vector<int>> grid = { {6, 7}, {5, 8} };
    //vector<vector<int>> grid = { {2, 7, 5} };
    vector<vector<int>> grid = { {26, 24, 3}, {2, 22, 17 } };

    cout << sol.minCost(grid);

    cin >> c;
}
