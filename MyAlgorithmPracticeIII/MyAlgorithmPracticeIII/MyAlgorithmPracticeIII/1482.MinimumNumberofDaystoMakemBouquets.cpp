// see answer : bsearch
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
public:
    int minDays(vector<int>& A, int m, int k) {
        int n = A.size(), left = 1, right = 1e9;
        if (m * k > n) return -1;
        while (left < right) {
            int mid = (left + right) / 2, flow = 0, bouq = 0;
            for (int j = 0; j < n; ++j) {
                if (A[j] > mid) {
                    flow = 0;
                }
                else if (++flow >= k) {
                    bouq++;
                    flow = 0;
                }
            }
            if (bouq < m) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,2 ,3 ,4 };
    vector<vector<int>> queries = { {1,0}, {-3,1}, {-4,0}, {2,3} };

    vector<int> ans = sol.sumEvenAfterQueries(nums, queries);

    for (auto& it : ans) {
        cout << it << " ";
    }


    cin >> c;
}
