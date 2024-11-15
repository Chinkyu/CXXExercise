//  easy 
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
#include <functional>

using namespace std;

class LUPrefix {
public:
    int lup = 0;
    vector<int> v;
    int len = 0;
    LUPrefix(int n) {
        v = vector<int>(n + 1, 0);
        v[0] = 1;
        lup = 0;
        len = n;
    }

    void upload(int video) {
        v[video] = 1;
        while (lup < len && v[lup + 1] == 1) lup++;
    }

    int longest() {
        return lup;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,13,10,12,31 };

    cout << sol.countDistinctIntegers(nums);

    cin >> c;
}