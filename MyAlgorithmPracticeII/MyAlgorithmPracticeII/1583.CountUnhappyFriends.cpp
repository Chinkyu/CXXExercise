// easy : 
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
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<int> couple(n);
        for (auto& it : pairs) {
            couple[it[0]] = it[1];
            couple[it[1]] = it[0];
        }

        vector<unordered_map<int, int>> like(n, unordered_map<int, int>());
        for (int i = 0; i < preferences.size(); ++i) {
            for (int j = 0; j < n - 1; ++j) {
                like[i][preferences[i][j]] = j;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int mate = couple[i];

            // search who like more than mate
            for (int j = 0; j < like[i][mate]; ++j) {
                int moreLover = preferences[i][j];
                int moreLoversMateRank = like[moreLover][couple[moreLover]];
                int moreLoversMyRank = like[moreLover][i];
                if (moreLoversMyRank < moreLoversMateRank) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> preferences = {{1, 3, 2}, {2, 3, 0}, {1, 3, 0}, {0, 2, 1}};
    vector<vector<int>> pairs = {{1, 3}, {0, 2}};
    cout << sol.unhappyFriends(4, preferences, pairs);
    cin >> c;
}