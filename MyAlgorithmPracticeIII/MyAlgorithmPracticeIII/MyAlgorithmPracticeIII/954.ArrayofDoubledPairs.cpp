// tricky debugging.. may be bad algorithm. 
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
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> m;

        for (auto& it : arr) {
            m[it]++;
        }

        int l = m.size();
        auto it = m.begin();
        while(it != m.end()) {
            int v = it->first;

            if (v == 0) {
                if (it->second % 2 != 0) return false;
                it++;
                continue;
            }

            if (v < 0) {
                if ((double)v / 2 != v / 2) return false;
                v = v / 2;
            }
            else {
                v = v * 2;
            }

            // may check v could be one of *2;
            if (m.find(v) == m.end() ) {
                return false;
            }

            if (m[v] >= it->second) {
                m[v] -= it->second;

                if (m[v] == 0) {
                    m.erase(v);
                }
            }
            else {
                return false;
            }

            it++;
        }

        return true;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> arr = { 2, 4, 0, 0, 8, 1 };
    //{ -8, -4, -2, -1, 0, 0, 1, 2, 4, 8 };
    //{ -5, -2 };
    //{ 4, -2, 2, -4 };
   //{ 3, 1, 3, 6 };

   cout << sol.canReorderDoubled(arr);

    cin >> c;
}
