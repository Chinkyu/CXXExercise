// brute force  : 
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
    int beautifulSubstrings(string s, int k) {
        int l = s.size();
        vector<int> cc(l + 1, 0), vc(l + 1, 0);

        for (int i = 0; i < l; ++i) {

            if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') { // vowl
                vc[i + 1] = vc[i] + 1;
                cc[i + 1] = cc[i];
            }
            else { // consonate
                cc[i + 1] = cc[i] + 1;
                vc[i + 1] = vc[i];
            }
        }

        int ans = 0;
        for (int i = 0; i < l + 1; ++i) {
            for (int j = i + 1; j < l + 1; ++j) {
                int v_count = vc[j] - vc[i];
                int c_count = cc[j] - cc[i];

                if (/*(v_count >= k && v_count % k == 0) && (c_count >= k && c_count % k == 0)*/
                    (v_count == c_count) && ((v_count * c_count) % k == 0)) {
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

    string s = "abba";
    //"baeyh";

    cout << sol.beautifulSubstrings(s, 1);

    cin >> c;
}
