// 답봤음 : 쉽게 해결하네.. 소팅 해서는... 
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
    int minimumLengthEncoding(vector<string>& words) {
        string ans;
        sort(words.begin(), words.end(), [](string& a, string& b) {return a.size() > b.size(); });
        for (string& s : words)
            if (ans.find(s + "#") == string::npos) ans += s + "#";
        return ans.size();
    }
};

int main() {
    char c;
    Solution sol;
    string order = "kqep";
    string s = "pekeq";

    cout << sol.customSortString(order, s);

    cin >> c;
}