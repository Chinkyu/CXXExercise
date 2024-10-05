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

class Solution {
public:
    int minFlips(string target) {
        int l = target.size();
        int ans = 0;

        int c = '0';
        for (int i = 0; i < l; ++i) {
            if (target[i] != c) {
                ans++;
                c = (c == '0') ? '1' : '0';
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    string target = "10111";
    cout << sol.minFlips(target);

    cin >> c;
}