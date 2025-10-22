// easy : 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
    bool checkIfCanBreak(string s1, string s2) {

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        int bs = 0;

        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] < s2[i] && bs == 0) {
                bs = 1;
                continue;
            }
            if (s1[i] > s2[i] && bs == 0) {
                bs = -1;
                continue;
            }

            if (s1[i] < s2[i] && bs == -1) {
                return false;
            }
            if (s1[i] > s2[i] && bs == 1) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    char c;
    
    string s1 = "leetcode";
    string s2 = "interview";


    cout << sol.checkIfCanBreak(s1, s2);


    cin >> c;
}
