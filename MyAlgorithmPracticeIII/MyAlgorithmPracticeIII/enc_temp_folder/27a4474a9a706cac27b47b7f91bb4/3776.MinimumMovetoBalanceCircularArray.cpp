// ok : 
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
    long long minMoves(vector<int>& balance) {
        int l = balance.size();
        long long sum = 0;
        
        // find minus
        bool haveMinus = false;
        int mIndex = -1;
        int mValue = 0;
        for (int i = 0; i < l; ++i) {
            sum += balance[i];
            if (balance[i] < 0) {
                haveMinus = true;
                mIndex = i;
                mValue = balance[i];
            }
        }

        if (haveMinus == false) return 0;
        if (sum < 0) return -1;

        // sort array
        vector<int> srt;

        for (int i = 1; (0 <= mIndex - i) || (mIndex + i < l); ++i) {
            int s = 0;
            if (0 <= mIndex - i) s += balance[mIndex - i];
            if (mIndex + i < l) s += balance[mIndex + i];
            srt.push_back(s);
        }

        long long ans = 0;
        mValue = -mValue;
        for(int i = 0; i < srt.size(); ++i) {
            if (srt[i] > mValue) {
                ans += mValue * (i + 1);
                mValue = 0;
            }
            else {  // == < 
                ans += srt[i] * (i + 1);
                mValue -= srt[i];
            }

            if (mValue == 0) break;
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> balance = { 5, 1, -4 };
    //{ 1, 2, -5, 2 };

    cout << sol.minMoves(balance);


    cin >> c;
}
