// easy : Xi = Xi-1 + (Xi-1) * 4 점화식으로 풀어도 factorial 이라.. 이렇게 품
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
    long long coloredCells(int n) {
        long long ans = 1;

        for (int i = 2; i <= n; ++i) {
            ans = ans + (4 * (i - 1));
        }
        
        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    cout << sol.coloredCells(2);
    cin >> c;
}