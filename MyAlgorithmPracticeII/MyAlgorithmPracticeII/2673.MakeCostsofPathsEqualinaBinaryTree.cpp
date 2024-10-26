// 답봤음...
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

// 아래에서 위로 올라가면서 맟줘야 된다네..Child 를 포함해서....
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int res = 0;
        function<int(int)> dfs = [&](int i) {
            if (i >= cost.size()) return 0;
            int a = dfs(2 * i + 1), b = dfs(2 * i + 2);
            res += abs(a - b);
            return cost[i] + max(a, b);
            };
        dfs(0);
        return res;
    }
};

// 같은 층을 max 로 맞추는것은 해결책이 아님.. 
class _Solution {
public:
    int minIncrements(int n, vector<int>& cost) {

        int idx = 0;
        int ans = 0;

        for (int i = 0; idx < n; ++i) {
            int num = pow(2, i);
            int tmax = 0;
            int sum = 0;
            for (int j = 0; j < num; ++j) {
                sum += cost[idx];
                tmax = max(tmax, cost[idx]);
                idx++;
            }
            ans += (tmax * num) - sum;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<int> cost = { 1,5,2,2,3,3,1 }; 

    cout << sol.minIncrements(7, cost);

    cin >> c;
}