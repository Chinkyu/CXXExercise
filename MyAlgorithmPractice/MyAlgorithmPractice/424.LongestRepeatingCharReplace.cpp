#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	bool checkValid(vector<int> ca, int noise) {

		sort(ca.begin(), ca.end());
		int sum = 0;
		for (int i = 0; i < ca.size() - 1; ++i) {
			sum += ca[i];
		}

		return (sum > noise) ? false : true;
	}

	int characterReplacement(string s, int k) {
		vector<int> ca(26, 0);
		int l = s.size();
		if (l <= 0) return 0;

		int st = 0, ed = 0;
		int max = 0;
		ca[s[0] - 'A']++;

		do {
			if (checkValid(ca, k) == true) {
				if (max < ed - st + 1) max = ed - st + 1;
				ed++;
				if (ed >= l) {
					return max;
				}
				ca[s[ed] - 'A']++;
			}
			else {
				ca[s[st] - 'A']--;
				st++;
			}
		} while (ed < l && st + k < l);
		return max;
	}
};

int main() {
	char c;
	Solution sol;
	//string s = "ABAB";
	//string s = "AABABBA";
	string s = "";

	cout << sol.characterReplacement(s, 0);

	cin >> c;

}