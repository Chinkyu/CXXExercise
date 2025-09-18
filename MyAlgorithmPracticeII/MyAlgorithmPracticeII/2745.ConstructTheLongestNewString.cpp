// refer answer : OK 
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

/*

    There is no requirement to match strings of the "AB" type with any specific string. These strings can be placed anywhere within the overall string as "ABABABAB.." .Hence we take all z type of strings
    Combine "AA" and "BB" strings as "AABB" pairs.Thus,for the total length, we choose the minimum number of occurrences between the two patterns and multiply it by 4, as the resulting composite string will have the pattern "AABB".
    If there are remaining "AA" or "BB" strings, append a single occurrence at the end of the string. For example, with x=2, y=1, and z=0, the resulting string would be "AABBA".

*/



class Solution {
public:
    int longestString(int x, int y, int z) {

        int ans = 0;

        ans += z * 2;

        if (x == y) {
            ans += x * 4;
        }
        else if (x > y) {
            ans += y * 4 + 2;
        } else{ // x < y
            ans += x * 4 + 2;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> points = { {3, 3}, {5, -1}, {-2, 4} };

    vector<vector<int>> ans = sol.kClosest(points, 2);

    for (auto& it : ans) {
        cout << it[0] << " " << it[1] << endl;
    }

    cin >> c;
}