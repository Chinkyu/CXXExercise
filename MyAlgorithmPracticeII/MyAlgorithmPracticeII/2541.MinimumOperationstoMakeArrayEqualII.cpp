// ok 
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
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int l = nums1.size();
        long long pdiff = 0, diff = 0;
        
        if (k == 0) {
            if (nums1 == nums2) {
                return 0;
            }
            else {
                return -1;
            }
        };

        for (int i = 0; i < l; ++i) {
            int tdiff = nums1[i] - nums2[i];
            if (tdiff % k != 0) return -1;

            pdiff += (tdiff > 0) ? tdiff : 0;
            diff += tdiff;
        }

        if (diff != 0) return -1;

        return pdiff / k;

    }
};

int main() {
    char c;
    Solution sol;
    string s = "1001101";

    cout << sol.maxOperations(s);

    cin >> c;
}