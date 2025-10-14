// see answer : Àß ÀÌÇØ ¾ÈµÊ..
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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

/*

    Every index i can at least reach p[i] (prefix maximum).
    If p[i] > s[i+1], we showed a constructive path i ¡æ x ¡æ y ¡æ i+1 that connects both sides. Hence the reachable sets from i and i+1 are identical.
    If p[i] ¡Â s[i+1], then left-side values are all smaller/equal to right-side values. That makes crossing impossible (no valid jump condition holds). So the maximum reachable from i is just the best prefix maximum p[i].
    Combining both cases ensures correctness.

*/


class Solution {
public:
    vector<int> maxValue(vector<int>& a) {
        int n = a.size();
        if (n == 0) return {};
        vector<int> p(n), s(n), ans(n);

        // prefix max
        for (int i = 0; i < n; ++i)
            p[i] = (i ? max(p[i - 1], a[i]) : a[i]);

        // suffix min
        s[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i)
            s[i] = min(s[i + 1], a[i]);

        // answers
        ans[n - 1] = p[n - 1];
        for (int i = n - 2; i >= 0; --i)
            ans[i] = (p[i] > s[i + 1]) ? ans[i + 1] : p[i];

        return ans;
    }
};

int main() {
    Solution sol;
    char c;
    vector<int> tasks = { 2,2,3,3,2,4,4,4,4,4 };

    cout << sol.minimumRounds(tasks);

    cin >> c;
}
