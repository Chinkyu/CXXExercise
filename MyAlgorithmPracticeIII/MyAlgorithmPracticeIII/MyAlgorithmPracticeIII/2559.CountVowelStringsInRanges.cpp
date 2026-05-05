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
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }


    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int l = words.size();
        vector<int> w, aw;

        for (int i = 0; i < l; ++i) {
            if (isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1])) {
                w.push_back(1);
            }
            else {
                w.push_back(0);
            }
        }

        aw.push_back(w[0]);
        for (int i = 1; i < l; ++i) {
            aw.push_back(aw[i - 1] + w[i]);
        }


        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i) {
            int st = (queries[i][0] - 1 < 0) ? 0 : aw[queries[i][0] - 1];
            int a = aw[queries[i][1]] - st;
            ans.push_back(a);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    //vector<int> nums = { 0,3,7,2,5,8,4,6,0,1 };

    cout << sol.trailingZeroes(5);

    cin >> c;
}
