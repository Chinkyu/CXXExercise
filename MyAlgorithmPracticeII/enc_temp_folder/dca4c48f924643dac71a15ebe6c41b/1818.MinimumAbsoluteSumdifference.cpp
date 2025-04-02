//  ¥‰∫√¿Ω : Making map.........  does it make sense??  
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
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {

        long long sum = 0;
        int delta = 0;

        int mdelta = 0;
        int idelta = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            int d = abs(nums1[i] - nums2[i]);
            if (mdelta <= d) {
                mdelta = d;
                idelta = i;
            }
            sum += d;

            sum %= 1000000007;
        }

        int adelta = mdelta;
        for (int i = 0; i < nums1.size(); ++i) {
            if (adelta > abs(nums1[i] - nums2[idelta])) {
                adelta = abs(nums1[i] - nums2[idelta]);
            }
        }

        sum -= mdelta - adelta;
        return sum;
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