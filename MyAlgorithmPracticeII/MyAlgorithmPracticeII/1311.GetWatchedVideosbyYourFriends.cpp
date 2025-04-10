//  답봤음 : 문제 잘못 이해.. = skip
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
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<string, int> m;
        queue<int> q;
        
        for(auto it : friends[id]) q.push(it);

        for (int i = 0; i < level; ++i) {
            queue<int> tq;
            while(!q.empty()) {
                int f = q.front();
                q.pop();

                for (auto it : watchedVideos[f]) m[it]++;
                for (auto it : friends[f]) {
                    tq.push(it);
                }
            }
            q = tq;
        }

        vector<pair<string, int>> v;
        for (auto it : m) {
            v.push_back(make_pair(it.first, it.second));
        }

        sort(v.begin(), v.end(), [](pair<string, int>& l, pair<string, int>& r) {
            if (l.second == r.second) return l.first < r.first;
            return l.second < r.second;
        });

        vector<string> ans;
        for (auto it : v) {
            ans.push_back(it.first);
        }

        return ans;

    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<string>> watchedVideos = {{"A", "B"}, {"C"}, {"B", "C"}, {"D"}};
    vector<vector<int>> friends = {{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    int id = 0;
    int level = 1;


    vector<string> ans = sol.watchedVideosByFriends(watchedVideos, friends, id, level);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}