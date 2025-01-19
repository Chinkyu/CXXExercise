// See anser : My god  simple brute force solve problems... 
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
    int countOfSubstrings(string word, int k) {
        int l = word.size();

        int ans = 0;
        for (int id = 0; id < l; ++id) {
            int a = 0, e = 0, i = 0, o = 0, u = 0, c = 0;
            for (int j = id; j < l; ++j) {

                if (word[j] == 'a') a++;
                else if (word[j] == 'e') e++;
                else if (word[j] == 'i') i++;
                else if (word[j] == 'o') o++;
                else if (word[j] == 'u') u++;
                else c++;

                if (a > 0 && e > 0 && i > 0 && o > 0 && u > 0 && c == k) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    string word = "aeioqq";

    cout << sol.countOfSubstrings(word, 1);

    cin >> c;
}