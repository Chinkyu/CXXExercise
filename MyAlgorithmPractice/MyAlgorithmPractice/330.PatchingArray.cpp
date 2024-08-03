// ¥‰∫√¿Ω : dp memoization 
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
    int minPatches(vector<int>& nums, int n) {
        long long count = 0;
        long long sum = 0;
        long long i = 0;
        while (sum < n) {
            if (i < nums.size() && nums[i] <= (sum + 1)) {
                sum += nums[i++];
            }
            else {
                count++;
                sum += (sum + 1);
            }
        }
        return count;
    }
};

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
