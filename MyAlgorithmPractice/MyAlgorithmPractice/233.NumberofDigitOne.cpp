// ¥‰∫√¿Ω... : sliding windows
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

class Solution {
public:
    int countDigitOne(int n) {
        int ret = 0;
        for (long long int i = 1; i <= n; i *= (long long int)10) {
            int a = n / i;
            int b = n % i;
            int x = a % 10;
            if (x == 1) {
                ret += (a / 10) * i + (b + 1);
            }
            else if (x == 0) {
                ret += (a / 10) * i;
            }
            else {
                ret += (a / 10 + 1) * i;
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    char c;

    vector<vector<char>> mat =
    {
            {'a', 'b'},
            {'c', 'd'}
    };

    vector<string> words = { "ab", "cb", "ad", "bd", "ac", "ca", "da", "bc", "db", "adcb", "dabc", "abb", "acb" };
    //vector<string> words = { "ac", "ca", "db" };


    vector<string> ans = sol.findWords(mat, words);
    for (auto it : ans) {
        cout << it.c_str() << endl;
    }

    cin >> c;
}
