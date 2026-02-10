// see answer : reverse  n 개 부터 붙이기... : 놀라운 알고르즘임... 
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
private:
    vector<int> parent;
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            parent[i] = j;
            return true;
        }
        return false;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        if (edges.empty()) {
            return 0;
        }

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
            });

        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);  // parents 에 자기 값.. 

        int count = n;
        for (const auto& e : edges) {
            int u = e[0], v = e[1], t = e[2];
            if (unite(u, v)) {
                count--;
            }
            if (count < k) {
                return t;
            }
        }
        return 0;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,0,-1,0,-2,2 };

    vector<vector<int>> ans = sol.fourSum(nums, 0);

    for (auto& it : ans) {
        cout << it[0] << "," << it[1] << "," << it[2] << "." << it[3];
    }


    cin >> c;
}
