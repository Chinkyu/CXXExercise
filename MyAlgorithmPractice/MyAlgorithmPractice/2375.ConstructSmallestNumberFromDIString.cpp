// �� ����..  ����� ������.. ��� ���� ����� �ʴ� ���� ����.
// ������� ������ ����� ����....
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
	string smallestNumber(string pattern) {
		string smallestNumber(string pattern) {
			string result;
			stack<int> s;
			for (int i = 0; i <= pattern.length(); i++)
			{
				s.push(i + 1);
				if (i == pattern.length() || pattern[i] == 'I')
				{
					while (!s.empty())
					{
						result += to_string(s.top());
						s.pop();
					}
				}
			}

			return result;
		}
	}
};

int main() {
	char c;

	Solution sol;

	vector<vector<int>> edges = { {-1, -1}, {0, 5}, {0, 10}, {2, 6}, {2, 4} };

	cout << sol.maxScore(edges);

	cin >> c;
}