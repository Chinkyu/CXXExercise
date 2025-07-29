// saw anser : BFS.  get from n1, n2 for all and check for anser for each 

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
#include <cmath>
#include <regex>
#include <memory>

using namespace std;


class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1 = getDistances(edges, node1);
        vector<int> dist2 = getDistances(edges, node2);
        int result = -1;
        int minDistance = INT_MAX;

        for (int i = 0; i < edges.size(); i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDistance) {
                    minDistance = maxDist;
                    result = i;
                }
            }
        }
        return result;
    }

private:
    vector<int> getDistances(const vector<int>& edges, int start) {
        int n = edges.size();
        vector<int> dist(n, -1);
        int d = 0;
        while (start != -1 && dist[start] == -1) {
            dist[start] = d++;
            start = edges[start];
        }
        return dist;
    }
};


int main() {
    char c;
    Solution sol;

    //string num1 = "9", num2 = "99";

    vector<int> ans = sol.closestDivisors(999);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}