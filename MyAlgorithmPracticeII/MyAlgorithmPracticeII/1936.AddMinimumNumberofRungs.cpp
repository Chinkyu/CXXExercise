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
    int addRungs(vector<int>& rungs, int dist) {

        int ans = 0;
        int pre = 0;
        for (int i = 0; i < rungs.size(); ++i) {
            int a = (rungs[i] - pre) / dist;
            if ((rungs[i] - pre) % dist ==  0) a--;
            ans += a;
            pre = rungs[i];
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> rungs = { 1,3,5,10 };

    cout << sol.addRungs(rungs, 2);

    cin >> c;
}