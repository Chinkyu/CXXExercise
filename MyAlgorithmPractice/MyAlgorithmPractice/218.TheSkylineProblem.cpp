// ¥‰∫√¿Ω... : sliding windows
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
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> pq{ 0 };

        vector<pair<int, int>> points;

        for (auto b : buildings) {
            points.push_back({ b[0], -b[2] });
            points.push_back({ b[1], b[2] });
        }

        sort(points.begin(), points.end());

        int ongoingHeight = 0;

        // points.first = x coordinate, points.second = height
        for (int i = 0; i < points.size(); i++) {
            int currentPoint = points[i].first;
            int heightAtCurrentPoint = points[i].second;

            if (heightAtCurrentPoint < 0) {
                pq.insert(-heightAtCurrentPoint);
            }
            else {
                pq.erase(pq.find(heightAtCurrentPoint));
            }

            // after inserting/removing heightAtI, if there's a change
            auto pqTop = *pq.rbegin();
            if (ongoingHeight != pqTop) {
                ongoingHeight = pqTop;
                ans.push_back({ currentPoint, ongoingHeight });
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    char c;

    //	vector<vector<char>> mat =
    //	{
    //			{'o', 'a', 'a', 'n'},
    //			{'e', 't', 'a', 'e'},
    //			{'i', 'h', 'k', 'r'},
    //			{'i', 'f', 'l', 'v'}
    //	};

    //	vector<string> words = { "oath", "pea", "eat", "rain" };

    vector<vector<char>> mat =
    {
            {'a', 'b'},
            {'c', 'd'}
    };

    vector<string> words = { "ab", "cb", "ad", "bd", "ac", "ca", "da", "bc", "db", "adcb", "dabc", "abb", "acb" };
    //vector<string> words = { "ac", "ca", "db" };


    vector<string> ans = sol.findWords(mat, words);
    for (auto it : ans) {
        cout << it.c_str() << endl;
    }

    cin >> c;
}
