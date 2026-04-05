// ok
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
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> ans;

        int rt = tomatoSlices - cheeseSlices * 2;

        if (rt < 0 || (rt % 2) != 0) {
            return ans;
        }

        // if t remained?
        if (rt / 2 > cheeseSlices) return ans;

        ans.push_back(rt / 2); // jumbo burger
        ans.push_back(cheeseSlices - rt / 2);   // cheese burger

        return ans;
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> arr = { 1, 3, 5 };

    cout << sol.numOfSubarrays(arr);

    cin >> c;
}
