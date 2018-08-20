#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max_cnt, cnt;
		unordered_map<int, int> umap;

		for (int k = 0; k < k.length(); k++) {

			s = 
			umap.clear();
			max_cnt = cnt = 0;
			for (int i = 0; i < s.length(); i++) {
				if (umap[s[i]] >= 1) {
					// try to go left
	//				for (int j = i - cnt -1; j >= 0; j--) {
	//					if (umap[s[j]] >= 1) {
	//						break;
	//					} else {
	//						umap[s[j]]++;
	//						cnt++;
	//					}
	//				}

					umap.clear();
					umap[s[i]]++;
					if (max_cnt < cnt) max_cnt = cnt;
					cnt = 1;
					continue;
				}
				umap[s[i]]++;
				cnt++;
			}
		}
		// try to go left
//		for (int j = s.length() - cnt - 1; j >= 0; j--) {
//			if (umap[s[j]] >= 1) {
//				break;
//			}
//			else {
//				umap[s[j]]++;
//				cnt++;
//			}
//		}
		if (max_cnt < cnt) max_cnt = cnt;
		return max_cnt;
	}
};

int main() {
	string s = "bpoiexpqhmebhhu";
	Solution sol;
	char c; 

	cout << sol.lengthOfLongestSubstring(s);

	cin >> c;
}