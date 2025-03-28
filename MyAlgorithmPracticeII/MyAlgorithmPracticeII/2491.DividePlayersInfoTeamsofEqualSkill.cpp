// OK. : 

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
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        int l = skill.size();
        map<int, int> m;
        for (auto it : skill) {
            m[it]++;
            sum += it;
        }

        int team_sum = sum / (l / 2);
        long long ans = 0;

        for (auto it : m) {
            if (it.first == 0) continue;

            int num = it.first;
            if (m[team_sum - num] != it.second) {
                return -1;
            }

            if (num == team_sum - num) {
                ans += (long long)(num * (team_sum - num)) * (it.second/2);
            }
            else {
                ans += (num * (team_sum - num)) * it.second;
            }
            m[num] = 0;
            m[team_sum - num] = 0;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> skill = { 3,2,5,1,3,4 };
    cout << sol.dividePlayers(skill);

    cin >> c;
}