// 답봤음 : 쉽게 해결하네.. 소팅 해서는... 
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
#include <functional>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int ops = 0;
        for (int fac = 2; fac <= n; fac++) {
            while (n % fac == 0) {
                ops += fac;
                n /= fac;
            }
        }
        return ops;
    }
};

int main() {
    char c;
    Solution sol;
    string order = "kqep";
    string s = "pekeq";

    cout << sol.customSortString(order, s);

    cin >> c;
}