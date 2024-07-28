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
private:
    vector<string> res;

public:
    vector<string> removeInvalidParentheses(string s) {
        helper(s, 0, 0, { '(', ')' });
        return res;
    }

    void helper(string s, int left, int right, const vector<char>& para) {
        int len = s.length();
        int counter = 0;
        // Analysis
        //  "()())()"
        while (right < len) {
            char ch = s[right];
            if (ch == para[0]) {
                counter++;
            }
            else if (ch == para[1]) {
                counter--;
            }
            if (counter < 0) {
                break;
            }
            right++;

        }

        // Case 1
        if (counter < 0) {
            while (left <= right) {
                char ch = s[left];
                if (ch != para[1] || (left > 0 && s[left] == s[left - 1])) {
                    left++;
                    continue;
                }
                // "(())()"
                s.erase(left, 1);
                helper(s, left, right, para);
                s.insert(s.begin() + left, para[1]);
                left++;

            }
        }
        // Case 2
        else if (counter > 0) {
            reverse(s.begin(), s.end());
            helper(s, 0, 0, { ')','(' });
        }
        // Case 3
        else {
            res.push_back(para[0] == '(' ? s : string(s.rbegin(), s.rend()));
        }
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
