// see answer : find circle .  k size circle need k - 1 swap.. 
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
    int findsum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;

        sort(v.begin(), v.end(), [&](int a, int b) {
            int sumA = findsum(a);
            int sumB = findsum(b);
            if (sumA == sumB) return a < b;
            return sumA < sumB;
            });

        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]] = i;
        }

        vector<bool> visited(n, false);
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || v[i] == nums[i]) continue;

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = mp[v[j]];
                cycle_size++;
            }

            if (cycle_size > 1) {
                cnt += (cycle_size - 1);
            }
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    char c;

    sol.combine(4, 2);

    cin >> c;
}
