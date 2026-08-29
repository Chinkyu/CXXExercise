// ok... int, long long....  takes long.. might have better ..
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
#include <numeric>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        long long ans = 0;
        int m = 1;

        long long div = dividend;
        long long dir = divisor;

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            m = -1;
        }

        div = abs(div);
        dir = abs(dir);


        if (dir == 1) {
            ans = div;
        }
        else {
            while (div >= dir) {
                div -= dir;
                ans++;
            }
        }

        if (m == -1) ans = -ans;

        if (ans > INT_MAX) ans = INT_MAX;
        if (ans < INT_MIN) ans = INT_MIN;

        return ans;
    }
};

int main() {
    char c;

    TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(-1);
    root->left->left = new TreeNode(-1);
    root->left->right = new TreeNode(-1);
    root->right = new TreeNode(-1);


    FindElements sol(root);

    cout << sol.find(1);

    cin >> c;
}
