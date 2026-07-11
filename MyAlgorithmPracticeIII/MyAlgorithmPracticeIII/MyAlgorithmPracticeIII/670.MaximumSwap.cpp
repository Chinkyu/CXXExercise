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

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);

        string ss = s;
        sort(ss.begin(), ss.end(), std::greater<>());

        int l = s.size();
        for (int i = 0; i < l; ++i) {
            if (s[i] != ss[i]) {
                char tmp = s[i];
                s[i] = ss[i];

                int j = l - 1;
                while (s[j] != ss[i]) j--;
                s[j] = tmp;
                break;
            }
        }

        return stoi(s);
    }
};


int main() {
    char c;
    Solution sol;

    int num = 2736;
    cout << sol.maximumSwap(num);

    cin >> c;
}
