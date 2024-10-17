// trick : difficulty 가 같은 다른 work이 존재 하는경우 큰것을 선택 해야 함.. 
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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int l = difficulty.size();
        map<int, int> m;

        for (int i = 0; i < l; ++i) {
            m[difficulty[i]] = max(m[difficulty[i]], profit[i]);
        }

        int t_max = 0;
        for (auto& it : m) {
            t_max = max(t_max, it.second);
            m[it.first] = t_max;
        }

        int ans = 0;
        for (int i = 0; i < worker.size(); ++i) {
            // handle before - golden
            auto it = m.lower_bound(worker[i]);
            if (it == m.end()) --it;

            bool isSkip = false;
            while (worker[i] < (*it).first) {
                if (it == m.begin()) {
                    isSkip = true;
                    break;
                }
                it--;
            }

            if (isSkip) continue;

            ans += it->second;
        }
        return ans;

    }
};


int main() {
    char c;
    Solution sol;
    vector<int> difficulty = { 66,1,28,73,53,35,45,60,100,44,59,94,27,88,7,18,83,18,72,63 };
    vector<int> profit = { 66,20,84,81,56,40,37,82,53,45,43,96,67,27,12,54,98,19,47,77 };
    vector<int> worker = { 61,33,68,38,63,45,1,10,53,23,66,70,14,51,94,18,28,78,100,16 };


    cout << sol.maxProfitAssignment(difficulty, profit, worker);

    cin >> c;
}