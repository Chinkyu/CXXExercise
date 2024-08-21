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
    int numberOfArithmeticSlices(vector<int>& nums) {
        long long n = nums.size();
        if (n <= 2) return 0;

        long long ans = 0;
        unordered_map<long long, long long> dp[n + 1];
        for (long long i = 1; i < n; i++) {
            for (long long j = 0; j < i; j++) {
                long long cnt = 1;
                long long diff = (long long)nums[i] - (long long)nums[j];

                // agr diff ke sath ek length alredy present hai to
                if (dp[j].count(diff)) {
                    cnt = dp[j][diff];
                    dp[i][diff] += cnt;
                    ans += cnt;
                }

                dp[i][diff] += 1;  // 1 + to add curr element
            }
        }
        return ans;

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
