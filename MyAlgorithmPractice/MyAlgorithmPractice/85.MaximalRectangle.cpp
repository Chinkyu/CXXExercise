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
    func maximalRectangle(_ matrix : [[Character]] ) -> Int {
        guard !matrix.isEmpty, let cols = matrix.first ? .count else { return 0 }

        var maxArea = 0
            var heights = [Int](repeating: 0, count : cols + 1)

            for row in matrix{
                for j in 0.. < cols {
                    if row[j] == "1" {
                        heights[j] += 1
                    }
     else {
      heights[j] = 0
  }
}

var stack = [-1]
for j in 0...cols {
    while let last = stack.last, last != -1, heights[j] < heights[last] {
        stack.removeLast()
        let height = heights[last]
        let width = j - 1 - (stack.last ? ? -1)
        maxArea = max(maxArea, height * width)
    }
    stack.append(j)
}
            }

                return maxArea
    }
}

int main() {
    char c;
    Solution sol;

    vector<int> heights = { 2,1,5,6,2,3 };

    cout << sol.largestRectangleArea(heights);

    cin >> c;
}