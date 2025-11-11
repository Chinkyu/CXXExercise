// easy : any direction is ok 
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
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {

        int ans = 0;

        // row
        int direction = (homePos[0] - startPos[0] > 0) ? 1 : -1;
        for (int i = startPos[0]; i != homePos[0]; i += direction) {
            ans += rowCosts[i];
        }
        // remove first and add last
        ans -= rowCosts[startPos[0]];
        ans += rowCosts[homePos[0]];

        // column
        direction = (homePos[1] - startPos[1] > 0) ? 1 : -1;
        for (int i = startPos[1]; i != homePos[1]; i += direction) {
            ans += colCosts[i];
        }
        // remove first and add last
        ans -= colCosts[startPos[1]];
        ans += colCosts[homePos[1]];

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> asteroids = {5, 10, -5};
    vector<int> starPos = {1, 0};
    vector<int> homePos = {2, 3};
    vector<int> rowCosts = {5, 4, 3};
    vector<int> colCosts = { 8, 2, 6, 7 };

    cout << sol.minCost(starPos, homePos, rowCosts, colCosts);


    //cout << "Test  application";

    cin >> c;
}
