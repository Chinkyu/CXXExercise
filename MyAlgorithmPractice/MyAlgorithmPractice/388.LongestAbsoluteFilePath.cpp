#include <iostream>
#include <sstream>
#include <vector>


using namespace std;

struct Node {
	string s;
	char type;
	Node *next;
	Node(string st) : s(st), next(NULL) {}
};

class Solution {
public:
	vector<string> path;
	int path_size = 0;
	int max_len = 0;

	void build_path(string ss) {
		int depth = 0;
		int st = 0;

		while (ss[st] == '\t') {
			depth++;
			st++;
		}
		string f = ss.substr(st);
		if (f.find(".") != std::string::npos) {
			// file
			// generate file string 
			string full_path;
			for (int i = 0; i < depth; ++i) {
				full_path.append(path[i] + "/");
			}
			full_path.append(f);
			if (full_path.size() > max_len) max_len = full_path.size();
		}
		else {
			// directory
			if (path.size() < depth+1) path.resize(depth+1);
			path[depth] = f;
		}
	}

	int lengthLongestPath(string input) {
		int st = 0;
		int l = input.length();

		if (l <= 0) return 0;

		max_len = 0; 

		int i = 0;
		do {
			if (input[st + i] == '\n') {
//				if (input[st + i + 1] == 'n') {
					build_path(input.substr(st, i));
					st = st + i + 1;
					i = 0;
//				}
			}
			i++;
		} while (st + i <= l);
		build_path(input.substr(st, i));
		return max_len;
	}
};

void main() {
	char c;
	Solution sol;

	string p = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";

	cout << sol.lengthLongestPath(p);

	cin >> c;
}