// see answer : recursive -> timeout.. need memoization 
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
    int M = 1000000007;

    int findPaths(int m, int n, int N, int i, int j) {
        vector<std::vector<std::vector<int>>> memo(m, std::vector<std::vector<int>>(n, std::vector<int>(N + 1, -1)));
        //for (auto l : memo) for (auto sl : l) Arrays.fill(sl, -1);
        return findPaths(m, n, N, i, j, memo);
    }

    int findPaths(int m, int n, int N, int i, int j, vector<std::vector<std::vector<int>>> &memo) {
        if (i == m || j == n || i < 0 || j < 0) return 1;
        if (N == 0) return 0;
        if (memo[i][j][N] >= 0) return memo[i][j][N];
        memo[i][j][N] = (
            (findPaths(m, n, N - 1, i - 1, j, memo) + findPaths(m, n, N - 1, i + 1, j, memo)) % M +
            (findPaths(m, n, N - 1, i, j - 1, memo) + findPaths(m, n, N - 1, i, j + 1, memo)) % M
            ) % M;
        return memo[i][j][N];
    }

};


// recursive  timeout
class _Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (i == m || j == n || i < 0 || j < 0) return 1;
        if (N == 0) return 0;
        return findPaths(m, n, N - 1, i - 1, j)
            + findPaths(m, n, N - 1, i + 1, j)
            + findPaths(m, n, N - 1, i, j - 1)
            + findPaths(m, n, N - 1, i, j + 1);
    }
};

int main() {
    char c;
    //vector<vector<int>> n = { { -2, -2, 1, 1},{2, 2, 4, 6} };
    vector<vector<int>> n = { { 1, 1, 5, 5} };


    Solution sol(n);

    for (int i = 0; i < 5; ++i) {
        vector<int> ans = sol.pick();
        cout << ans[0] << " " << ans[1] << endl;
    }

    cin >> c;
}
