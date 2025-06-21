// see solution
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
    int findSubstringInWraproundString(string p) {
        int ans = 1, prev_ans = 1;
        vector<int> arr(26, 0);
        arr[p[0] - 'a'] = 1;
        for (int i = 1; i < p.size(); i++) {
            if ((p[i - 1] - 'a' + 1) % 26 == p[i] - 'a') // Checking for continuation
                prev_ans++;
            else
                prev_ans = 1;
            if (arr[p[i] - 'a'] < prev_ans) {
                ans += prev_ans - arr[p[i] - 'a'];
                arr[p[i] - 'a'] = prev_ans;
            }
        }
        return ans;
    }
};

int main() {
    char c;
    AuthenticationManager sol(5);

    sol.renew("aaa", 1);
    sol.generate("aaa", 2);
    cout << sol.countUnexpiredTokens(6);

    sol.generate("bbb", 7);
    sol.renew("aaa", 8);
    sol.renew("aaa", 10);
    cout << sol.countUnexpiredTokens(15);




    cin >> c;
}