// see answer : mono stack 
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
    long long bowlSubarrays(vector<int>& A) {
        long long res = 0;
        vector<int> s;
        for (int r = 0; r < A.size(); ++r) {
            int a = A[r];
            while (!s.empty() && A[s.back()] <= a) {
                int l = s.back();
                s.pop_back();
                if (r - l + 1 >= 3) {
                    res += 1;
                }
            }
            if (!s.empty() && r - s.back() + 1 >= 3) {
                res += 1;
            }
            s.push_back(r);
        }
        return res;
    }
};


int main() {
    Solution sol;
    char c;
    //vector<vector<int>> reservedSeats = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    //vector<vector<int>> reservedSeats = { {4, 3}, {1, 4}, {4, 6}, {1, 7} };
    //vector<vector<int>> reservedSeats = { {2, 1}, {1, 8}, {2, 6} };
    vector<vector<int>> reservedSeats = { {2, 3} };

    cout << sol.maxNumberOfFamilies(3, reservedSeats);

    cin >> c;
}
