// 답봤음 : Comnbination : 
//The number of ways to choose m - 1 down moves from m + n - 2 total moves is given by the combination formula :
//𝐶(𝑚 + 𝑛−2, 𝑚 - 1) = ((𝑚 + 𝑛−2)!) / (((𝑚−1)!)((𝑛−1)!))

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
    int uniquePaths(int m, int n) {
        long result = 1;
        for (int i = 1; i <= m - 1; i++) {
            result = result * (n + i - 1) / i;
        }
        return (int)result;
    }
};


int main() {
    char c;
    Solution sol;
    vector<string> messages = { "Hello userTwooo", "Hi userThree", "Wonderful day Alice", "Nice day userThree" };
    vector<string> senders = { "Alice", "userTwo", "userThree", "Alice" };

    cout << sol.largestWordCount(messages, senders);

    cin >> c;
}