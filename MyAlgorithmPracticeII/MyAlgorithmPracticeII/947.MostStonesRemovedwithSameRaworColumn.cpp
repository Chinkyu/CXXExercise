//   ¥‰∫√¿Ω : 
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

// Disjoint Set Union (DSU) or Union-Find data structure with union by size
struct DSU {
    vector<int> parent; // Parent array to represent the set each element belongs to
    vector<int> size;   // Size array to keep track of the size of each set

    // Constructor initializes parent and size arrays
    DSU(int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i); // Initially, each element is its own parent (self loop)
            size.push_back(1);   // Each element starts as a single set of size 1
        }
    }

    // Function to find the root parent of a node with path compression
    int findParent(int node) {
        if (parent[node] == node) return node; // If node is the parent of itself, return it

        // Path compression: make the root parent directly the parent of the node
        return parent[node] = findParent(parent[node]);
    }

    // Function to union two sets by their size
    void unionBySize(int u, int v) {
        int pu = findParent(u); // Find root parent of u
        int pv = findParent(v); // Find root parent of v

        if (pu == pv) return; // If they are already in the same set, do nothing

        // Union by size: attach the smaller set to the root of the larger set
        if (size[pu] > size[pv]) {
            parent[pv] = pu;   // Make pu the parent of pv
            size[pu] += size[pv]; // Increase the size of the set represented by pu
        }
        else {
            parent[pu] = pv;   // Make pv the parent of pu
            size[pv] += size[pu]; // Increase the size of the set represented by pv
        }
    }
};

class Solution {
public:
    // Function to compute the maximum number of stones that can be removed
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        // Find the maximum row and column indices
        for (int i = 0; i < n; i++) {
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }

        // Initialize DSU with the number of unique rows and columns
        DSU dsu(maxRow + maxCol + 1);
        int c = maxRow + maxCol + 2; // Maximum range for both rows and columns

        // Union rows and columns where stones are placed
        for (int i = 0; i < n; i++) {
            int u = stones[i][0];             // Row index
            int v = stones[i][1] + 1 + maxRow; // Column index offset by maxRow to avoid overlap with row indices
            dsu.unionBySize(u, v);            // Union the row and column indices
        }

        // Count the number of connected components with more than one stone
        for (int i = 0; i < c; i++) {
            if (dsu.parent[i] == i && dsu.size[i] > 1) n--;
        }

        return n; // Return the number of stones that can be removed
    }
};

int main() {
    char c;
    Solution sol;

    cout << sol.reorderedPowerOf2(16);

    cin >> c;
}