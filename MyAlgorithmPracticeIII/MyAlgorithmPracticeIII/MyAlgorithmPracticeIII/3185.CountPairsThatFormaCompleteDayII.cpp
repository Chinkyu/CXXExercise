//ok..  asymatic answer divide by 2 because of duplication

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
#include <random>
#include <chrono>
#include <iterator>

using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int l = hours.size();
        map<int, int> m;

        for (int i = 0; i < l; ++i) {
            m[hours[i] % 24]++;
        }

        long long ans = 0;
        long long aans = 0;
        for (auto& it : m) {
            if (it.first == 0 || it.first == 12) {
                // numC2
                ans += ((long long)it.second * (it.second - 1)) / 2;
            }
            else {
                if (m.find(24 - it.first) != m.end()) {
                    aans += it.second * (long long)m[24 - it.first];
                }
            }
        }

        ans += aans / 2;
        return ans;

    }
};

int main() {
    char c;
    Solution sol;

    string s = "00011000";
    cout << sol.minFlipsMonoIncr(s);


    cin >> c;
}
