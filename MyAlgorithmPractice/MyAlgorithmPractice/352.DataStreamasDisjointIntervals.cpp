// ¥‰∫√¿Ω : math
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

class SummaryRanges {


public:
    set<int>st;
    SummaryRanges() {}
    void addNum(int value) { st.insert(value); }
    vector<vector<int>> getIntervals() {
        if (st.empty()) {
            return {};
        }
        vector<vector<int>> ans;
        int start = -1, last = -1;
        for (int val : st) {
            if (start < 0) {
                start = last = val;
            }
            else if (val - last == 1) {
                last = val;
            }
            else {
                ans.push_back({ start, last });
                start = last = val;
            }
        }
        ans.push_back({ start, last });
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

//UPVOTE IF YOU LIKED THE ANSWER..THANK YOU

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
