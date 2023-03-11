// stack을 기본적으로 사용 하면 되고.. string 의 iterator를 사용해서..
// iterator 를 loop에서 지우는 부분이 좀 tricky 함. 

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
	string minRemoveToMakeValid(string s) {
		string::iterator it = s.begin();
		stack<string::iterator> st;

		int depth = 0;
		for (string::iterator it = s.begin(); it != s.end();) {
			if (depth == 0 && *it == ')') {
				if (it != s.begin()) {
					it-- ;
					s.erase(it+1);
					it++;
					continue;
				}
				else {  // s.begin();
					s.erase(it);
					it = s.begin();
					continue;
				}
			}

			if (*it == '(') {
				depth++;
				st.push(it);
			}

			if (*it == ')') {
				depth--;
				st.pop();
			}
			++it;
		}

		// remove remained '('
		while (st.size() != 0) {
			s.erase(st.top());
			st.pop();
		}

		return s;
	}
};

int main() {
	char c;

	Solution sol;

	string s1 = "lee(t(c)o)de)";
	//string s1 = "a)b(c)d";
	//string s1 = "))((";

	cout << sol.minRemoveToMakeValid(s1);

	//cout << sol.minimumSwap(s1, s2);

	cin >> c;
}