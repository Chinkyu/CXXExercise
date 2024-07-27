// Easy : debugging matter
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

class Codec {
public:
    static constexpr int NULL_NUM = INT_MAX;
    void readTree(TreeNode* p, vector<int>& vdata) {

        vdata.push_back(p->val);

        if (p->left != nullptr) readTree(p->left, vdata);
        else vdata.push_back(NULL_NUM);

        if (p->right != nullptr) readTree(p->right, vdata);
        else vdata.push_back(NULL_NUM);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int> vdata;

        if (root == nullptr) return "";
        readTree(root, vdata);

        string ans;
        if (vdata.size() == 0) return ans;
        ans += to_string(vdata[0]);
        for (auto& it : vdata) {
            ans.push_back(',');
            ans += to_string(it);
        }

        return ans;
    }

    void buildTree(TreeNode* p, vector<int>& vdata, int &idx) {

        if (vdata.size() <= idx) return;

        if (vdata[++idx] != NULL_NUM) {
            p->left = new TreeNode(vdata[idx]);
            buildTree(p->left, vdata, idx);
        }
        if (vdata[++idx] != NULL_NUM) {
            p->right = new TreeNode(vdata[idx]);
            buildTree(p->right, vdata, idx);
        }

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream input(data);
        vector<int> vdata;

        string token;
        while (getline(input, token, ',')) {
            if (token == "") continue;
            vdata.push_back(stoi(token));
        }

        TreeNode* ans = nullptr;
        int idx = 0;
        if (vdata.size() == 0) return ans;

        ans = new TreeNode(vdata[0]);
        buildTree(ans, vdata, ++idx);

        return ans;
    }
};

int main() {
    Codec sol;
    char c;

    TreeNode *r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    r->right->left = new TreeNode(4);
    r->right->right = new TreeNode(5);


    string ans = sol.serialize(r);
    cout << ans;

    TreeNode* root = sol.deserialize(ans);

    cin >> c;
}
