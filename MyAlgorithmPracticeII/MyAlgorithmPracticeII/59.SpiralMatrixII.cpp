//  ok : really brute force????
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));

        int dir = 1;// right
        int il = 0, ic = 0;
        for (int i = 1; i <= n * n; ++i) {
            v[il][ic] = i;

            // move
            switch (dir) {
            case 1: // right
                if (n <= ic + 1 || v[il][ic + 1] != 0 ) {
                    // go down
                    il++;
                    dir++;
                }
                else {
                    ic++;
                }
                break;
            case 2: // down
                if (n <= il + 1 || v[il + 1][ic] != 0) {
                    // go left
                    ic--;
                    dir++;
                }
                else {
                    il++;
                }
                break;
            case 3:  // left
                if (ic - 1 < 0 || v[il][ic- 1] != 0 ) {
                    // go up
                    il--;
                    dir++;
                } 
                else {
                    ic--;
                }
                break;
            case 4:  // up
                if (il - 1 < 0 || v[il - 1][ic] != 0) {
                    // go right
                    ic++;
                    dir = 1;
                }
                else {
                    il--;
                }
                break;
            }


        }

        return v;
    }
};


int main() {
    char c;
    Solution sol;

    vector<vector<int>> ans = sol.generateMatrix(3);

    for (auto& it : ans) {
        for (auto& jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }

    cin >> c;
}