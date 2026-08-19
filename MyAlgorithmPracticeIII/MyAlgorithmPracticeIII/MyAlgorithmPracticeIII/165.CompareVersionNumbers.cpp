// ok. 
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
    int compareVersion(string version1, string version2) {

        stringstream v1(version1), v2(version2);

        string t1= "0", t2 = "0";

        bool v1s = static_cast<bool>(getline(v1, t1, '.'));
        bool v2s = static_cast<bool>(getline(v2, t2, '.'));

        while (v1s ||v2s) {

            int vn1 = stoi(t1);
            int vn2 = stoi(t2);

            if (vn1 > vn2) {
                return 1;
            }
            else if (vn1 < vn2) {
                return -1;
            }

            t1 = "0";
            t2 = "0";
            v1s = static_cast<bool>(getline(v1, t1, '.'));
            v2s = static_cast<bool>(getline(v2, t2, '.'));
        }

        return 0;
    }
};

int main() {
    char c;
    //vector<vector<int>> n = { { -2, -2, 1, 1},{2, 2, 4, 6} };
    vector<vector<int>> n = { { 1, 1, 5, 5} };

    Solution sol;

    cout << sol.compareVersion("1.0.1", "1");

    cin >> c;
}
