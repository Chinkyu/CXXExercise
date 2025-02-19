// see answer : ¹Ø¿¡¼­ ºÎÅÍ Â÷°îÂ÷°î.. 

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
    int maxDistinctElements(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int l = INT_MIN;
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int mi = nums[i] - k;
            int mx = nums[i] + k;

            if (l < mi) { l = mi; ans++; }
            else if (l < mx) { l = l + 1; ans++; }

        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> queries = { "bbb", "cc" };
    vector<string> words = { "a", "aa", "aaa", "aaaa" };

    vector<int> ans = sol.numSmallerByFrequency(queries, words);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}