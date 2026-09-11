// ok : string operation 
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

    string addOne(string s) {
        int l = s.size();

        bool isAllOne = true;
        for (int i = l - 1; i >= 0; --i) {
            if (s[i] == '1') {
                s[i] = '0';
            }
            else {
                s[i] = '1';
                isAllOne = false;
                break;
            }
        }

        if (isAllOne == true) {
            s.insert(0, "1");
        }

        return s;
    }

    int numSteps(string s) {
        int ans = 0;

        while (s != "1") {
            if (*s.rbegin() == '0') {
                s.pop_back();
            }
            else { // '1'
                s = addOne(s);
            }
            ans++;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
   
    string s = "1101";
    cout << sol.numSteps(s);

    cin >> c;
}
