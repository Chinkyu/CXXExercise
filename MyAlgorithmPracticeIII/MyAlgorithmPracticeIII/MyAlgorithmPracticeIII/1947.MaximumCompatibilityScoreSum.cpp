// because n, m is small.... can do this  : try everything 

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
#include <numeric>

using namespace std;

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size();
        vector<vector<int>> score(n, vector<int>(n, 0));

        for (int i = 0; i < students.size(); ++i) {
            for (int j = 0; j < mentors.size(); ++j) {

                int cnt = 0;
                for (int k = 0; k < students[0].size(); ++k) {
                    if (students[i][k] == mentors[j][k]) cnt++;
                }
                score[i][j] = cnt;
            }
        }

        vector<int> mi(n);
        iota(mi.begin(), mi.end(), 0); // from 0 to n - 1;

        int ans = 0;
        do {

            int t_max = 0;

            for (int i = 0; i < n; ++i) {
                t_max += score[i][mi[i]];
            }

            ans = max(ans, t_max);

        } while (next_permutation(mi.begin(), mi.end()));

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> segments = { {1, 4, 5}, {4, 7, 7}, {1, 7, 9} };

    vector<vector<long long>> ans = sol.splitPainting(segments);
    for (auto& it : ans) {
        cout << it[0] << " " << it[1] << " " << it[2] << endl;
    }

    cin >> c;
}
