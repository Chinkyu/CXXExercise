// easy : not same. push, pop,   same : push
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
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> ans;

        int c = 1;
        for (int i = 0; i < target.size(); ++i) {

            while (target[i] != c) {
                ans.push_back("Push");
                ans.push_back("Pop");
                c++;
            }

            ans.push_back("Push");
            c++;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string addr = "172.16.254";
    // "1e1.4.5.6";
    //"2001:0db8:85a3:0:0:8A2E:0370:7334";

    cout << sol.validIPAddress(addr);

    cin >> c;
}
