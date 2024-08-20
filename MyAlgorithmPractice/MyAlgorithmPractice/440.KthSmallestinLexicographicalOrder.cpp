// ¥‰∫√¿Ω : binary logic
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
    int findKthNumber(long n, int k) {
        auto getGap = [&n](long a, long b) {
            long gap = 0;
            while (a <= n) {
                gap += min(n + 1, b) - a;
                a *= 10;
                b *= 10;
            }
            return gap;
            };

        long currNum = 1;

        for (int i = 1; i < k;) {
            long gap = getGap(currNum, currNum + 1);
            if (i + gap <= k) {
                i += gap;
                ++currNum;
            }
            else {
                ++i;
                currNum *= 10;
            }
        }

        return currNum;
    }
};

    string getMaxKey() {
        return max_key;
    }

    string getMinKey() {
        return min_key;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main() {
    Codec sol;
    char c;

    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->right->left = new TreeNode(4);
    r->right->right = new TreeNode(5);


    string ans = sol.serialize(r);
    cout << ans;

    TreeNode* root = sol.deserialize(ans);

    cin >> c;
}
