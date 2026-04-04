// ok : exception   total size is shorter than k
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

// dp. 
class Solution
{
public:
    int numSquares(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Note that cntPerfectSquares[0] is 0.
        vector<int> cntPerfectSquares(n + 1, INT_MAX);
        cntPerfectSquares[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            // For each i, it must be the sum of some number (i - j*j) and 
            // a perfect square number (j*j).
            for (int j = 1; j * j <= i; j++)
            {
                cntPerfectSquares[i] =
                    min(cntPerfectSquares[i], cntPerfectSquares[i - j * j] + 1);
            }
        }

        return cntPerfectSquares.back();
    }
};

// not sloution 
class _Solution {
public:
    int numSquares(int n) {

        int ans = 0;

        while (n > 0) {
            int sq = pow((int)sqrt(n), 2);
            n -= sq;
            ans++;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "au";
    //"abcabcbb";

    cout << sol.numSquares(12);

    cin >> c;
}
