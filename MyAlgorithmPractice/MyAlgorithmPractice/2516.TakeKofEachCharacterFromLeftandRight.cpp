//  슬라이딩 윈도우로 푸는데.. 예외 처리가 많아서 시간 걸림.. !!! 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
	int takeCharacters(string s, int k) {
		vector<int> countV(3, 0), fcountV(3, 0), bcountV(3, 0);
		int l = s.size();
		int bidx = l;
		int min = INT_MAX;

		if (k == 0) return 0;

		// f 0. withonly b 

		// back 
		for (int j = l - 1; 0 <= j; --j) {
			bcountV[s[j] - 'a']++;
			if (bcountV[0] >= k && bcountV[1] >= k && bcountV[2] >= k) {
				if (bcountV[0] + bcountV[1] + bcountV[2] < min) min = bcountV[0] + bcountV[1] + bcountV[2];
				bidx = j;
				break;
			}
		}
		if (min == INT_MAX) return -1;

		for (int i = 0; i < l; ++i) {
			fcountV[s[i] - 'a']++;

			if (i == bidx) {
				bidx++;
				countV[s[i] - 'a']--;
				bcountV[s[i] - 'a']--;
			}

			countV = fcountV;   // vector copy
			countV[0] += bcountV[0]; countV[1] += bcountV[1]; countV[2] += bcountV[2];

//			if (countV[0] >= k && countV[1] >= k && countV[2] >= k) {
//				if (countV[0] + countV[1] + countV[2] < min) min = countV[0] + countV[1] + countV[2];
//			}

			// back 
			for (int j = bidx; j < l; ++j) {
				countV[s[j] - 'a']--;
				bcountV[s[j] - 'a']--;
				bidx = j;
				if (countV[0] < k || countV[1] < k || countV[2] < k) {
					countV[s[j] - 'a']++;
					bcountV[s[j] - 'a']++;
					bidx = j;
					if (countV[0] + countV[1] + countV[2] < min) min = countV[0] + countV[1] + countV[2];
					break;
				}
			}

			if (countV[0] >= k && countV[1] >= k && countV[2] >= k) {
				if (countV[0] + countV[1] + countV[2] < min) min = countV[0] + countV[1] + countV[2];
			}
		}

		if (min == INT_MAX) return -1;
		return min;

	}
};

int main() {
	char c;

	Solution sol;

	string s = "bcbaab"; // "aabaaaacaabc";
	cout << sol.takeCharacters(s, 1);

	cin >> c;
}