// easy : using set and from 
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

class SmallestInfiniteSet {
    set<int> s;
    int from = 1;
public:
    SmallestInfiniteSet() {
        s.clear();
        from = 1;
    }

    int popSmallest() {
        int ans = 0;
        if (s.size() > 0) {
            auto first = s.begin();
            int ans = *first;
            s.erase(first);
            return ans;
        }

        ans = from++;
        return ans;
    }

    void addBack(int num) {

        if (num < from) {
            s.insert(num);
        }
        else if (num == from - 1) {
            from--;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main() {
    char c;
    Solution sol;
    //vector<int> asteroids = {5, 10, -5};
    vector<int> starPos = { 1, 0 };
    vector<int> homePos = { 2, 3 };
    vector<int> rowCosts = { 5, 4, 3 };
    vector<int> colCosts = { 8, 2, 6, 7 };

    cout << sol.minCost(starPos, homePos, rowCosts, colCosts);


    //cout << "Test  application";

    cin >> c;
}
