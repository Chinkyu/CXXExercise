//  see sol : 다익... 스트라..
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
#include <set>
#include <list>
#include <regex>
#include <memory>
#include <functional>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> dis(rows, vector<int>(cols, INT_MAX));
        dis[0][0] = 0;
        pq.push({ 0, {0, 0} });

        while (!pq.empty()) {
            pair<int, pair<int, int>> topElement = pq.top();
            pq.pop();

            int currAdjDistance = topElement.first;
            int xC = topElement.second.first;
            int yC = topElement.second.second;

            if (xC == rows - 1 && yC == cols - 1) {
                return dis[xC][yC];
            }
            else {
                int xMove[] = { -1, 0, 1, 0 };
                int yMove[] = { 0, 1, 0, -1 };

                for (int i = 0; i < 4; i++) {
                    int newX = xC + xMove[i];
                    int newY = yC + yMove[i];

                    if (newX < rows && newY < cols && newX >= 0 && newY >= 0) {
                        int absDistance = abs(heights[xC][yC] - heights[newX][newY]);
                        int maxDifference = max(absDistance, currAdjDistance);

                        if (maxDifference < dis[newX][newY]) {
                            dis[newX][newY] = maxDifference;
                            pq.push({ maxDifference, {newX, newY} });
                        }
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<string>> access_times = { {"a", "0549"}, {"b", "0457"}, {"a", "0532"}, {"a", "0621"}, {"b", "0540"} };

    vector<string> ans = sol.findHighAccessEmployees(access_times);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}