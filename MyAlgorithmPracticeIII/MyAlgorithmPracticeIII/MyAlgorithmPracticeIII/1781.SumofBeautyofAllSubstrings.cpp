// ok : multiset, map  - very slot 
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
    int beautySum(string s) {
        int l = s.size();


        int ans = 0;
        for (int i = 0; i < l - 1; ++i) {
            string ps = "";
            ps.push_back(s[i]);
            
            multiset<int> ms;
            unordered_map<char, int> m;

            ms.insert(1);
            m[s[i]] = 1;

            for (int j = i + 1; j < l; ++j) {

                int prenum = m[s[j]];
                m[s[j]]++;
                if (prenum != 0) {
                    auto it = ms.find(prenum);
                    ms.erase(it);
                    ms.insert(prenum + 1);
                }
                else {
                    ms.insert(1);
                }

                ans += *ms.rbegin() - *ms.begin();
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "aabcb";

    cout << sol.beautySum(s);

    cin >> c;
}
