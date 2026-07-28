// ok
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
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        int l = asteroids.size();
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;

        for (int i = 0; i < l; ++i) {
            if (asteroids[i] > m) {
                return false;
            }

            m += asteroids[i];
        }

        return true;
    }
};


int main() {
    char c;
    Solution sol;

    vector<int> v = { 1, 2, 3, 4 };

    sol.buildBTS(v, 0, v.size() - 1);

    //    cout << sol.angleClock(1, 57);


    cin >> c;
}
