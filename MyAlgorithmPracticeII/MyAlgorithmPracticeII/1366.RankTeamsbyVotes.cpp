// 답봤는데 : array 정렬 방식을 활용함... .
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
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> count(26, vector<int>(27));
        for (char& c : votes[0])
            count[c - 'A'][26] = c;

        for (string& vote : votes)
            for (int i = 0; i < vote.length(); ++i)
                --count[vote[i] - 'A'][i];
        sort(count.begin(), count.end());
        string res;
        for (int i = 0; i < votes[0].length(); ++i)
            res += count[i][26];
        return res;
    }
};

int main() {
	char c;
	Solution sol;
	vector<int> nums = { 3, 5, 2, 6 };

	vector<int> ans = sol.mostCompetitive(nums, 2);
	for (auto it : ans) {
		cout << it << " ";
	}
	cin >> c;
}