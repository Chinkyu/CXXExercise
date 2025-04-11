//  ¥‰∫√¿Ω : b search
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

// OJ: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
// Author: github.com/lzl124631x
// Time: O(NlogT) where T is the maximum possible speed
// Space: O(1)
class Solution {
    bool valid(vector<int>& A, int speed, double hour) {
        double time = 0;
        for (int i = 0; i < A.size(); ++i) {
            time = ceil(time);
            time += (double)A[i] / speed;
            if (time > hour) return false;
        }
        return true;
    }
public:
    int minSpeedOnTime(vector<int>& A, double hour) {
        if (hour < A.size() - 1) return -1;
        long L = 1, R = 1e7;
        while (L <= R) {
            long M = (L + R) / 2;
            if (valid(A, M, hour)) R = M - 1;
            else L = M + 1;
        }
        return L > 1e7 ? -1 : L;
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