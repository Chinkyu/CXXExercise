// ok : really not timeout??
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

class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int l = nums.size();
        map<int, int> m;

        for (int i = 0; i < l; ++i) {
            m[nums[i]]++;
        }

        int ans = 0;
        int total = l;
        for (auto& it : m) {
            total -= it.second;
            if (total >= k) {
                ans += it.second;
            }


        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    vector<string> ans = sol.findRepeatedDnaSequences(s);
    for (auto& it : ans) {
        cout << it << endl;
    }



    cin >> c;
}
