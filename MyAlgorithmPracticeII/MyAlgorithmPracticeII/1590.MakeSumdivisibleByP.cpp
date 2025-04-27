//  see answer
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
#include <set>
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& A, int p) {
        int n = A.size(), res = n, need = 0, cur = 0;
        for (auto a : A)
            need = (need + a) % p;
        unordered_map<int, int> last = { {0, -1} };
        for (int i = 0; i < n; ++i) {
            cur = (cur + A[i]) % p;
            last[cur] = i;
            int want = (cur - need + p) % p;
            if (last.count(want))
                res = min(res, i - last[want]);
        }
        return res < n ? res : -1;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "aabcbbca";

    cout << sol.lastNonEmptyString(s);

    cin >> c;
}