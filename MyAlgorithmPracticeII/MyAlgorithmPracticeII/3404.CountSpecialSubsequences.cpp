// easy : 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
    long long numberOfSubsequences(vector<int>& A) {
        int n = A.size();
        long long res = 0;
        unordered_map<double, int> cnt;
        for (int r = 4; r < n - 2; ++r) {
            int q = r - 2;
            for (int p = 0; p < q - 1; ++p)
                cnt[1.0 * A[p] / A[q]]++;
            for (int s = r + 2; s < n; ++s)
                res += cnt[1.0 * A[s] / A[r]];
        }
        return res;
    }
};

int main() {
    Solution sol;
    char c;
    vector<int> nums = { 1, 2, 3, 4 };

    cout << sol.rangeSum(nums, 4, 1, 5);

    cin >> c;
}
