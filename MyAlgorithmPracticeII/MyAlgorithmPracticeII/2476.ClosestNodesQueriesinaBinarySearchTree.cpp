// see answer : dfs
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> sorted;
    void pushToArr(TreeNode* root) {
        if (root->left) pushToArr(root->left);
        sorted.push_back(root->val);
        if (root->right) pushToArr(root->right);
        return;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        sorted.clear();
        pushToArr(root);
        int
            left, right,
            gi, si,
            mid, elem
            ;
        vector<vector<int>> ans;
        for (int q : queries) {
            gi = si = -1;
            left = 0; right = sorted.size() - 1;
            while (left <= right) {
                mid = (left + right) / 2;
                elem = sorted[mid];
                if (elem == q) {
                    gi = si = q;
                    break;
                }
                else if (elem < q) {
                    gi = elem;
                    left = mid + 1;
                }
                else if (elem > q) {
                    si = elem;
                    right = mid - 1;
                }
            }
            ans.push_back({ gi, si });
        }
        return ans;
    }
};

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
    void traverse(vector<int>& v, TreeNode* p) {
        if (p == nullptr) return;

        if (p->left != nullptr) traverse(v, p->left);
        v.push_back(p->val);
        if (p->right != nullptr) traverse(v, p->right);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        map<int, int> m;
        vector<int> v;

        traverse(v, root);
        
        for (auto& it : v) {
            m[it] = 1;
        }

        vector<vector<int>> ans;
        for (auto& it : queries) {
            vector<int> item;

            auto ub = m.upper_bound(it);
            if (it < m.begin()->first) {
                item[0] = -1;
            }
            else {
                item[0] = ub->first;
            }

            auto lb = m.lower_bound(it);
            if (lb == m.end())
                item[1] = -1;
            else {
                item[1] = lb->first;
            }
        }

        return ans;
    }

    vector<vector<int>> closestNodes(vector<int>& arr, vector<int>& queries) {
        map<int, int> m;
        vector<int> v;

        //sort(arr.begin(), arr.end());

        for (auto& it : arr) {
            m[it] = 1;
        }

        vector<vector<int>> ans;
        for (auto& it : queries) {
            vector<int> item(2, 0);

            auto ub = m.upper_bound(it);

            if (ub != m.begin()) {
                auto lub = ub->prev();
                if (it <= lb->first) ub = lub;
            }

            if (it < m.begin()->first) {
                item[0] = -1;
            }
            else {
                item[0] = ub->first;
            }

            auto lb = m.lower_bound(it);
            if (lb == m.end())
                item[1] = -1;
            else {
                item[1] = lb->first;
            }
        }

        return ans;
    }

};

int main() {
    char c;
    Solution sol;

    vector<int> arr = { 6, 2, 13, 1, 4, 9, 15, 14 };
    vector<int> queries = { 2, 5, 16 };

    vector<vector<int>> ans = sol.closestNodes(arr, queries);
    for (auto& it : ans) {
        cout << it[0] << "," << it[1] << endl;
    }

    cin >> c;
}