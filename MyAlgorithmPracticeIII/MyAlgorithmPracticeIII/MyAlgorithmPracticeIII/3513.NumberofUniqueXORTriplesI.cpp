// see answer by math just counting 
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

/*
observe the pattern:

    n=3 --> 4 unique values
    n=4,5,6,7 --> 8 unique values
    n=8,9...15 --> 16 unique values

answer doubles every time n crosses a power of 2. that's exactly what floor(log2(n)) tracks which "zone" between powers of 2 we are in, so answer is always 2^(floor(log2(n))+1)
*/

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // cant form triplets
        int bits = log2(n);   // which power of 2 are we at
        return 1 << (bits + 1); // next power of 2 = total unique xor values
    }
};


// Timeout   -> Tomorrow..!!!!!! 
class _Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int l = nums.size();
        set<int> s;

        for (auto it : nums) s.insert(it);


        for (int i = 0; i < l - 2; ++i) {
            for (int j = i + 1; j < l - 1; ++j) {
                for (int k = j + 1; k < l; ++k) {
                    int t = nums[i] ^ nums[j] ^ nums[k];
                    s.insert(t);
                }
            }
        }

        return s.size();
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 3, 1, 2 };
    cout << sol.uniqueXorTriplets(nums);

    cin >> c;
}
