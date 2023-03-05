// ���� ���ߴ� ������ ¥�� �ϴ°��̶�.. map lower_bound�� ������ �ϴµ�
// �ð��� �� ���� �ɷ�����.. �׳� �޶� ������� ���� Ǯ������ ����.
// �� ���ķδ� �� ���� ����. 
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
	int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {

		map<int, int> b;

		// retulate warehoust
		int min = warehouse[0];
		for (int i = 1; i < warehouse.size(); ++i) {
			if (min > warehouse[i]) min = warehouse[i];
			warehouse[i] = min;
		}

		sort(boxes.begin(), boxes.end());
		reverse(warehouse.begin(), warehouse.end());

		for (auto it : boxes) {
			if (b.find(it) == b.end()) {
				b[it] = 1;
			} else {
				b[it]++;
			}
		}

		int ans = 0;
		for (int i = 0; i < warehouse.size(); ++i) {
			auto it = b.lower_bound(warehouse[i]);

			if (it != b.end() && (*it).first == warehouse[i]) {
				(*it).second--;
				if ((*it).second <= 0) b.erase(it);
				ans++;
			}
			else {
				if (it != b.begin()) {
					it--;
					(*it).second--;
					if ((*it).second <= 0) b.erase(it);
					ans++;
				}
				// can't put box because there is not fit box
			}
		}

		return ans;
	}
};

int main() {
	char c;

	Solution sol;

//	vector<int> boxes = { 4, 3, 4, 1 };
//	vector<int> warehouse = { 5, 3, 3, 4, 1 };

	vector<int> boxes = { 1, 2, 2, 3, 4 };
	vector<int> warehouse = { 3, 4, 1, 2 };

	cout << sol.maxBoxesInWarehouse(boxes, warehouse);

	cin >> c;
}