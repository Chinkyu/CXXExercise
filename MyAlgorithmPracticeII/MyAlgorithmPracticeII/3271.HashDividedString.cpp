// ok : 
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
    string stringHash(string s, int k) {
        string ans;
        int l = s.size();

        for (int i = 0; i < l; ++i) {
            int sub_sum = 0;
            for (int j = i, t = 0; j < l && t < k; ++j, ++t) {
                sub_sum += s[j] - 'a';
                sub_sum %= 26;
                i = j;
            }
            ans.push_back(sub_sum + 'a');
        }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "mxz";

    cout << sol.stringHash(s, 3);

    cin >> c;
}