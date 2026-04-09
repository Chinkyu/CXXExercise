// ok.. 
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
    long long minimumCost(string s) {
        long long ans = 0;
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                ans += min(i, n - i); // Key Observation
                //Think Greedy 
            }
        }return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "0011";
        //"010101";
    cout << sol.minimumCost(s);

    cin >> c;
}
