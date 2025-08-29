//  ok
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

// 뒤에서 1빼고 그룹 개수 찾아서 처음 *1, 다음 *2, 다다음*3 방식으로...

class Solution {
public:
    int maxOperations(string s) {
        int l = s.size();

        vector<int> v;

        int idx = l-1;

        // remove first '1'
        while (idx >= 0 && s[idx] == '1') idx--;

        while (idx >= 0) {
            // skip 0
            while (idx >= 0 && s[idx] == '0') idx--;

            int cnt = 0;
            while (idx >= 0 && s[idx] == '1') {
                idx--; cnt++;
            }
            if (cnt > 0) v.push_back(cnt);
        }

        int ans = 0;
        for (int i = 0; i < v.size(); ++i) {
            ans += v[i] * (i + 1);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    string s = "1001101";

    cout << sol.maxOperations(s);

    cin >> c;
}