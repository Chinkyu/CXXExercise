// not esay
//  stack 가지고 한다는것은 이해 하겠는데.. 
//  last 로 지운 값하고 지금 넣는 값이 같은 경우  count++ 안한다는 부분이 생각하기 쉽지 않음. 

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <iomanip>

using namespace std;

class Solution {
public:
	vector<vector<int>> seePeople(vector<vector<int>>& heights) {
		int rl = heights.size(), cl = heights[0].size();
		vector<vector<int>> ans(rl, vector<int>(cl, 0));

		// raw calcuration 
		for (int i = 0; i < rl; ++i) {
			stack<int> st;
			for (int j = cl - 1; j >= 0; --j) {
				int seeCount = 0;
				int last = 0;
				while (!st.empty() && st.top() <= heights[i][j]) {
					seeCount++;;
					last = st.top();
					st.pop();
				}
				if (!st.empty() && heights[i][j] != last) seeCount++;
				st.push(heights[i][j]);
				ans[i][j] += seeCount;
			}
		}

		// raw calcuration 
		for (int j = 0; j < cl; ++j) {
			stack<int> st;
			for (int i = rl - 1; i >= 0; --i) {
				int seeCount = 0;
				int last = 0;
				while (!st.empty() && st.top() <= heights[i][j]) {
					seeCount++;;
					last = st.top();
					st.pop();
				}
				if (!st.empty() && heights[i][j] != last) seeCount++;
				st.push(heights[i][j]);
				ans[i][j] += seeCount;
			}
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	//vector<vector<int>> heights = { {3, 1, 4, 2, 5} };
	//vector<vector<int>> heights = { {5, 1},{3, 1},{4, 1} };
	//vector<vector<int>> heights = { {4,2,1,1,3} };
	vector<vector<int>> heights = { {1, 1, 1} };
	vector<vector<int>> ans = sol.seePeople(heights);
	for (auto it : ans) {
		for (auto jt : it) {
			cout << jt << " ";
		}
		cout << endl;
	}

	cin >> c;

}