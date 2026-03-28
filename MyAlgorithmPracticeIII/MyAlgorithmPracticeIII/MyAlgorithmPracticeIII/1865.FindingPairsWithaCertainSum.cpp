// ok : pass with two map..
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
#include <chrono>
#include <iterator>

using namespace std;

// timeout
class _FindSumPairs {
public:
    unordered_map<int, int> m;
    vector<int> n1, n2;

    _FindSumPairs(vector<int>& nums1, vector<int>& nums2) {

        n1 = nums1;
        n2 = nums2;

        for (auto& it : nums1) {
            for (auto& jt : nums2) {
                m[it + jt]++;
            }
        }
    }

    void add(int index, int val) {
        // remove old
        for (auto& it : n1) {
            m[it + n2[index]]--;      // remove old
            m[it + n2[index]+val]++;  // add new
        }

        n2[index] += val;
    }

    int count(int tot) {
        return m[tot];
    }
};

class FindSumPairs {
public:
    unordered_map<int, int> m1, m2;
    vector<int> n1, n2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {

        n1 = nums1;
        n2 = nums2;

        for (auto& it : nums1) {
            m1[it]++;
        }

        for (auto& jt : nums2) {
            m2[jt]++;
        }
    }

    void add(int index, int val) {
        m2[n2[index]]--;  // remove old
        n2[index] += val;
        m2[n2[index]]++;   // add new
    }

    int count(int tot) {
        int ans = 0;
        for (auto& it : m1) {
            ans += m2[tot - it.first] * it.second;
        }
        return ans;
    }
};



/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */


int main() {
    char c;
    Solution sol;

    vector<int> plants = { 2, 2, 3, 3 };

    cout << sol.minimumRefill(plants, 5, 3);

    cin >> c;
}
