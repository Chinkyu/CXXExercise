//  easy
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

class StockSpanner {
public:
    vector<int> v;
    StockSpanner() {
        v.clear();
    }

    int next(int price) {
        int ans = 0;
        v.push_back(price);
        for (int i = v.size() - 1; i >= 0; --i) {
            if (v[i] <= price) {
                ans++;
            }
            else {
                return ans;
            }
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
    char c;
    Solution sol;

    cout << sol.reorderedPowerOf2(16);

    cin >> c;
}