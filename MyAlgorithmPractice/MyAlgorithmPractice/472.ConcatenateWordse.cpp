// 답봤음 : 문제 이해 안감... - skip
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
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> rapport(102, -1);
        vector<int> rest(102, -1);
        int b = -1; int posRest = 0; int rap = 0;
        int last = -1;
        rapport[0] = rest[0] = 0;
        for (int i = 1; i <= s2.size() + 1; i++) {
            int j;
            for (j = 0; j < s1.size(); j++) {
                if (s2[posRest] == s1[j]) {
                    posRest++;
                    if (posRest == s2.size()) {
                        rap++;
                        posRest = 0;
                    }
                }
            }
            for (int k = 0; k < i; k++) {
                if (posRest == rest[k]) { b = k; last = i; break; }
            }
            rapport[i] = rap; rest[i] = posRest;
            if (b >= 0)break;
        }
        int interval = last - b;
        if (b >= n1)return rapport[n1] / n2;
        return ((n1 - b) / interval * (rapport[last] - rapport[b]) + rapport[(n1 - b) % interval + b]) / n2;
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
