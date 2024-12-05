//  tricky :  tricky in memoization 
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
    int traverse(vector<vector<int>>& matrix, vector<vector<int>>& memo, int l, int c, int ac) {

        if (l >= matrix.size() - 1) {
            return ac + matrix[l][c];
        }

        if (memo[l][c] != INT_MAX) return memo[l][c] + ac;

        int tmin = INT_MAX;
        if (0 <= c - 1) {
            tmin = min(tmin, traverse(matrix, memo, l + 1, c - 1, ac + matrix[l][c]));
        }

        // c
        tmin = min(tmin, traverse(matrix, memo, l + 1, c, ac + matrix[l][c]));


        if (c + 1 < matrix[0].size()) {
            tmin = min(tmin, traverse(matrix, memo, l + 1, c + 1, ac + matrix[l][c]));
        }

        if (memo[l][c] > tmin - ac) memo[l][c] = tmin - ac;
        return tmin;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int l = matrix.size();
        vector < vector<int>> memo(l, vector<int>(l, INT_MAX));

        for (int i = 0; i < matrix[0].size(); ++i) {
            ans = min(ans, traverse(matrix, memo,  0, i, 0));
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> matrix = { {100, -42, -46, -41}, {31, 97, 10, -10}, {-58, -51, 82, 89}, {51, 81, 69, -51} };
    //{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};

    cout << sol.minFallingPathSum(matrix);

    cin >> c;
}