//쉽게 풀림.. 

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

class MyLinkedList {
public:
	vector<int> v;
	MyLinkedList() {
		v.clear();
	}

	int get(int index) {

		if (index < 0 || v.size() <= index) return -1;

		return v[index];
	}

	void addAtHead(int val) {
		v.insert(v.begin(), val);
	}

	void addAtTail(int val) {
		v.push_back(val);
	}

	void addAtIndex(int index, int val) {
		if (index < 0 || v.size() < index) return;
		if (v.size() == index) {
			v.push_back(val); 
			return;
		}

		auto it = v.begin() + index;
		v.insert(it, val);
	}

	void deleteAtIndex(int index) {
		if (index < 0 || v.size() <= index) return;

		auto it = v.begin() + index;
		v.erase(it);
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
	char c;

	Solution sol;

	//string s = "(123)";
	//string s = "(0123)";
	string s = "(00011)";
	vector<string> ans = sol.ambiguousCoordinates(s);

	for (auto it : ans) {
		cout << it << endl;
	}

	//	cout << sol.countHighestScoreNodes(parents) << endl;
	//	cout << "test : " << ans << endl;

	cin >> c;
}