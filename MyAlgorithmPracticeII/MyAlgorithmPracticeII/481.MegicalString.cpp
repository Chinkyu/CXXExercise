// see answer and make from rule : 
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
    int magicalString(int n) {

        vector<int> ms = { 1, 2, 2 };
    
        int iterator = 1;
        int cnt = 1;
        for (int i = 2; ms.size() < n; ++i) {
            for (int j = 0; j < ms[i]; j++) {
                ms.push_back(iterator);
                if (ms.size() <= n && iterator == 1) cnt++;
            }
            iterator = (iterator == 1) ? 2 : 1;
        }
        return cnt;

    }
};



class _Solution {
public:
    int magicalString(int n) {
        if (n < 4) return 1;
        vector<int> arr(n + 2, 0);
        arr[2] = 2;
        int res = 1;
        for (int idx = 2, curr = 1, pos = 3; pos < n; ++idx) {
            for (int j = 0; j < arr[idx] && pos < n; ++j, ++pos) {
                arr[pos] = curr;
                if (curr == 1) ++res;
            }
            curr ^= 3;
        }
        return res;
    }
};
int main() {
    char c;
    Solution sol;

    cout << sol.magicalString(7);


    cin >> c;
}