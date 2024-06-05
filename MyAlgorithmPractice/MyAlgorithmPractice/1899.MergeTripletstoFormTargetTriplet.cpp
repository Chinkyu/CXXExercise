// easy
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

using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        bool is0 = false, is1 = false, is2 = false;

        for (auto& it : triplets) {

            if (it[0] > target[0] || it[1] > target[1] || it[2] > target[2]) continue;

            if (it[0] == target[0]) is0 = true;
            if (it[1] == target[1]) is1 = true;
            if (it[2] == target[2]) is2 = true;
        }

        if (is0 == true && is1 == true && is2 == true) return true;
        return false;

    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> triplets = {{2, 5, 3}, {1, 8, 4}, {1, 7, 5}};
    vector<int> target = { 2, 7, 5 };
    cout << sol.mergeTriplets(triplets, target);
    cin >> c;
}