//  easy :
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
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int l = deck.size();
        vector<int> ans;

        sort(deck.begin(), deck.end(), std::greater<int>());

        ans.push_back(deck[0]);
        if(l >= 2) ans.insert(ans.begin(), deck[1]);

        for (int i = 2; i < l; ++i) {
            int e = ans[ans.size() - 1];
            ans.pop_back();
            ans.insert(ans.begin(), e);
            ans.insert(ans.begin(), deck[i]);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> deck = { 17,13,11,2,3,5,7 };

    vector<int> ans = sol.deckRevealedIncreasing(deck);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}