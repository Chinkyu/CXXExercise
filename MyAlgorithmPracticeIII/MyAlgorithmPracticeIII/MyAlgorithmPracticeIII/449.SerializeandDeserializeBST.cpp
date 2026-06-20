// Ok... string  comman  serialization 
// tried with char.......  but.. 
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

    void ser_traverse(string& s, TreeNode* root) {
        if (root == nullptr) return;

        int l = -1, r = -1;
        if (root->left != nullptr) {
            l = root->left->val;
            ser_traverse(s, root->left);
        }
        if (root->right != nullptr) {
            r = root->right->val;
            ser_traverse(s, root->right);
        }

        s += to_string(root->val) + ',';
        s += to_string(l) + ',';
        s += to_string(r) + ',';
   }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        ser_traverse(s, root);
        return s;
    }

    void deser_traverse(unordered_map<int, pair<int, int>>& m, TreeNode* root) {

        if (m.find(root->val) == m.end()) {
            return;
        }

        int l = m[root->val].first;
        int r = m[root->val].second;

        if (l != -1) {
            root->left = new TreeNode(l);
            deser_traverse(m, root->left);
        }
        if (r != -1) {
            root->right = new TreeNode(r);
            deser_traverse(m, root->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data.size() <= 0) return nullptr;

        unordered_map<int, pair<int, int>> m;

        int rv = 0;

        istringstream stream(data);
        string token;
        while(getline(stream, token, ',')) {
            rv = stoi(token);
            getline(stream, token, ',');
            int s1 = stoi(token);
            getline(stream, token, ',');
            int s2 = stoi(token);
            m[rv] = make_pair(s1, s2);
        }

        TreeNode* root = new TreeNode(rv);
        deser_traverse(m, root);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;


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
