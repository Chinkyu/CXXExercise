// Easy : but slow - might be better solutions 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <string>A
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

class MedianFinder {
public:
    multiset<int> ms;
    MedianFinder() {
        ms.clear();
    }

    void addNum(int num) {
        ms.insert(num);
    }

    double findMedian() {
        int l = ms.size();

        if (l % 2 == 1) {
            // just middle
            auto iter = ms.begin();
            std::advance(iter, l / 2);
            return *iter;
        }
        else {
            // just div of middle + 1
            auto iter = ms.begin();
            std::advance(iter, l / 2 - 1);  //:: ckkang : mid value from multiset
            auto niter = iter++;
            double ans = ((double)*iter + (double)*niter) / 2;
            return ans;
        }
    }
};

int main() {
    MedianFinder sol;
    char c;

    vector<int> nums = { 1,2 };



    for (auto it : nums) {
        sol.addNum(it);
    }

    cout << sol.findMedian();

    cin >> c;
}
