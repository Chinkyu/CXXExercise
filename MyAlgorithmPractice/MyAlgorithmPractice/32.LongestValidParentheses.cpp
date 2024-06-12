// 港疑擠.....?????太?太?太?太? 
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
#include <regex>
#include <memory>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.length(), longest = 0;
		stack<int> st;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') st.push(i);
			else {
				if (!st.empty()) {
					if (s[st.top()] == '(') st.pop();
					else st.push(i);
				}
				else st.push(i);
			}
		}
		if (st.empty()) longest = n;
		else {
			int a = n, b = 0;
			while (!st.empty()) {
				b = st.top(); st.pop();
				longest = max(longest, a - b - 1);
				a = b;
			}
			longest = max(longest, a);
		}
		return longest;
	}
};

class _Solution {
public:
	int longestValidParentheses(string s) {
		vector<int> sv;
		int l = s.size();

		int ans = 0;
		int t_max = 0, vl = 0;  // valid length
		int bc = 0; // brace count;
		for (int i = 0; i < l; ++i) {
			if (s[i] == ')') {
				if (bc - 1 < 0) {
					if (vl > 0) {
						t_max = max(t_max, vl);
						vl = 0;
					}
				}
				else {
					bc--;
					vl += 2;
				}
			}
			else {  // '('
				bc++;
			}
		}

		if (bc == 0 && vl > 0) {
			t_max = max(t_max, vl);
		}

		if (bc > 0 && vl > 0) {
//			if (s[l - 1] == ')') {
				// need back trace
				
				int tbc = 0;
				bool isFirst = true;
				for (int i = l - 1, j = 0, k = 0; i >= 0; --i, ++j) {
					if (isFirst == true && s[i] == '(') {
						k++;
						continue;
					}

					isFirst = false;
					if (s[i] == ')') {
						tbc++;
					}
					else {
						tbc--;
					}
					if (tbc < 0) {
						t_max = max(t_max, j - k);
						break;
					}
					if (tbc == 0 && i == 0) {
						t_max = max(t_max, j - k + 1);
						break;
					}
				}

				if (bc > 0 && vl > 0) {
					t_max = max(t_max, vl);
				}
//			}
//			else {
//				t_max = max(t_max, vl);
//			}
		}

		return t_max;
	}
};

int main() {
	char c;
	Solution sol;

	//string s = "barfoofoobarthefoobarman";
	//vector<string> words = { "bar", "foo", "the" };

	string s = ")()(((())))(";
		//")(((((()())()()))()(()))(";
		//"(())(";
		//"()(()";
		//")()())";

	cout << sol.longestValidParentheses(s);

	cin >> c;
} 