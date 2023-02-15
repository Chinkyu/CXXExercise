// Accepted... 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class SnapshotArray {
public:

	unordered_map<int, unordered_map<int,int>> m;
	unordered_map<int,int> c;
	int len = 0;
	int snap_idx = -1;

	SnapshotArray(int length) : len(length) {
		
	}

	void set(int index, int val) {
		c[index] = val;
	}

	int snap() {
		snap_idx++;
		m[snap_idx] = c;
		return snap_idx;
	}

	int get(int index, int snap_id) {
		return m[snap_id][index];
	}
};



class SnapshotArray1 {
public:

	unordered_map<int, vector<int>> m;
	vector<int> c;
	int len = 0;
	int snap_idx = -1;
	SnapshotArray1(int length) : len(length) {
		c = vector<int>(len, 0);
	}

	void set(int index, int val) {
		c[index] = val;
	}

	int snap() {
		snap_idx++;
		m[snap_idx] = c;
		return snap_idx;
	}

	int get(int index, int snap_id) {
		return m[snap_id][index];
	}
};




int main() {
	char c;
	SnapshotArray sol(3);

	//cout << sol.btreeGameWinningMove(NULL, 5, 1) << endl;

	//	cout << "test : " << ans << endl;

	cin >> c;
}