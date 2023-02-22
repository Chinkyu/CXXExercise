// ó������  int  ���� ���� �ϴٰ�  string ���̰� 500������� ���� ����
// ��Ʈ������ ó�� �ϰ� �ߴµ�.. �׳�  PASS/..   
//  Memoization work ???  -  ��� pass��.. 
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
	unordered_map<string, int> memo_m;

	int numSteps(string s) {
		int ans = 0;
		string ws = s;

		while (!(ws.size() == 1 && ws.back() == '1')) {
			
			// memoization for best 
			if (memo_m.find(ws) != memo_m.end()) return memo_m[ws];

			if (ws.back() == '1') {
				ans++;
				//v += 1;
				int i = ws.size()-1;
				for (; i >= 0; --i) {
					if (ws[i] == '1') {
						ws[i] = '0';
					}
					else {
						ws[i] = '1';
						break;
					}

				}
				if (i == -1) ws.insert(0, 1, '1');

			}
			else {
				ans++;
				//v = v >> 1;
				ws.erase(ws.end()-1);
			}
		}

		memo_m[s] = ans;
		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	cout << sol.numSteps("1101");
	//	cout << "test : " << ans << endl;

	cin >> c;
}