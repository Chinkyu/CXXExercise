// ok : if num0, num1 is same  use NCR 
//  그런데 답을 보면  NCR 안쓰고 엄청 쉽게 출었음.....  같아도 처리가 되게..

/*
    long long maximumSubsequenceCount(string text, string pattern) {
        long long res = 0, cnt1 = 0, cnt2 = 0;
        for (char& c: text) {
            if (c == pattern[1])
                res += cnt1, cnt2++;
            if (c == pattern[0])
                cnt1++;
        }
        return res + max(cnt1, cnt2);
    }
*/


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
#include <random>

using namespace std;

class Solution {
public:

    long long NCR(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1; // Base case for nCn
        // Optimization: C(n, r) = C(n, n - r)
        if (r > n / 2) r = n - r;

        long long res = 1;
        for (int k = 1; k <= r; ++k) {
            res = res * (n - k + 1);
            res /= k;
        }
        return res;
    }

    long long maximumSubsequenceCount(string text, string pattern) {
        int l = text.size();
        vector<int> first;

        if (pattern[0] == pattern[1]) {

            int cnt = 0;
            for (auto& it : text) {
                if (it == pattern[0]) cnt++;
            }

            // cnt + 1  combination 2 
            return NCR(cnt + 1, 2);
        }


        int cnt = 0;
        long long fans = 0;
        for (int i = l - 1; i >= 0; --i) {
            if (text[i] == pattern[1]) {
                cnt++;
            } else
            if (text[i] == pattern[0]) {
                first.push_back(cnt);
                fans += cnt;
            }
        }

        // add first 
        fans += cnt; 

        // add second
        long long sans = 0;
        for (auto& it : first) {
            sans += it + 1;
        }

        return (fans > sans) ? fans: sans;
    }
};

int main() {
    char c;
    Solution sol;

    string text = "fwymvreuftzgrcrxczjacqovduqaiig";
    string pattern = "yy";

    cout << sol.maximumSubsequenceCount(text, pattern);


    cin >> c;
}
