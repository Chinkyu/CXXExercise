//  see answer - - bsearch

// About binary bit tree 
// https://velog.io/@kimgwon/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%B0%94%EC%9D%B4%EB%84%88%EB%A6%AC-%EC%9D%B8%EB%8D%B1%EC%8A%A4-%ED%8A%B8%EB%A6%ACBinary-Index-Tree-%ED%8E%9C%EC%9C%85-%ED%8A%B8%EB%A6%AC


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
#include <bit>

using namespace std;

class Solution {
public:
    // Check if we can place 'm' balls at 'position'
    // with each ball having at least 'x' gap.
    bool canPlaceBalls(int x, vector<int>& position, int m) {
        // Place the first ball at the first position.
        int prevBallPos = position[0];
        int ballsPlaced = 1;

        // Iterate on each 'position' and place a ball there if we can place it.
        for (int i = 1; i < position.size() && ballsPlaced < m; ++i) {
            int currPos = position[i];
            // Check if we can place the ball at the current position.
            if (currPos - prevBallPos >= x) {
                ballsPlaced += 1;
                prevBallPos = currPos;
            }
        }
        // If all 'm' balls are placed, return 'true'.
        return ballsPlaced == m;
    }

    int maxDistance(vector<int>& position, int m) {
        int answer = 0;
        int n = position.size();
        sort(position.begin(), position.end());

        // Initial search space.
        int low = 1;
        int high = ceil(position[n - 1] / (m - 1.0));
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // If we can place all balls having a gap at least 'mid',
            if (canPlaceBalls(mid, position, m)) {
                // then 'mid' can be our answer,
                answer = mid;
                // and discard the left half search space.
                low = mid + 1;
            }
            else {
                // Discard the right half search space.
                high = mid - 1;
            }
        }
        return answer;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
    char c;

    vector<int> n = { 1, 3, 5 };

    NumArray sol(n);
    cout << sol.sumRange(0, 2) << " ";
    sol.update(1, 2);
    cout << sol.sumRange(0, 2);

    cin >> c;
}

