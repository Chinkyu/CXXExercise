// see anwser
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
    long long minOperations(vector<int>& A, vector<int>& B) {
        int v = B.back(), last = 1e9;
        long long res = 0;
        for (int i = 0; i < A.size(); ++i) {
            int a = A[i], b = B[i];
            res += abs(a - b);
            if ((a <= v && v <= b) || (b <= v && v <= a))
                last = 0;
            else {
                last = min(last, min(abs(a - v), abs(b - v)));
            }
        }
        return res + last + 1;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "UU";
    cout << sol.distinctPoints(s, 1);

    cin >> c;
}
