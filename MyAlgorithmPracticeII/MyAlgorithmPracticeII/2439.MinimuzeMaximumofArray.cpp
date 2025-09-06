// see answer
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

/*
Intuition

In one operation:
decrease A[i] by 1.
increase A[i - 1] by 1.

We actully move the value of A[i] to A[i - 1] by 1,
the sum won't change.

If A[i] < A[i + 1],
then we can repeatly do the operations,
until A[i] >= A[i+1].
So finally the array A will become decrescent order.

Explanation

We calculate the prefix sum arrray and their average.
The average is the lower bound of the result,
and it's reachable lower bound by the process in intuition,
so this average is the result.

Calculate average

We need to calculate the ceil integer of the average,
For example 7 = 3 + 2 + 2,
the ceil average is 3.

The ceil average with sum of i + 1 number:
ceil(double(sum) / (i + 1))

We can also do integer division:
(sum + i) / (i + 1)

Complexity

Time O(n)
Space O(1)

*/
//  이거는 똑똑한 아이디어네...  모든 i 에 대해서 해 봐야 한다는게.. overheade 이긴한데..
// 좋은 아이디어임.. 

class Solution {
public:
    int minimizeArrayValue(vector<int>& A) {
        long sum = 0, res = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            res = max(res, (sum + i) / (i + 1));
        }
        return res;
    }
};

int main() {
    char c;
    Solution sol;
    vector<string> keyName = { "daniel", "daniel", "daniel", "luis", "luis", "luis", "luis" };
    vector<string> keyTime = { "10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00" };

    vector<string> ans = sol.alertNames(keyName, keyTime);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}