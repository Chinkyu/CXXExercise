// ok : idea  : change row/colulm  and reverse 
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
#include <chrono>
#include <iterator>

using namespace std;

// change row, colulm  and reverse in row

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = matrix.size();

        for (int i = 0; i < l; ++i) {
            for (int j = i + 1; j < l; ++j) {  // only for upper right .. 
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < l; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};

int main() {
    char c;
    Solution sol;

    vector<string> garbage = { "G", "M" };
    vector<int> travel = { 1 };

    cout << sol.garbageCollection(garbage, travel);


    cin >> c;
}
