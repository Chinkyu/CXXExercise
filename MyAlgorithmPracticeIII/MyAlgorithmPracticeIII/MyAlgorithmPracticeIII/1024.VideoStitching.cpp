// see answer : 심박 알고
//  st보다 작은것 중에  End 가 가장 먼거를 찾는것 계속함... 
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
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(begin(clips), end(clips));
        int res = 0;
        for (auto i = 0, st = 0, end = 0; st < T; st = end, ++res) {
            for (; i < clips.size() && clips[i][0] <= st; ++i)
                end = max(end, clips[i][1]);
            if (st == end) return -1;
        }
        return res;
    }
};

int main() {
    char c;
    Solution sol;

    string s = "1101";
    cout << sol.numSteps(s);

    cin >> c;
}
