#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int max = 0;
	int tM = 0;
	int tN = 0;
	int mLength = 0;

	void iterate(vector<string> &strs, vector<bool> &tt, int sm, int sn, int idx, int iCnt) {

		if (idx >= mLength) return;

		// not have it -------------------------------
		tt[idx] = false;
		iterate(strs, tt, sm, sn, idx+1, iCnt);

		tt[idx] = true;
		// have it -----------------------------------
		for (auto it : strs[idx]) {
			if (it == '0') sm++;
			else sn++;
		}

		if (sm == tM && sn == tN) {
			cout << "Bingo" << endl;
			if (max < iCnt) max = iCnt+1;
		}

		if (sm > tM || sn > tN) return;

		iterate(strs, tt, sm, sn, idx + 1, iCnt + 1);
	}

	int findMaxForm(vector<string>& strs, int m, int n) {
		int l = strs.size();
		vector<bool> tt(l, false);

		tM = m;
		tN = n;
		mLength = l;

		iterate(strs, tt, 0, 0, 0, 0);

		return max;
	}
};

int main() {
	char c;
	Solution sol;
	vector<string> v = {"10", "0001", "111001", "1", "0"};// { "10", "0", "1" }; // { "10", "0001", "111001", "1", "0" };

	cout << sol.findMaxForm(v, 3, 4);

	cin >> c;
}
