// easy : _, -  till end 
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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> w = asteroids;

        vector<int> tw = asteroids;
        do {
            w = tw;
            tw.clear();

            for (int i = 0; i < w.size(); ++i) {
                if (i + 1 < w.size() && 0 < w[i] && w[i + 1] < 0) {
                    int l = abs(w[i]), r = abs(w[i + 1]);
                    if (l < r) {
                        tw.push_back(w[i + 1]);
                        i++;
                    }
                    else if (l > r) {
                        tw.push_back(w[i]);
                        i++;
                    }
                    else { // l == r
                        // expire both
                        i++;
                    }
                    continue;
                }
                tw.push_back(w[i]);
            }
        } while (w != tw);

        return tw;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> asteroids = {5, 10, -5};
    vector<int> asteroids = { -2,1,-1,-2 };

    vector<int> ans = sol.asteroidCollision(asteroids);

    for (auto& it : ans) {
        cout << it << " ";
    }

    //cout << "Test  application";

    cin >> c;
}
