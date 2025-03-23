// ok. : 

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
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> arr2 = arr;

        sort(arr2.begin(), arr2.end());

        unordered_map<int, int> m1, m2;
        int ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            m1[arr[i]]++;
            m2[arr2[i]]++;

            if (m1 == m2) {
                ans++;
                m1.clear();
                m2.clear();
            }


        }

        return ans;

    }
};

int main() {
    char c;
    Solution sol;

    vector<int> arr = { 1,0,2,3,4 };

    cout << sol.maxChunksToSorted(arr);

    cin >> c;
}