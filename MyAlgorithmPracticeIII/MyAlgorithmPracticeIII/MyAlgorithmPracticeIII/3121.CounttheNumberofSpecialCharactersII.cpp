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
#include <random>
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> v(26, 0);

        for (auto& it : word) {

            if ('a' <= it && it <= 'z') {
                if (v[it - 'a'] >= 2) {  // 2 and 3
                    v[it - 'a'] = 3;  // lower after upper   - remove from candidate
                    continue;
                }
                v[it - 'a'] = 1;
            }
            else { // upper case
                if (v[it - 'A'] == 0) {  // upper first  - remove from candidate
                    v[it - 'A'] = 3;
                    continue;
                } else if (v[it - 'A'] == 1) {
                    v[it - 'A'] = 2;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (v[i] == 2) ans++;   // only 2
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string word = "aecsqgusxlWRUNVZOUNM";

    cout << sol.numberOfSpecialChars(word);


    cin >> c;
}
