// ¥‰∫√¿Ω : 

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
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            cnt++;
        }
        return (left << cnt);
    }
};

int main() {
    char c;
    Solution sol;
    string s = "abcacb";
    string p = "ab";
    vector<int> removable = { 3, 1, 0 };

    cout << sol.maximumRemovals(s, p, removable);

    cin >> c;
}