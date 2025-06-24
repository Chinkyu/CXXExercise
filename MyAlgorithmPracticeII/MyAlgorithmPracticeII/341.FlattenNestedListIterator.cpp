// ok : normal recursive
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

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedInteger {
public:
         // Return true if this NestedInteger holds a single integer, rather than a nested list.
        bool isInteger() const;
    *
             // Return the single integer that this NestedInteger holds, if it holds a single integer
             // The result is undefined if this NestedInteger holds a nested list
        int getInteger() const;
    
             // Return the nested list that this NestedInteger holds, if it holds a nested list
             // The result is undefined if this NestedInteger holds a single integer
        const vector<NestedInteger>& getList() const;
    
};

class NestedIterator {
public:
    vector<int> l;
    int idx = 0;

    void iterator(vector<NestedInteger>& l) {
        for (auto it : l) {
            if (it.isInteger()) {
                l.push_back(it.getInteger());
            }
            else {
                iterator(it.getList());
//                for (auto jt : it.getList()) {
//                    l.push_back(jt.getInteger());
//                }
            }
        }
    }

    NestedIterator(vector<NestedInteger>& nestedList) {
        idx = 0;
        iterator(nestedList);
    }

    int next() {
        int out = l[idx];
        idx++;
        return out;
    }

    bool hasNext() {
        return idx < l.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    char c;
    Solution sol;
    //vector<int> nums = { 10,9,2,5,3,7,101,18 };
    vector<int> nums = { 0,1,0,3,2,3 };

    cout << sol.lengthOfLIS(nums);

    cin >> c;
}