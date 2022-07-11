#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

class Leaderboard {
public:
#if 0
	bool isOneEditDistance(string s, string t) {

		// Make counter variable
		map<char, int> m1, m2;

		for (auto it : s) {
			if (m1.find(it) == m1.end()) {
				m1[it] = 1;
			} 
			else {
				m1[it]++;
			}
		}

		for (auto it : t) {
			if (m2.find(it) == m2.end()) {
				m2[it] = 1;
			}
			else {
				m2[it]++;
			}
		}

		int sl = s.length();
		int tl = t.length();
		if (sl + 1 == tl) {

		}
		else if (sl == t1 + 1) {


		}
		else if (sl == tl) {

		}
		else {
			return false;
		}

	}
#endif 

	bool isOneEditDistance(string s, string t) {
		int sl = s.size(), st = t.size();
		int diff = abs(sl - st);

		if (s == t || diff > 1) return false;

		int i = 0, j = 0;
		bool isDiffFound = false;
		while (i < sl && j < st) {
			if (s[i] != t[j]) {
				if (isDiffFound == true) return false;

				if (sl >= st) i++;
				if (sl <= st) j++;
				isDiffFound = true;
			}
			else {
				i++;
				j++;
			}
		}
		return true;
	}
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */



int main() {
	char c;
	Leaderboard* obj = new Leaderboard();


	cin >> c;
}
