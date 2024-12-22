// tricky : debugging 
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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = get_height(root), w = get_width(root);
        vector<vector<string>> ans(h, vector<string>(w, ""));
        helper(ans, root, 0, 0, w - 1);
        return ans;
    }
private:
    int get_height(TreeNode* p) {
        if (!p) return 0;
        int left = get_height(p->left), right = get_height(p->right);
        return max(left, right) + 1;
    }
    // width is the max(left, right)*2+1
    int get_width(TreeNode* p) {
        if (!p) return 0;
        int left = get_width(p->left), right = get_width(p->right);
        return max(left, right) * 2 + 1;
    }
    // always put the value in the middle of the range.
    void helper(vector<vector<string>>& ans, TreeNode* p, int level, int l, int r) {
        if (!p) return;
        int mid = l + (r - l) / 2;
        ans[level][mid] = to_string(p->val);
        helper(ans, p->left, level + 1, l, mid - 1);
        helper(ans, p->right, level + 1, mid + 1, r);
    }
};

int main() {
    char c;
    Solution sol;
    string equation = "-x=-1"; // "x+5-3+x=6+x-2"; //"2x=x"; 

    cout << sol.solveEquation(equation);

    cin >> c;
}