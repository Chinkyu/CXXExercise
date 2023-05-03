// low_bound 이용 및 몇가지 예외 케이스 때문에 시간이 좀 걸임.. 
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
	int findLatestStep(vector<int>& arr, int m) {
		int l = arr.size();
		vector<int> bitmap(l, 0);
		map<int, int> occupy_map;
		int m_count = 0;
		bool m_count_start = false;
		int idx_m_count_zero = -1;

		if (arr.size() == m ) return m;

		for (int i = 0; i < l; ++i) {
			int at = arr[i] - 1;
			bitmap[at] = 1;
			occupy_map[at] = 1;
			if (occupy_map[at] == m) m_count++;

			// handle after
			if (at < l - 1 && bitmap[at + 1] == 1) {
				if (occupy_map[at] == m) m_count--;
				occupy_map[at] = occupy_map[at + 1] + 1;
				if (occupy_map[at] == m) m_count++;
				if (occupy_map[at + 1] == m) m_count--;
				occupy_map.erase(at + 1);

			}

			// handle before
			auto it = occupy_map.lower_bound(at);

			if (it == occupy_map.end()) --it;
			while (at <= (*it).first && it != occupy_map.begin()) it--;

			if ((*it).first < at && (*it).first + (*it).second == at) {
				if ((*it).second == m) m_count--;
				(*it).second += occupy_map[at];
				if ((*it).second == m) m_count++;
				if (occupy_map[at] == m) m_count--;
				occupy_map.erase(at);
			}

			// check m_count 
			if (m_count_start == false && m_count > 0) m_count_start = true;
			if (m_count_start == true && m_count == 0) {
				idx_m_count_zero = i; m_count_start = false;
			}
		}
		return idx_m_count_zero;
	}
};

int main() {
	char c;

	Solution sol;

	vector<int> arr = { 4, 3, 2, 1 }; // { 3, 5, 1, 2, 4 };

	cout << sol.findLatestStep(arr, 1);

	cin >> c;
}