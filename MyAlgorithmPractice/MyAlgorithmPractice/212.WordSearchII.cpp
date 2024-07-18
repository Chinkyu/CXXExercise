#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
	struct Node {
		unordered_Amap<char, struct Node *> map;
		bool isExist;
		string word;
	};


	//vector<vector<char>>& board;
	bool isFound = false;
	struct Node *root;
	vector<string> ans;

	void iteration(vector<vector<char>>& board, vector<vector<bool>> &vmap, struct Node *p, int vi, int vj) {

		if (isFound == true) return;

		int m = board.size();
		int n = board[0].size();

		// push stack 
		//history.push(pair<int, int>(vi, vj));

		if (p->map.find(board[vi][vj]) != p->map.end()) {
			vmap[vi][vj] = true;

			p = p->map[board[vi][vj]];

			if (p->isExist == true) {
				ans.push_back(p->word);
				p->isExist = false;   // once detected remove from list 
			}

			// check 4 direction 
			for (int i = -1; i <= 1; ++i) {
				for (int j = -1; j <= 1; ++j) {
					if (i != 0 && j != 0) continue;  // remove corner;

					if (0 <= vi + i && vi + i < m &&
						0 <= vj + j && vj + j < n) {
						if (vmap[vi + i][vj + j] == false) {
							iteration(board, vmap, p, vi + i, vj + j);
						}
					}

				}
			}

			//history.pop();
			vmap[vi][vj] = false;
		}
	}



	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

		//int ws = word.size();
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> vmap(m, vector<bool>(n, false));

		ans.clear();

		isFound = false;


		// make Tri
		root = new Node();
		struct Node *p = root;
		for (auto it : words) {
			p = root;
			for(auto jt : it) {
				if (p->map.find(jt) ==  p->map.end()) {
					p->map[jt] = new Node();
				}
				p = p->map[jt];
			}
			p->isExist = true;
			p->word = it;
		}

		// for all char 
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				iteration(board, vmap, root, i, j);
			}
		}
		return ans;
	}
};

int main() {
	Solution sol;
	char c;

//	vector<vector<char>> mat =
//	{
//			{'o', 'a', 'a', 'n'},
//			{'e', 't', 'a', 'e'},
//			{'i', 'h', 'k', 'r'},
//			{'i', 'f', 'l', 'v'}
//	};

//	vector<string> words = { "oath", "pea", "eat", "rain" };

	vector<vector<char>> mat =
	{
			{'a', 'b'},
			{'c', 'd'}
	};

	vector<string> words = { "ab", "cb", "ad", "bd", "ac", "ca", "da", "bc", "db", "adcb", "dabc", "abb", "acb"};
	//vector<string> words = { "ac", "ca", "db" };


	vector<string> ans = sol.findWords(mat, words);
	for (auto it : ans) {
		cout << it.c_str() << endl;
	}

	cin >> c;
}
