// 답봤음... : back trace ??? 
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
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2) // if the size is 2 then return 2
            return n;


        int maxi = 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int count = 2;
                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j)
                    {
                        if ((points[j][1] - points[i][1]) * (points[i][0] - points[k][0]) == (points[i][1] - points[k][1]) * (points[j][0] - points[i][0]))
                            count++;
                    }
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};


int main() {
    char c;
    Solution sol;

    vector<int> heights = { 2,1,5,6,2,3 };

    cout << sol.largestRectangleArea(heights);

    cin >> c;
}