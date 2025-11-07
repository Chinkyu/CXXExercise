// see answer : 
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

using namespace std;

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int low = 0, high = price[n - 1] - price[0], ans = 0;

        auto canPick = [&](int d) {
            int count = 1, last = price[0];
            for (int i = 1; i < n; i++) {
                if (price[i] - last >= d) {
                    count++;
                    last = price[i];
                }
                if (count >= k) return true;
            }
            return false;
            };

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPick(mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    char c;
    vector<string> creators = { "alice", "bob", "alice", "chris" };
    vector<string> ids = { "one", "two", "three", "four" };
    vector<int> views = { 5, 10, 5, 4 };

    vector<vector<string>> ans = sol.mostPopularCreator(creators, ids, views);

    for (auto it : ans) {
        cout << it[0] << " " << it[1] << endl;
    }


    cin >> c;
}
