// OK : 
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
#include <regex>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size(), s2 = nums2.size();

        if (s1 + s2 == 1) {
            return (s1 == 0) ? nums2[0] : nums1[0];
        }

        int m1, m2;
        if ((s1 + s2) % 2 != 0) {
            m1 = m2 = (s1 + s2) / 2 + 1;
        }
        else {
            m1 = (s1 + s2) / 2;
            m2 = m1 + 1;
        }

        int n1_idx = 0, n2_idx = 0;
        int m1_num = -1, m2_num = -1;
        for (int i = 0; i < m1; ++i) {
            if (s1 <= n1_idx) {
                m1_num = nums2[n2_idx++];
            }
            else if (s2 <= n2_idx) {
                m1_num = nums1[n1_idx++];
            }
            else if (nums1[n1_idx] < nums2[n2_idx]) {
                m1_num = nums1[n1_idx++];
            }
            else {
                m1_num = nums2[n2_idx++];
            }
        }

        if (m1 != m2) {
            if (s1 <= n1_idx) {
                m2_num = nums2[n2_idx++];
            }
            else if (s2 <= n2_idx) {
                m2_num = nums1[n1_idx++];
            }
            else if (s1 <= n1_idx || nums1[n1_idx] < nums2[n2_idx]) {
                m2_num = nums1[n1_idx++];
            }
            else {
                m2_num = nums2[n2_idx++];
            }
        }
        else {
            m2_num = m1_num;
        }

        return ((double)m1_num + m2_num) / 2;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums1 = { 3, 4 };
    vector<int> nums2 = {  };
    cout << sol.findMedianSortedArrays(nums1, nums2);
    cin >> c;
}