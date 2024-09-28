// easy : 알고보니 이지였음.. 
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
    int pivotInteger(int n) {
        vector<int> p(n + 1);

        int a = 0;
        for (int i = 1; i <= n; ++i) {
            a += i;
            p[i] = a;
        }


        for (int i = 0; i <= n; ++i) {
            if (p[i] == p[n] - p[i] + i) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    char c;
    Solution sol;

    cout << sol.pivotInteger(8);
    cin >> c;
}