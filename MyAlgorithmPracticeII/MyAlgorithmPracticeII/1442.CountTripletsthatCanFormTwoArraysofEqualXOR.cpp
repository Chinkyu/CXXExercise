//  See solution 

/*
* 
a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]

Assume a == b, thus
a ^ a = b ^ a, thus
0 = b ^ a, thus
arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1] ^ arr[j] ^ arr[j + 1] ^ ... ^ arr[k] = 0
prefix[k+1] = prefix[i]

*/


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
    int countTriplets(vector<int>& A) {
        A.insert(A.begin(), 0);
        int n = A.size(), res = 0;
        for (int i = 1; i < n; ++i)
            A[i] ^= A[i - 1];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (A[i] == A[j])
                    res += j - i - 1;
        return res;
    }
};

int main() {
    char c;
    Solution sol;

    vector<vector<int>> ans = sol.generateMatrix(3);

    for (auto& it : ans) {
        for (auto& jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }

    cin >> c;
}