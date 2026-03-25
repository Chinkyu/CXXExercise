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
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int l = hand.size();

        map<int, int> m;
        for (auto& it : hand) {
            m[it]++;
        }

        if (l % groupSize != 0) return false;

        while (m.size() > 0) {
            int s = m.begin()->first;

            for (int i = 0; i < groupSize; ++i) {
                if (m[s + i] <= 0) return false;
                m[s + i]--;
                if (m[s + i] == 0) {
                    m.erase(s + i);
                }
            }
        }
        
        return true;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> edges = { {1, 0}, {1, 2}, {1, 3} };
    //"baeyh";

    vector<int> ans = sol.findMinHeightTrees(4, edges);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
