// 답봤음 : 문제 이해 안감... - skip
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
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        unordered_map<int, int> hashTable;
        priority_queue<int> lo;
        priority_queue<int, vector<int>, greater<int>> hi;

        int i = 0;

        while (i < k) {
            lo.push(nums[i++]);
        }
        for (int j = 0; j < k / 2; ++j) {
            hi.push(lo.top());
            lo.pop();
        }

        while (true) {
            medians.push_back(k & 1 ? lo.top() : ((double)lo.top() + (double)hi.top()) * 0.5);

            if (i >= nums.size()) break;

            int outNum = nums[i - k];
            int inNum = nums[i++];
            int balance = 0;

            balance += outNum <= lo.top() ? -1 : 1;
            hashTable[outNum]++;

            if (!lo.empty() && inNum <= lo.top()) {
                balance++;
                lo.push(inNum);
            }
            else {
                balance--;
                hi.push(inNum);
            }

            if (balance < 0) {
                lo.push(hi.top());
                hi.pop();
                balance++;
            }
            if (balance > 0) {
                hi.push(lo.top());
                lo.pop();
                balance--;
            }

            while (hashTable[lo.top()]) {
                hashTable[lo.top()]--;
                lo.pop();
            }

            while (!hi.empty() && hashTable[hi.top()]) {
                hashTable[hi.top()]--;
                hi.pop();
            }
        }
        return medians;
    }
};

class _Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int l = nums.size();
        multiset<int> ms;
        vector<double> ans;

        for (int i = 0; i < k; ++i) {
            ms.insert(nums[i]);
        }

        int m = k / 2;
        multiset<int>::iterator it = ms.begin();
        for(int i = 0; i < m; ++i) it++;

        double mid = *it;
        if (k % 2 == 0) {
            it--;
            mid = (mid + *it) / 2.0;
        }

        ans.push_back(mid);

        for (int i = 0; i < l - k; ++i) {
            ms.erase(ms.find(nums[i]));
            ms.insert(nums[i + k]);

            it = ms.begin();
            for (int i = 0; i < m; ++i) it++;

            double mid = *it;
            if (k % 2 == 0) {
                it--;
                mid = (mid + *it) / 2.0;
            }

            ans.push_back(mid);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    char c;

    //vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
    vector<int> nums = { 1,4, 2, 3 };

    vector<double> ans = sol.medianSlidingWindow(nums, 4);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
