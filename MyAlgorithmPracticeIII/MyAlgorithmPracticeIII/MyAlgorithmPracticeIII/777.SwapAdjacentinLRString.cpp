// ok : check string remove x...   l only can move left,  r only can move to right 
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
    bool canTransform(string start, string result) {
        int l = start.size();
        
        string ds, de;
        vector<int> ls, rs, le, re;

        for (int i = 0; i < l; ++i) {
            if (start[i] != 'X') {

                ds.push_back(start[i]);

                if (start[i] == 'L') ls.push_back(i);
                if (start[i] == 'R') rs.push_back(i);
            }

            if(result[i] != 'X') {
                de.push_back(result[i]);

                if (result[i] == 'L') le.push_back(i);
                if (result[i] == 'R') re.push_back(i);
            }
        }

        if (ds != de) return false;

        for (int i = 0; i < ls.size(); ++i) {
            if (ls[i] < le[i]) return false;
        }

        for (int i = 0; i < rs.size(); ++i) {
            if (rs[i] > re[i]) return false;
        }

        return true;
    }
};

int main() {
    char c;
    Solution sol;

    string start = "XL";
    string result = "LX";

    cout << sol.canTransform(start, result);

    cin >> c;
}
