//  easy : 0고려 필요 
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
	string minimizeResult(string expression) {
		int l = expression.size();
		int pidx = 0;
		string ls, rs;
		for (int i = 0; i < l; ++i) {
			if (expression[i] == '+') {
				pidx = i;
				ls = expression.substr(0, i);
				rs = expression.substr(i + 1);
				break;
			}
		}

		int minl = 0; 
		int minr = 0;
		long long cmin = stoi(ls) + stoi(rs);
		for (int i = 0; i <= ls.size() - 1; ++i) {
			for (int j = 0; j <= rs.size() - 1; ++j) {
				int n1 = (i > 0) ? stoi(ls.substr(0, i)) : 1;
				int n2 = stoi(ls.substr(i));
				int n3 = stoi(rs.substr(0, rs.size() - j));
				int n4 = (j > 0) ? stoi(rs.substr(rs.size() - j)) : 1;

				long long tmin = n1 * (n2 + n3) * n4;
				if (tmin < cmin) {
					cmin = tmin;
					minl = i;
					minr = j;
				}
			}
		}

		string ans = expression;
		ans.insert(minl, 1, '(');
		ans.insert(expression.size() + 1- minr, 1, ')');
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	string expression = "12+34"; // "247+38"; // "9999+9999"; 
	cout << sol.minimizeResult(expression);


	cin >> c;

}