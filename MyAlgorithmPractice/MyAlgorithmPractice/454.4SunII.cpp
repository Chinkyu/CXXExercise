#include <iostream>
#include <vector>
#include <map>

using namespace std;

class _Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int cnt = 0;
		for (auto it : A) {
			for (auto jt : B) {
				for (auto kt : C) {
					for (auto lt : D) {
						int sum = it + jt + kt + lt;
						if (sum == 0) cnt++;
					}
				}
			}
		}
		return cnt;
	}
};

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int cnt = 0;
		map<int, int> m;

		for (auto it : A) {
			for (auto jt : B) {
				if (m.find(it + jt) == m.end()) {
					m[it + jt] = 1;
				}
				else {
					m[it + jt]++;
				}
			}
		}


		for (auto kt : C) {
			for (auto lt : D) {
				int sum = (kt + lt) * -1;
				if (m.find(sum) != m.end()) {
					cnt += m[sum];
				}
			}
		}

		return cnt;
	}
};