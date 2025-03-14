// ok : check one by one 

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
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {

        vector<vector<int>> v(n, vector<int>(n, 0));

        for (auto it : dig) {
            v[it[0]][it[1]] = 1;
        }

        int ans = 0;

        for (int i = 0; i < artifacts.size(); ++i) {
            bool not_extracted = false;
            for (int j = artifacts[i][0]; j <= artifacts[i][2]; ++j) {
                for (int k = artifacts[i][1]; k <= artifacts[i][3]; ++k) {
                    if (v[j][k] != 1) {
                        not_extracted = true;
                        goto NEXT;
                    }
                }
            }
NEXT:
            if (not_extracted == false) ans++;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> artifacts = { {0, 0, 0, 0}, {0, 1, 1, 1} };
    vector<vector<int>> dig = { {0, 0}, {0, 1} };

    cout << sol.digArtifacts(2, artifacts, dig);

    cin >> c;
}