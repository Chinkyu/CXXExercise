// ok : x1 * number of l2 : l2 is even x1 not count
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
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        l1 %= 2;
        l2 %= 2;

        int xor1 = nums1[0] * l2, xor2 = nums2[0] * l1;

        for (int i = 1; i < nums1.size(); ++i) xor1 ^= nums1[i] * l2;
        for (int i = 1; i < nums2.size(); ++i) xor2 ^= nums2[i] * l1;

        return xor1 ^ xor2;

    }
};

int main() {
    char c;
    Solution sol;

    vector<int>
        cout << sol.largestMerge(word1, word2);


    cin >> c;
}
