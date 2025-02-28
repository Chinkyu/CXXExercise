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
    string getHappyString(int n, int k) {
        int sz = 3 * (1 << (n - 1));
        if (k > sz) return "";
        auto [q, r] = div(k - 1, 1 << (n - 1));// k-1
        string s(n, ' ');
        s[0] = 'a' + q;
        bitset<9> bin(r);
        array<char, 2> xx[3] = { {'b', 'c'}, {'a', 'c'}, {'a', 'b'} };
        for (int i = n - 2; i >= 0; i--) {
            char idx = s[n - 2 - i] - 'a';
            s[n - 1 - i] = (bin[i]) ? xx[idx][1] : xx[idx][0];
        }
        return s;
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