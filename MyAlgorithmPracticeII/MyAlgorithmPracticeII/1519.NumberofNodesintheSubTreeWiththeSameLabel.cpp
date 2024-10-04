// easy : tricky to build tree.......   
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

    void traverse(vector<vector<int>>& tree, string &labels, int node, unordered_map<char, int> &charCount, vector<int> &ans) {

        for (auto& it : tree[node]) {
            unordered_map<char, int> t_charCount;
            traverse(tree, labels, it, t_charCount,ans);

            for (auto& it : t_charCount) charCount[it.first] += it.second;

        }

        charCount[labels[node]]++;
        ans[node] = charCount[labels[node]];
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> tree(n);

        set<int> s;
        s.insert(0);
        for (auto& it : edges) {
            if (s.find(it[0]) != s.end()) {
                tree[it[0]].push_back(it[1]);
                s.insert(it[1]);
            } else {
                tree[it[1]].push_back(it[0]);
                s.insert(it[0]);
            }
        }

        unordered_map<char, int> charCount;
        vector<int> ans(n);

        traverse(tree, labels, 0, charCount, ans);

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> edges = { {0, 1},{0, 2},{1, 4},{1, 5},{2, 3},{2, 6} };
    string labels = "abaedcd";
    vector<int> ans =  sol.countSubTrees(7, edges, labels);

    for (auto& it : ans) {
        cout << it << " ";
    }


    cin >> c;
}