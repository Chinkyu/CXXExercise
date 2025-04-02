//  ¥‰∫√¿Ω : 
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
    int minAbsoluteSumDiff(vector<int>& n1, vector<int>& n2) {
        long res = 0, gain = 0;
        set<int> s(begin(n1), end(n1));
        for (int i = 0; i < n1.size(); ++i) {
            long original = abs(n1[i] - n2[i]);
            res += original;
            if (gain < original) {
                auto it = s.lower_bound(n2[i]);
                if (it != end(s))
                    gain = max(gain, original - abs(*it - n2[i]));
                if (it != begin(s))
                    gain = max(gain, original - abs(*prev(it) - n2[i]));
            }
        }
        return (res - gain) % 1000000007;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> nums1 = { 1, 7, 5 };
    //vector<int> nums2 = { 2, 3, 5 };
    vector<int> nums1 = { 1, 28, 21 };
    vector<int> nums2 = { 9, 21, 20 };

    cout << sol.minAbsoluteSumDiff(nums1, nums2);

    cin >> c;
}