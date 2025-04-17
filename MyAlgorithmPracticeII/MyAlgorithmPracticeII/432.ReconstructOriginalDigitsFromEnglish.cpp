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
    const int DIGS[10] = { 0,2,4,6,8,5,7,3,9,1 }, CHARS[10] = { 25,22,20,23,6,5,18,7,8,14 };
    const vector<vector<int>> REMS = { {14},{14},{5,14},{18,8},{8,7},{8},{},{},{},{} };
public:
    string originalDigits(string S) {
        int fmap[26] = { 0 }, ans[10] = { 0 };
        for (char c : S) fmap[c - 97]++;
        for (int i = 0; i < 10; i++) {
            int count = fmap[CHARS[i]];
            for (int rem : REMS[i]) fmap[rem] -= count;
            ans[DIGS[i]] = count;
        }
        string ansstr;
        for (int i = 0; i < 10; i++) {
            char c = (char)(i + 48);
            for (int j = ans[i]; j; j--)
                ansstr += c;
        }
        return ansstr;
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