// ¥‰∫√¿Ω : 
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

    struct Node {
        Node* links[2];
        int ct = 0;

        Node() {
            links[0] = links[1] = NULL;
            ct = 0;
        }
    };

    int countSmaller(Node* root, int x) {
        Node* curr = root;
        bitset<15>bits(x);
        int ans = 0;
        for (int i = 14; i >= 0 && curr; i--) {
            if (bits[i] == 1) {

                if (curr->links[0]) {
                    ans += curr->links[0]->ct;
                    curr = curr->links[1];
                }
                else curr = curr->links[1];
            }
            else {

                curr = curr->links[0];
            }
        }
        return ans;
    }

    void insert(Node* root, int x) {
        Node* curr = root;
        bitset<15>bits(x);

        for (int i = 14; i >= 0; i--) {
            if (!curr->links[bits[i]]) curr->links[bits[i]] = new Node();
            curr = curr->links[bits[i]];
            curr->ct++;
        }
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<int>ans(n);
        Node* root = new Node();
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = countSmaller(root, (nums[i] + 1e4));
            insert(root, (nums[i] + 1e4));
        }

        return ans;
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
