// saw answer : permutation's meaning
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
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size(), x = 0;
        // XOR of the permutation
        for (int i = 1; i <= n + 1; i++) x ^= i;

        // Xoring X with all the odd positioned elements to find first number
        for (int i = 1; i < n; i += 2) x ^= encoded[i];

        vector <int> res;
        res.push_back(x);
        for (int i = 0; i < n; i++) {
            x ^= encoded[i];
            res.push_back(x);
        }
        return res;
    }
};

int main() {
	char c;
	Solution sol;
	//vector<vector<int>> matrix = { {5, 2},{1, 6} };
	vector<vector<int>> matrix = {{10, 9, 5}, {2, 0, 4}, {1, 0, 9}, {3, 4, 8}};

	cout << sol.kthLargestValue(matrix, 10);

	cin >> c;
}