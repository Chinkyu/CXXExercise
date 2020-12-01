#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	bool _checkInclusion(string s1, string s2) {
		map<char, int> m;

		for (auto it : s2) {
			if (m.find(it) == m.end()){
				m[it] = 1;
			}
			else {
				m[it]++;
			}
		}

		for (auto it : s1) {
			if (m.find(it) == m.end()) {
				return false;
			}
			else {
				m[it]--;
				if (m[it] < 0) return false;
			}
		}

		return true;
	}
	bool checkInclusion(string s1, string s2) {
		map<char, int> m1, m2;
		int s1l = s1.size(), s2l = s2.size();

		if (s2l < s1l) return false;

		// build m1
		for (auto it : s1) {
			if (m1.find(it) == m1.end()) {
				m1[it] = 1;
			}
			else {
				m1[it]++;
			}
		}

		// build m2
		for (int i = 0; i < s1l; i++) {
			if (m2.find(s2[i]) == m2.end()) {
				m2[s2[i]] = 1;
			}
			else {
				m2[s2[i]]++;
			}
		}

		// check same
		if (m1 == m2) return true;


		int step = s2l - s1l;
		for (int i = 0; i < step; ++i) {
			// remove i
			m2[s2[i]]--;
			if (m2[s2[i]] <= 0) m2.erase(s2[i]);

			// add i + step
			if (m2.find(s2[i+s1l]) == m2.end()) {
				m2[s2[i + s1l]] = 1;
			}
			else {
				m2[s2[i + s1l]]++;
			}

			// check same
			if (m1 == m2) return true;
		}

		return false;
	}
};


int main() {
	char c;
	Solution sol;
	string s1 = "ab", s2 = "eidbaooo";//"eidbaooo";

	cout << sol.checkInclusion(s1, s2);

	cin >> c;
}