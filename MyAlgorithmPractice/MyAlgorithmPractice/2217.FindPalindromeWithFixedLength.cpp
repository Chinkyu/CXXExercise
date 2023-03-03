// ��� �� �ȸ¾Ƽ� �Դ� ���� �ߴµ�...   ���� ���� Ǯ�� �־���
// �������� ���� ������ ����ϰ� ������ �ڿ� ���̴� ���
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <bitset>
#include <map>

using namespace std;

class Solution {
public:
	vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
		vector<long long> ans;

		for (auto it : queries) {
			int half_length = (intLength + 1) / 2;
			long long l = 1 * pow(10, half_length-1);
			l += (it - 1);

			string s = to_string(l);

			if (s.size() > half_length) {
				ans.push_back(-1);
				continue;
			}

			if (intLength > 1) {

				if ((intLength & 0x1) == 0x1) {  // if lengh is odd, reduce
					half_length--;
					s.pop_back();
				}
				reverse(s.begin(), s.end());

				l = l * pow(10, half_length);
				if (s.size() > 0) l += stol(s);
			}
			ans.push_back(l);
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> queries = { 5,4,1 };
	vector<long long> ans = sol.kthPalindrome(queries, 2);

	for (auto it : ans) {
		cout << " " << it;
	}
	cout << endl;

	cin >> c;
}