//  ¥‰∫√¿Ω
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

class _Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {

        unordered_map<int, int> fm, sm;

        for (int i = 0; i < coordinates.size() - 1; ++i) {
            for (int j = 1; j < coordinates.size(); ++j) {
                fm[coordinates[i][0] ^ coordinates[j][0]]++;
            }
        }

        for (int i = 0; i < coordinates.size() - 1; ++i) {
            for (int j = 1; j < coordinates.size(); ++j) {
                sm[coordinates[i][1] ^ coordinates[j][1]]++;
            }
        }

        int ans = 0;
        for (auto& it : fm) {
            if (sm.find(k - it.first) != sm.end()) {
                ans += it.second * sm[k - it.first];
            }
        }

        return ans;

    }
};

// timeout 
class _Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {

        int ans = 0;
        for (int i = 0; i < coordinates.size() - 1; ++i) {
            for (int j = i + 1; j < coordinates.size(); ++j) {
                if ((coordinates[i][0] ^ coordinates[j][0]) + (coordinates[i][1] ^ coordinates[j][1]) == k) {
                    ans++;
                }
            }
        }

        return ans;

    }
};

class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        // Create a map to store the frequency of each coordinate in the input vector
        map<vector<int>, int> m;

        // Iterate through the input coordinates and populate the map
        for (auto it : coordinates) {
            m[it]++;
        }

        long long ans = 0; // Initialize the answer variable

        if (k == 0) {
            // If k is 0, count pairs with the same coordinates
            for (auto it : m) {
                ans += it.second * 1ll * (it.second - 1) / 2; // Count pairs using combination formula
            }
            return ans; // Return the total count of pairs
        }
        else {
            // If k is not 0, count pairs with XOR distance equal to k
            for (auto& it : m) {
                for (int j = 0; j <= k; j++) {
                    vector<int> x = { it.first[0] ^ j, it.first[1] ^ (k - j) };
                    // Calculate the complementary coordinate using XOR
                    if (m.find(x) != m.end()) {
                        ans += m[x] * it.second; // Increment answer by the product of frequencies
                    }
                }
            }
            return ans / 2; // Divide the answer by 2 to avoid double counting
        }
    }
};



int main() {
    char c;
    Solution sol;
    vector<vector<int>> nums = { {1,3},{1,3},{1,3},{1,3},{1,3} };

    cout << sol.countPairs(nums, 0);

    cin >> c;
}