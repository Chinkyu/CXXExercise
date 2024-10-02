// easy : 
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

class SubrectangleQueries {
public:
    vector<vector<int>> rectangle_;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rectangle_ = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {

        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                rectangle_[i][j] = newValue;
            }
        }

    }

    int getValue(int row, int col) {
        return rectangle_[row][col];
    }
};

int main() {
    char c;
    Solution sol;
    //vector<string> arr = { "cha", "r", "act", "ers" };
    vector<string> arr = {
        "abcdefghijklm", "bcdefghijklmn", "cdefghijklmno", "defghijklmnop", "efghijklmnopq", "fghijklmnopqr", "ghijklmnopqrs", "hijklmnopqrst", "ijklmnopqrstu", "jklmnopqrstuv", "klmnopqrstuvw", "lmnopqrstuvwx", "mnopqrstuvwxy", "nopqrstuvwxyz", "opqrstuvwxyza", "pqrstuvwxyzab"
    };
    cout << sol.maxLength(arr);
    cin >> c;
}