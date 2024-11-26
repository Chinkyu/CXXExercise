//  easy : sliding windows... need perforamcnece improve... may be without copy
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
    int longestWPI(vector<int>& hours) {
        int l = hours.size();
        vector<int> nh;

        nh.push_back(0);
        for (auto& it : hours) {
            if (it > 8) {
                nh.push_back(1);
            }
            else {
                nh.push_back(0);
            }
        }

        l++;
        vector<int> anh(l, 0);
        anh[0] = nh[0];
        for (int i = 1; i < l; ++i) {
            anh[i] = anh[i - 1] + nh[i];
        }

        int ans = 0; 
        for (int i = 0; i < l - 1; ++i) {
            for (int j = 1; j < l; ++j) {
                if (anh[j] - anh[i] > (j - i)/ 2) {
                    ans = max(ans, j - i);
                }
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> hours = { 6, 6, 9 }; //  { 9, 9, 6, 0, 6, 6, 9 };

    cout << sol.longestWPI(hours);

    cin >> c;
}