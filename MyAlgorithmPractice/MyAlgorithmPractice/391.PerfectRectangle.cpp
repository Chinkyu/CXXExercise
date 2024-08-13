// ¥‰∫√¿Ω : vector and unordered_map
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
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> mark;
        for (vector<int>& x : rectangles) {
            mark[{x[0], x[1]}]++;
            mark[{x[0], x[3]}]--;
            mark[{x[2], x[1]}]--;
            mark[{x[2], x[3]}]++;
        }
        int n_mark = 0;
        for (auto ptr = mark.begin(); ptr != mark.end(); ptr++)
            if (ptr->second != 0) {
                if (abs(ptr->second) != 1) return false;
                n_mark++;
            }
        return n_mark == 4;
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
