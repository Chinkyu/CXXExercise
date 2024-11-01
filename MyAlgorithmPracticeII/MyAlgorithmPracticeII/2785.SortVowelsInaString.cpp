// easy :
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
    string sortVowels(string s) {

        string vo;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {

                vo.push_back(s[i]);
                s[i] = '.';
            }
        }

        sort(vo.begin(), vo.end());

        int voidx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '.') s[i] = vo[voidx++];
        }

        return s;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "lEetcOde";
    cout << sol.sortVowels(s);

    cin >> c;
}