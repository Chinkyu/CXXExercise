//  답봤음 : 문제의 답을 만들고 그냥 확인 한다... 
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
    bool reorderedPowerOf2(int n) {
        vector<string>v;
        string p = to_string(n);
        sort(p.begin(), p.end());
        for (int i = 0; i < 31; i++) {
            long long x = (1LL << i);
            string s = to_string(x);
            sort(s.begin(), s.end());
            v.push_back(s);
        }
        for (auto it : v) {
            if (it == p) {
                return true;
            }
        }
        return false;
    }
};


// 이렇게 하면.... timeout.
class Solution {
public:

    bool isPowerof2(string s) {
        long long n = 0;
        n = stol(s, 0);

        if (n == 0)
            return false;

        cout << (float)log2(n) << endl;

        return (ceil(log2(n)) == floor(log2(n)));
    }


    bool permute(string ns, int l, int r) {
        if (l == r) {
            return isPowerof2(ns);
        }
        else {
            for (int i = l; i <= r; ++i) {
                swap(ns[l], ns[i]);
                bool rt = permute(ns, l + 1, r);
                swap(ns[l], ns[i]); // trace back

                if (rt == false) return false;
            }
        }

        return true;
    }

    bool reorderedPowerOf2(int n) {
        string ns = to_string(n);

        return permute(ns, 0, ns.size() - 1);
    }
};

int main() {
    char c;
    Solution sol;

    cout << sol.reorderedPowerOf2(16);

    cin >> c;
}