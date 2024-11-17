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

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {

        int ans = 0;
        int st = bottom-1;

        special.push_back(top + 1);
        sort(special.begin(), special.end());

        for (int i = 0; i < special.size(); ++i) {
            ans = max(ans, special[i] - st);
            st = special[i];
        }

        return ans - 1;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> special = { 4, 6 };

    cout << sol.maxConsecutive(2, 9, special);

    cin >> c;
}