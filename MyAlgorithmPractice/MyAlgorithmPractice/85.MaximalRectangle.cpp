// 답봤음... 
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
private:
    int area(vector<int>& heights)
    {
        int n = heights.size();
        int ans = 0;
        stack<int>st;
        for (int i = 0; i <= n; ++i)
        {
            while (!st.empty() and (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;

                ans = max(ans, width * height);
            }
            st.push(i);

        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>heights(m, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            ans = max(ans, area(heights));
        }
        return ans;

    }
};

int main() {
    char c;
    Solution sol;

    vector<int> heights = { 2,1,5,6,2,3 };

    cout << sol.largestRectangleArea(heights);

    cin >> c;
}