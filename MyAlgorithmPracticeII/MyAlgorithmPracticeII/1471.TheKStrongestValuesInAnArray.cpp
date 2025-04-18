//  OK :
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

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        int m = arr[(arr.size()-1) / 2];

        vector<pair<int, int>> arr2;
        for (int i = 0; i < arr.size(); ++i) {
            arr2.push_back(make_pair(arr[i], abs(arr[i] - m)));
        }

        sort(arr2.begin(), arr2.end(), [](pair<int, int>& l, pair<int, int>& r) {
            if (l.second == r.second) {
                return l.first > r.first;
                }
            return l.second > r.second;
            });

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(arr2[i].first);
        }

        return ans;
    }
};

int main() {
    char c;
    Solution sol;
    //vector<int> arr = { 1, 1, 3, 5, 5 };
    vector<int> arr = { -7,22,17,3 };


    vector<int> ans = sol.getStrongest(arr, 2);

    for (auto it : ans) {
        cout << it << " ";
    }

    cin >> c;
}