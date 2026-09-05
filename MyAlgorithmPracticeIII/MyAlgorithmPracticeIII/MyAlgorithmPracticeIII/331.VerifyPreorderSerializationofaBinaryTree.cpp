// ok : traverse success   after finish, no remain 
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
#include <numeric>

using namespace std;

class Solution {
public:

    bool traverse(stringstream& ss) {

        string token;
        int ans = true;

        // left
        if (getline(ss, token, ',')) {
            if (token != "#") {
                ans = traverse(ss);
            }
        }
        else {
            ans = false;
        }

        // right
        if (getline(ss, token, ',')) {
            if (token != "#") {
                ans = traverse(ss);
            }
        }
        else {
            ans = false;
        }

        return ans;
    }


    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);

        
        if (preorder == "#") {
            return true;  // one node tree
        }


        // first value
        string token;
        if (getline(ss, token, ',')) {
            if (token == "#") {
                return false;
            }
            //else {
            //    ans = true; // none #
            //}
        }
        else {
            return false;
        }

        bool ans = traverse(ss);

        // if there is remains 
        if (getline(ss, token, ',')) {
            return false;
        }

        return ans;
    }
};


int main() {
    char c;

    Solution sol;

    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    //string s = "1,#";

    cout << sol.isValidSerialization(s);

    cin >> c;
}
