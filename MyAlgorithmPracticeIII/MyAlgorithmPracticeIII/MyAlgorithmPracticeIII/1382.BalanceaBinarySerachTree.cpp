// Ok..
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
#include <chrono>
#include <iterator>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};


class Solution {
public:

    void traverse(vector<int>& v, TreeNode* r) {

        if (r->left != nullptr) {
            traverse(v, r->left);
        }

        if (r->right != nullptr) {
            traverse(v, r->right);
        }

        v.push_back(r->val);
        // delete r;  이상하게 delete 넣으며 
    }

    TreeNode* buildBTS(vector<int>& v, int st, int ed) {

        if (st > ed) return nullptr;

        int m = st + (ed - st) / 2;
        TreeNode* r = new TreeNode(v[m]);

        r->left = buildBTS(v, st, m - 1);
        r->right = buildBTS(v, m + 1, ed);

        return r;
    }



    TreeNode* balanceBST(TreeNode* root) {

        vector<int> v;
        traverse(v, root);

        sort(v.begin(), v.end());

        TreeNode * r = buildBTS(v, 0, v.size() - 1);

        return r;

    }
};

int main() {
    char c;
    Solution sol;

    vector<int> v = { 1, 2, 3, 4 };

    sol.buildBTS(v, 0, v.size() - 1);

//    cout << sol.angleClock(1, 57);


    cin >> c;
}
