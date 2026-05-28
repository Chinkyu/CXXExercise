// ok : need to think left and right separately
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
    int maxDistToClosest(vector<int>& seats) {
        int l = seats.size();

        int st = -1;
        int ldist = 0, mdist = 1, rdist = 0;
        int ans = 0;

        // left 
        int ldx = 0;
        if (seats[0] == 0) {
            while (seats[ldx] == 0) ldx++;
            ldist = ldx;
        }
        ans = max(ans, ldist);

        int rdx = l - 1;
        if (seats[rdx] == 0) {
            while (seats[rdx] == 0) rdx--;
            rdist = l - 1 - rdx;
        }
        ans = max(ans, rdist);

        for (int i = ldx; i <= rdx; ++i) {
            if (seats[i] == 1) {
                if (i - st > mdist) {
                    mdist = max(mdist, i - st);
                }
                st = i;
            }
        }
        ans = max(ans, mdist / 2);

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    
    vector<int> seats = { 1, 0, 0 , 0 };

    cout << sol.maxDistToClosest(seats);

    cin >> c;
}
