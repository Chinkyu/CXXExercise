#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

class Solution1 {
public:
	int ans = 0;

	void findDecodeNumber(int sti, string &iString) {
		int edi = iString.length() - 1;

		if (sti >= edi) {   // if sti == endi, doesn't need cound only one way
			ans++;
			return;
		}

		// Always more than two number
		int n1 = iString[sti] - '0';
		findDecodeNumber(sti + 1, iString);

		int n2 = (iString[sti] - '0') * 10 + (iString[sti + 1] - '0');
		if (26 >= n2) {
			findDecodeNumber(sti + 2, iString);
		}
	}

	int getDecodeNumber() {
		string iString;

		getline(cin, iString);

		ans = 0;
		findDecodeNumber(0, iString);

		return ans;
	}
};


class Solution2 {
public:
	int ans = 0;

	void findDecodeNumber(string &iString) {
		int edIdx = iString.length() - 1;
		queue<int> idxQ;

		idxQ.push(0);
		while (!idxQ.empty()) {
			int i = idxQ.front();
			idxQ.pop();

			if (i >= edIdx) {  // End index  count up
				ans++;
				continue;
			}

			// assert : if (i +1 <= edIdx ) 
			// this number
			idxQ.push(i + 1);

			if ((i + 1 <= edIdx)  
				&& (26 >= (iString[i] - '0') * 10 + (iString[i + 1] - '0'))) {
				idxQ.push(i + 2);
			}

		}
	}

	int getDecodeNumber() {
		string iString;

		getline(cin, iString);

		ans = 0;
		findDecodeNumber(iString);

		return ans;
	}
};


int main() {
	int i;
	char c;
	Solution1 s1;
	Solution2 s2;

//	cout << s1.getDecodeNumber() << endl;
	cout << s2.getDecodeNumber() << endl;

	cin >> c;
}