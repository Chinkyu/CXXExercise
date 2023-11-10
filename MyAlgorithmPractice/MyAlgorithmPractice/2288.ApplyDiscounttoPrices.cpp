//  double, long long  때문데.. 조금.....
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
	inline bool isDigit(string &s) {
		int l = s.size();
		for (int i = 1; i < l; ++i) {
			if (s[i] < '0' || '9' < s[i]) return false;
		}
		return true;
	}
	string discountPrices(string sentence, int discount) {
		istringstream input(sentence);
		string ans;

		string token;
		while (getline(input, token, ' ')) {
			if (token == "") continue;

			if (token[0] == '$' && isDigit(token)) {
				string tnum = token.substr(1);
				try {
					long long n = stol(tnum);
					double f = (double)n * (1.0 -(double)discount / 100);

					stringstream ss;
					ss << "$";
					ss << fixed << std::setprecision(2) << f;
					string cs = ss.str();
					ans.append(cs + " ");
				}
				catch (exception e) {
					ans.append(token + " ");
				}
			}
			else {
				ans.append(token+" ");
			}

		}

		ans.pop_back();
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	string sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$";

	cout << sol.discountPrices(sentence, 50);

	cin >> c;

}