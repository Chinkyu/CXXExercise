// see answer
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
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // min priority queue
        priority_queue<array<long, 3>, vector<array<long, 3>>, greater<array<long, 3>>> avail, busy;
        vector<int> res;
        for (int i = 0; i < servers.size(); ++i)
            avail.push({ 0, servers[i], i });
        for (long t = 0; t < tasks.size(); ++t) {
            while (!busy.empty() && (busy.top()[0] <= t || avail.empty())) {
                auto [time, w, i] = busy.top(); busy.pop();
                avail.push({ time <= t ? 0 : time, w, i });
            }
            auto [time, w, s] = avail.top(); avail.pop();
            busy.push({ max(time, t) + tasks[t], w, s });
            res.push_back(s);
        }
        return res;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> numbers = { 2, 7, 11, 15 };

    vector<int> ans = sol.twoSum(numbers, 9);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
