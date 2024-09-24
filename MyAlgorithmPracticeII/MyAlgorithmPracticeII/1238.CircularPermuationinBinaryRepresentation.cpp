// ´äºÃ´Âµ¥ : gray code ???? 
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
    vector<int> circularPermutation(int n, int start) {
        int N = 1 << n;
        vector <int> ans;
        for (int i = 0; i < N; i++)
            ans.push_back(start ^ (i ^ (i >> 1)));
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> folder = { "/a", "/a/b", "/c/d", "/c/d/e", "/c/f" };

    vector<string> ans = sol.removeSubfolders(folder);
    for (auto it : ans) {
        cout << it << " ";
    }
    cin >> c;
}