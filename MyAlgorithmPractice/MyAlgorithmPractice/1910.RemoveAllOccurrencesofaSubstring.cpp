// easy
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

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int lp = part.size();

        do {
            size_t idx = s.find(part);
            if (idx == string::npos) break;

            s.erase(idx, lp);

        } while (true);


        return s;

    }
};

int main() {
    char c;
    Solution sol;

    string s = "daabcbaabcbc";

    cout << sol.removeOccurrences(s, "abc");

    cin >> c;
}