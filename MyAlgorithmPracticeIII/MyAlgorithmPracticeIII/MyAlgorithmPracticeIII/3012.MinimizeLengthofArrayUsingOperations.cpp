// see answer : 최소값과 연산해서 나머지가 있는 놈이 하나라도 있으면 답이 1 아니면 수 + 1 /2 
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
    int minimumArrayLength(vector<int>& A) {
        int v = *min_element(A.begin(), A.end());
        for (int x : A)
            if (x % v > 0)
                return 1;
        int cnt = count(A.begin(), A.end(), v);
        return (cnt + 1) / 2;
    }
};

int main() {
    char c;
    Solution sol;
    vector<vector<int>> buildings = { {0, 1}, {2, 1}, {3, 1}, {1, 4}, {2,4} };

    vector<int> ans = sol.findSmallestSetOfVertices(5, buildings);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
