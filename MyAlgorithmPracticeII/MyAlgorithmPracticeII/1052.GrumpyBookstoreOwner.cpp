//  mid : tricky to resolve timeout 
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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l = customers.size();
        int ans = 0;

        int osum = 0;
        for (int i = 0; i < l; ++i) {
            osum += (grumpy[i] == 0) ? customers[i] : 0;
        }
        ans = osum;
        for (int i = 0; i < l; ++i) {
            int tsum = osum;

            for (int j = i; j < i + minutes; ++j) {
                if (grumpy.size() <= j) break;
                tsum += (grumpy[j] == 0) ? 0 : customers[j];
            }

            ans = max(ans, tsum);
        }

        return ans;
    }
};


// timeout 
class _Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l = customers.size();
        int ans = 0;

        int tsum = 0;
        for (int i = 0; i < l; ++i) {
            tsum += (grumpy[i] == 0)? customers[i] : 0;
        }
        ans = tsum;
        for (int i = 0; i < l; ++i) {
            vector<int> tgrumpy = grumpy;

            for (int j = i; j < i + minutes; ++j) {
                if (tgrumpy.size() <= j) break;
                tgrumpy[j] = 0;
            }

            tsum = 0;
            for (int i = 0; i < l; ++i) {
                tsum += (tgrumpy[i] == 0) ? customers[i] : 0;
            }

            ans = max(ans, tsum);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> customers = { 1,0,1,2,1,1,7,5 };
    vector<int> grumpy = { 0,1,0,1,0,1,0,1 };

    cout << sol.maxSatisfied(customers, grumpy, 3);

    cin >> c;
}