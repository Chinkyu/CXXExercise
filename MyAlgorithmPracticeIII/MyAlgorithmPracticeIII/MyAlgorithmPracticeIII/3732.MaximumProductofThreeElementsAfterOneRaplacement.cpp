// ok : follow with hint : product of two largest value and 100000
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

// The answer is the product of the two largest values in nums and 105.

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        // find max two nums 

        vector<int> mNums;

        for (auto& it : nums) {
            mNums.push_back(abs(it));
        }

        sort(mNums.begin(), mNums.end());
        int l = mNums.size();

        long long ans = mNums[l - 1] * (long long)mNums[l - 2];

        ans *= 100000;

        return ans;
    }
};

int main() {
    char c;
    Codec sol;

    TreeNode* root = new TreeNode(2);

    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    string s = sol.serialize(root);

    TreeNode* r1 = sol.deserialize(s);


    cin >> c;
}
