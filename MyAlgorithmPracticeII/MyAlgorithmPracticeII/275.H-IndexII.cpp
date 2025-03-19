// ¥‰∫√¿Ω :  b search 

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
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if citations[mid] can be an h-index
            if (citations[mid] >= n - mid) {
                right = mid - 1; // Try for a higher h-index
            }
            else {
                left = mid + 1; // Increase citation count requirement
            }
        }

        // The number of papers with at least `n - left` citations
        return n - left;
    }
};

int main() {
    char c;
    Solution sol;

    //    string colors = "abaac";
    //    vector<int> needTime = { 1, 2, 3, 4, 5 };
    string colors = "aabaa";
    vector<int> needTime = { 1, 2, 3, 4, 1 };


    //cout << sol.minCost(colors, needTime);

    cin >> c;
}