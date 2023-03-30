//쉽게 풀림.. 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		sort(words.begin(), words.end(), [](string &l, string &r) {
			return l.size() > r.size();
		});

		//for (auto it : words) cout << " " << it;

		for (int i = 0; i < words.size(); ++i) {
			if (words[i] == "") continue;
			for (int j = i + 1; j < words.size(); ++j) {
				if (words[j] == "") continue;
				int ll = words[i].size();
				int rl = words[j].size();

				if (0 == words[i].compare(ll - rl, rl, words[j])) { // if equal
					words[j] = "";
				}
			}
		}

		int count = 0; 
		int total_len = 0;
		for (int i = 0; i < words.size(); ++i) {
			if (words[i] == "") continue;
			total_len += words[i].size();
			count++;
		}

		return total_len + count;
	}
};

int main() {
	char c;

	Solution sol;

	vector<string> words = { "time", "me", "bell" };

	cout << sol.minimumLengthEncoding(words);


	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}