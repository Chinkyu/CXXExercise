// ok : 우와 무식하게 되네....  
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

    void operation(vector<int> &v) {
        int l = v.size();
        vector<int> arr = v;
        for (int i = 0; i < l; ++i) {
            if (i % 2 == 0) {
                arr[i] = v[i / 2];
            }
            else {
                arr[i] = v[l / 2 + (i - 1) / 2];
            }
        }

        v = arr;
    }

    int reinitializePermutation(int n) {
        vector<int> v(n, 0), v2(n, 0);

        for (int i = 0; i < n; ++i) {
            v[i] = v2[i] = i;
        }

        int cnt = 0;
        do {
            operation(v2);
            cnt++;
        } while (v != v2);

        return cnt;
    }
};

int main() {
    char c;
    Solution sol;

    cout << sol.reinitializePermutation(6);

    cin >> c;
}