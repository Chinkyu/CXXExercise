// ok : using multiset, set
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
    int numSpecialEquivGroups(vector<string>& words) {

        set<pair<multiset<char>, multiset<char>>> s;


        for (auto& it : words) {
            multiset<char> ls, rs;
            for (int i = 0; i < it.size(); ++i) {
                if (i % 2 == 0) {
                    ls.insert(it[i]);
                }
                else {
                    rs.insert(it[i]);
                }
            }

            s.insert(make_pair(ls, rs));

        }

        return s.size();
    }
};

int main() {
    char c;
    Solution sol;

    string croakOfFrogs = "croakcrook";

    cout << sol.minNumberOfFrogs(croakOfFrogs);

    cin >> c;
}






