// easy
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;

        for (auto& it : tasks) {
            m[it]++;
        }

        int ans = 0;
        for (auto& it : m) {
            int div = it.second / 3;
            int rem = it.second % 3;

            if (it.second <= 1) {
                return -1;
            } 

            ans += div;
            if (rem > 0) ans++;
        }

        return ans;

    }
};

int main() {
    Solution sol;
    char c;
    vector<int> tasks = { 2,2,3,3,2,4,4,4,4,4 };

    cout << sol.minimumRounds(tasks);

    cin >> c;
}
