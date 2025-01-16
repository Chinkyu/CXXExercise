// ¥‰∫√¿Ω
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
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> last;
        long long res = 0;
        for (int a : tasks)
            if (last.count(a))
                last[a] = res = max(res, last[a] + space) + 1;
            else
                last[a] = ++res;
        return res;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "leet**cod*e";

    cout << sol.removeStars(s);

    cin >> c;
}