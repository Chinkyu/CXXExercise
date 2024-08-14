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
    map<pair<int, int>, bool> t;
    unordered_set<int> s;
    bool canCross(vector<int>& stones) {
        if (stones[1] - stones[0] != 1)
            return false;
        int last_stone = stones[stones.size() - 1];
        for (int i : stones)
        {
            s.insert(i);
        }
        return func(last_stone, stones[1], 1);
    }
    bool func(int last_stone, int curr_stone, int k)
    {
        if (curr_stone == last_stone)
            return true;
        if (t.find(make_pair(curr_stone, k)) != t.end())
            return t[make_pair(curr_stone, k)];
        bool ans = false;
        if (k - 1 > 0 && s.find(curr_stone + k - 1) != s.end())
        {
            ans = ans || func(last_stone, curr_stone + k - 1, k - 1);
        }
        if (s.find(curr_stone + k) != s.end())
        {
            ans = ans || func(last_stone, curr_stone + k, k);
        }
        if (s.find(curr_stone + k + 1) != s.end())
        {
            ans = ans || func(last_stone, curr_stone + k + 1, k + 1);
        }
        t[make_pair(curr_stone, k)] = ans;
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
