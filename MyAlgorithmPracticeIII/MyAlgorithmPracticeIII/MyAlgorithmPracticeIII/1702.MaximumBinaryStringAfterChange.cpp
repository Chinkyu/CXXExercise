// ok :  remain left 1  and move all 1 to right  and 0000 -> 1110
//       So only one zero in result 
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

//if left '1' skip it. 
class Solution {
public:
    string maximumBinaryString(string binary) {
        int l = binary.size();
        int cnt_one = 0;
        int left_one = 0;

        if (l <= 1) return binary;

        bool zero_met = false;
        for (int i = 0; i < l; ++i) {
            if (binary[i] == '0') {
                zero_met = true;
            }
            if (zero_met == false && binary[i] == '1') left_one++;

            if (zero_met == true && binary[i] == '1') cnt_one++;
        }

        string ans(l, '1');
        if (l - cnt_one - 1 >= 0 && cnt_one >= 0 && l - left_one > 0) {
            ans[l - cnt_one - 1] = '0';
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "1100";

    cout << sol.maximumBinaryString(s);

    cin >> c;
}
