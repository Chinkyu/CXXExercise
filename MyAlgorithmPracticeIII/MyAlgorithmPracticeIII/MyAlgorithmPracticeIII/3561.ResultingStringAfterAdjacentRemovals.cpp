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
#include <bit>

using namespace std;

class Solution {
public:
    string resultingString(string s) {
        string ans = s;

        for (int i = 1; i < ans.size(); ++i) {
            if ((abs(ans[i - 1] - ans[i]) == 1) || (abs(ans[i - 1] - ans[i]) == 25)) {
                ans.erase(ans.begin() + i - 1);  // remove two... if remove shift to left 
                ans.erase(ans.begin() + i - 1);
                if (i >= 2) {
                    i -= 2;  // 2 can be 0
                }
                else {
                    i = 0;
                }
            }
        }

        // check last

        // while (ans.size() >= 2 && 
        //     ((abs(ans[ans.size() - 1] - ans[0]) == 1) || ((abs(ans[ans.size() - 1] - ans[0]) == 25)))) {
        //     ans.erase(ans.begin());
        //     ans.erase(ans.end() - 1);
        // }

        return ans;
    }
};

int main() {
    char c;

    Solution sol;

    cout << sol.resultingString("gflkii");

    cin >> c;
}
