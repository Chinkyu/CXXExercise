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

int countOfSubstrings(string s, int k) {
    int ans = 0;

    for (int i = 0; i < s.size(); i++) {
        int a = 0, e = 0, m = 0, o = 0, u = 0, c = 0;
        for (int j = i; j < s.size(); j++) {
            if (s[j] == 'a') a++;
            else if (s[j] == 'e') e++;
            else if (s[j] == 'i') m++;
            else if (s[j] == 'o') o++;
            else if (s[j] == 'u') u++;
            else c++;

            if (a and e and m and o and u and c == k) ans++;
        }
    }

    return ans;
}

int main() {
    char c;
    Solution sol;
    vector<int> nums = { 4,2,9,5,3 };

    cout << sol.maximumPrimeDifference(nums);

    cin >> c;
}