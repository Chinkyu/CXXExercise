// ok : using priority queue : need memorize how to use priority queue?

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
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first; // Min-heap
        }
    };

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix.size();
        priority_queue < pair<int, int>, vector<pair<int, int>>, Compare> pq;
        vector<int> idx(l, 1);

        for (int i = 0; i < l; ++i) {
            pq.push(make_pair(matrix[i][0], i));
        }

        int ith = 1;
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans = pq.top().first;
            int topidx = pq.top().second;
            if (idx[topidx] < l) {
                pq.push(make_pair(matrix[topidx][idx[topidx]], topidx));
                idx[topidx]++;
            }
            pq.pop();
        }
        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> matrix = { {1, 5, 9},{10, 11, 13},{12, 13, 15} };

    cout << sol.kthSmallest(matrix, 8);

    cin >> c;
}