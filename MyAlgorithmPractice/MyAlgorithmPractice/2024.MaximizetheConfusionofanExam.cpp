// Ǯ�ٰ���.


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

// timeout  �ε�  �����̵� ������ ����ؾ���... 
class Solution {
public:
	int maxConsecutiveAnswers(string answerKey, int k) {
		int mLen = 0, l = answerKey.size();

		if (l == 1 || k == 1) return 1;

		for (int i = 0; i < l - k; ++i) {
			int tCount = 0, fCount = 0;
			for (int j = i; j < l; ++j) {
			
				if (answerKey[j] == 'T') tCount++;
				else fCount++;

				if (min(tCount, fCount) > k) {
					mLen = max(mLen, j - i);
					break;
				}

				if (j == l - 1) {
					mLen = max(mLen, j - i + 1);
				}
			}
		}

		return mLen;

	}
};

int main() {
	char c;
	Solution sol;

	string answerKey = "TFFT";
	cout << sol.maxConsecutiveAnswers(answerKey, 1);
	cin >> c;
}