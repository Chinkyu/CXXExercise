//   나도    "a/*xkd","dldldl */b"  가   ab되어야 하는것은 좀 이상한데..
// 하라는데도 그냥 했음... 
// 위 것 처리 하는것이 좀 깔끔하지 않음..... 

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
	enum state {
		COMMENT_NOT_START,
		COMMENT_STARTED,
		COMMENT_END
	};


	vector<string> removeComments(vector<string>& source) {
		enum state st = COMMENT_NOT_START;
		vector<string> ans;

		for (auto it : source) {
			int line_cmt = it.find("//");
			int block_start = it.find("/*");
			int block_end = it.find("*/");

			string str = it;

RESTART:
			switch (st) {
			case COMMENT_NOT_START:
				line_cmt = str.find("//");
				block_start = str.find("/*");
				if (string::npos != line_cmt && string::npos != block_start) {
					if (block_start < line_cmt) {  // /*
						st = COMMENT_STARTED;
						
						block_end = str.find("*/", block_start + 2);
						if (block_end != string::npos) {
							str = str.erase(block_start, block_end - block_start + 2);
							st = COMMENT_NOT_START;
							if (str == "") continue;
							goto RESTART;
						}


						str = str.substr(0, block_start);
						if (str == "") continue;
					}
					else {							// //
						str = str.substr(0, line_cmt);
						if (str == "") continue;
					}
				}
				else if (string::npos == line_cmt && string::npos != block_start) {  // /*
					st = COMMENT_STARTED;

					block_end = str.find("*/", block_start + 2);
					if (block_end != string::npos) {
						str = str.erase(block_start, block_end - block_start + 2);
						st = COMMENT_NOT_START;
						if (str == "") continue;
						goto RESTART;
					}

					str = str.substr(0, block_start);
					if (str == "") continue;
				}
				else if (string::npos != line_cmt && string::npos == block_start) {  // //
					str = str.substr(0, line_cmt);
					if (str == "") continue;
				}
				break;
			case COMMENT_STARTED:
				block_end = str.find("*/");
				if (string::npos != block_end) {
					str = str.substr(block_end + 2);
					st = COMMENT_NOT_START;
					if (str == "") continue;
					ans[ans.size() - 1] += str;
					str = ans[ans.size() - 1];
					ans.pop_back();
					goto RESTART;
				}
				else {
					continue;
				}
				break;
//			case COMMENT_END:
//				if (str == "") {
//					continue;
//				}
//				else {
//
//				}
//				break;
			}

			ans.push_back(str);

		}

		return ans;

	}
};

int main() {
	char c;

	Solution sol;

	vector<string> source = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"
};
	vector<string> ans = sol.removeComments(source);


	for (auto it : ans) {
		cout << it << endl;
	}

	//cout << sol.minimumSwap(s1, s2);

	cin >> c;
}