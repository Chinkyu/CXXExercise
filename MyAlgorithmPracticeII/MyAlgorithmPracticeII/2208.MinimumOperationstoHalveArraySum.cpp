//  easy : sort timeout, heap Ok.  
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
    int halveArray(vector<int>& nums) {

        vector<double> dn;

        double sum = 0;
        for (auto& it : nums) {
            dn.push_back(it);
            sum += it;
        }

        double csum = sum;
        int ans = 0;

        make_heap(dn.begin(), dn.end());
        do {
            pop_heap(dn.begin(), dn.end());
            double d = dn[dn.size() - 1];
            dn.pop_back();
            csum -= d / 2.0;
            dn.push_back(d / 2.0);
            push_heap(dn.begin(), dn.end());
            ans++;

        } while (sum / 2.0 < csum);

        return ans;
    }
};


// timeout 
class _Solution {
public:
    int halveArray(vector<int>& nums) {

        vector<double> dn;

        double sum = 0;
        for (auto& it : nums) {
            dn.push_back(it);
            sum += it;
        }

        double csum = sum;
        int ans = 0;
        do {
            sort(dn.begin(), dn.end());
            double d = dn[dn.size() - 1];
            dn.pop_back();
            csum -= d / 2.0;
            dn.push_back(d / 2.0);

            ans++;

        } while (sum / 2.0 < csum);

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 5,19,8,1 };

    cout << sol.halveArray(nums);

    cin >> c;
}