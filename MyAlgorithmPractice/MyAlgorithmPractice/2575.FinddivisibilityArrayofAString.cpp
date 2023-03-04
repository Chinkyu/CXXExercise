//  앞에서 모듈러를 하면서 오면 된다는것을 몰라서...   long long 보다 값이 커져서  Error 났음
// 답을 보고 따라함... 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> divisibilityArray(string word, int m) {
		vector<int> ans;
		long long sum = 0;

		for (auto it : word) {
			sum *= 10;
			sum += it - '0';

			sum = sum % m;
			if (sum == 0) {
				ans.push_back(1);
			}
			else {
				ans.push_back(0);
			}
		}

		return ans;
	}
};


class _Solution {
public:
	vector<int> divisibilityArray(string word, int m) {
		vector<int> ans;
		string s;

		for (auto it : word) {
			s.push_back(it);
			long long v = stoll(s);
			if (v % m == 0) {
				ans.push_back(1);
			}
			else {
				ans.push_back(0);
			}
		}
		
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	string word = "86217457695827338571";
	vector<int> ans = sol.divisibilityArray(word, 8);

	for (auto it : ans) {
		cout << " " << it;
	}
	cout << endl;

	cin >> c;
}