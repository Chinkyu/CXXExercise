// ¥‰∫√¿Ω. : 

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
    int calculateSumInRange(int start, int count) {
        int sum = (count * (2 * start + (count - 1))) / 2;
        return sum;
    }

    int minimumSum(int quantity, int k) {
        int middle = k / 2;

        if (quantity <= middle) {
            return quantity * (quantity + 1) / 2;
        }

        int leftSum = middle * (middle + 1) / 2;

        int remainingNumbers = quantity - middle;

        return leftSum + calculateSumInRange(k, remainingNumbers);
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> arr = { 1,0,2,3,4 };

    cout << sol.maxChunksToSorted(arr);

    cin >> c;
}