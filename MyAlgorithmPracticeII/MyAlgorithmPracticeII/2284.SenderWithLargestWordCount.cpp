// 이상함 : vsstudio 에서는 되는데.. leetcode 에서는 다른답이 나오는데.... why ??
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

    int wordCount(string& s) {
        int count = 1;
        for (auto& it : s) {
            if (it == ' ') count++;
        }
        return count;
    }

    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int l = messages.size();
        unordered_map<string, int> m;

        for (int i = 0; i < l; ++i) {
            int wc = wordCount(messages[i]);
            if (m.find(senders[i]) == m.end() || m[senders[i]] < wc) m[senders[i]] += wc;
        }

        string ans = "";
        for (auto& it : m) {
            if (it.second > ans.size()) {
                ans = it.first;
            }
            else if (it.second == ans.size()) {
                if (it.first > ans) ans = it.first;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> messages = { "Hello userTwooo", "Hi userThree", "Wonderful day Alice", "Nice day userThree" };
    vector<string> senders = {"Alice", "userTwo", "userThree", "Alice" };

    cout << sol.largestWordCount(messages, senders);

    cin >> c;
}