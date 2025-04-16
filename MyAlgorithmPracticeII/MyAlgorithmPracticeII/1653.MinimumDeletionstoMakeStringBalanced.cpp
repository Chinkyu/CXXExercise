//  ¥‰∫√¿Ω :
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
    int minimumDeletions(string s) {
        int res = 0, count = 0;
        for (char c : s) {
            if (c == 'b')
                count++;
            else if (count) {
                res++;
                count--;
            }
        }
        return res;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<string>> watchedVideos = { {"A", "B"}, {"C"}, {"B", "C"}, {"D"} };
    vector<vector<int>> friends = { {1, 2}, {0, 3}, {0, 3}, {1, 2} };
    int id = 0;
    int level = 1;


    vector<string> ans = sol.watchedVideosByFriends(watchedVideos, friends, id, level);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}