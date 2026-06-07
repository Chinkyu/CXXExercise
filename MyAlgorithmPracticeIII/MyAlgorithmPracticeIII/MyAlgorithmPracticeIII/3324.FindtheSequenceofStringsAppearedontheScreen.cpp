// ok
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
    vector<string> stringSequence(string target) {
        int l = target.size();
        vector<string> ans;

        string current = "";

        for (int i = 0; i < l; ++i) {

            current.push_back('a');
            ans.push_back(current);

            for (int j = current[i]; j < target[i]; ++j) {
                current[i]++;
                ans.push_back(current);
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string target = "he";

    vector<string> ans = sol.stringSequence(target);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
