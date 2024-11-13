//  easy : Getting combination function is tricky... 
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
    void generateCombinations(int n, int k, int current, int bits, vector<int>& result) {
        if (k == 0) {
            result.push_back(bits);
            //cout << bits << endl;
            return;
        }

        if (current == n) {
            return;
        }

        // Include the current bit
        generateCombinations(n, k - 1, current + 1, bits | (1 << current), result);

        // Exclude the current bit
        generateCombinations(n, k, current + 1, bits, result);
    }


    int maximumRows(vector<vector<int>>& matrix, int numSelect) {

        int lr = matrix.size();
        int lc = matrix[0].size();

        vector<int> rVal;
        for (int i = 0; i < lr; ++i) {
            int v = 0;
            for (int j = 0; j < lc; ++j) {
                v |= (matrix[i][j] << j);
                //v = v << 1;
            }
            rVal.push_back(v);
        }

        vector<int> combination;
        generateCombinations(lc, numSelect, 0, 0, combination);

        int ans = 0;
        for (auto& it : combination) {
            int covered_row = 0;
            for (auto jt : rVal) {
                if(jt == 0 || ((jt & it) == jt)) covered_row++;
            }

            ans = max(ans, covered_row);
        }

        return ans;
    }
};


int main() {
    char c;
    Solution sol;

    vector<vector<int>> matrix =
    { {1}, {0} };
        //{{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 0, 1}};

    cout << sol.maximumRows(matrix, 1);

    cin >> c;
}