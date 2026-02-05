// ok : truck move to the end of garbage
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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int l = garbage.size();

        vector<int> act(l, 0);

        act[0] = 0;  travel[0];
        for (int i = 1; i < act.size(); ++i) {
            act[i] = act[i - 1] + travel[i- 1];
        }

        int ans = 0;
        bool foundM = false, foundP = false, foundG = false;
        for (int i = l - 1; i >= 0; --i) {

            // count Char number
            ans += garbage[i].size();

            // find last garbage for each MPG and add distance once 
            if (foundP == false && garbage[i].find("P") != string::npos) {
                ans += act[i];
                foundP = true;
            }

            if (foundM == false && garbage[i].find("M") != string::npos) {
                ans += act[i];
                foundM = true;
            }

            if (foundG == false && garbage[i].find("G") != string::npos) {
                ans += act[i];
                foundG = true;
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<string> garbage = { "G", "M"};
    vector<int> travel = { 1 };

    cout << sol.garbageCollection(garbage, travel);


    cin >> c;
}
