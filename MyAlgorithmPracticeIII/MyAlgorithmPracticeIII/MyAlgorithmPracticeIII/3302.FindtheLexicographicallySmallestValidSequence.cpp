// see answer :  last 를 만들고 앞에서 가면서 처리... 대략 이해... 일단 이런 알고리즘 구상하기가 힘들어 보임. 
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
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size(), skip = 0;
        vector<int> last(m, -1);
        for (int i = n - 1, j = m - 1; i >= 0; --i)
            if (j >= 0 && word1[i] == word2[j])
                last[j--] = i;
        vector<int> res;
        for (int i = 0, j = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j] || (skip == 0 && (j == m - 1 || i < last[j + 1]))) {
                res.push_back(i);
                skip += (word1[i] != word2[j++]);
            }
        }
        return res.size() == m ? res : vector<int>();
    }
};

int main() {
    char c;
    Solution sol;

    vector<int> nums = { 1,3,4,8 };
    vector<vector<int>> queries = { {0,1} ,{1,2},{2,3},{0,3} };

    vector<int> ans = sol.minDifference(nums, queries);

    for (auto& it : ans) {
        cout << it << " ";
    }

    cin >> c;
}
