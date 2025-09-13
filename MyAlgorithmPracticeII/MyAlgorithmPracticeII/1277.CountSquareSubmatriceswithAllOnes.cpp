// ok... :
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
    int countSquares(vector<vector<int>>& matrix) {
        int l = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> cm(l + 1, vector<int>(m + 1, 0));

        for (int i = 1; i < l + 1; ++i) {
            for (int j = 1; j < m + 1; ++j) {
                cm[i][j] = cm[i - 1][j] + cm[i][j - 1] - cm[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        int ans = 0;
        for (int k = 1; k <= min(l, m); ++k) {
            for (int i = 0; i < l + 1 - k; ++i) {
                for (int j = 0; j < m + 1 - k; ++j) {
                    int num = cm[i + k][j + k] - cm[i][j + k] - cm[i + k][j] + cm[i][j];

                    if (num == k * k) ans++;

                }
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> matrix =
    {
        {0, 1, 1, 1} ,
        {1, 1, 1, 1},
        {0, 1, 1, 1 }
    };

    cout << sol.countSquares(matrix);

    cin >> c;
}