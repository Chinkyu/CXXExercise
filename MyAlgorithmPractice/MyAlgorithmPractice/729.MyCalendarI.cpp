// map을 가지고 처리 하면 되고...  lower_bound 가지고 아래단 값을 찾는것
// 그리고   OFF/ON 이 한곳에서 일어 날때  그 해당 값을 지우는것 때문에..
// 디버깅 하면서...  시간이 좀 걸림.. 
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

class MyCalendar {
public:
	map<int, int> m;
	MyCalendar() {
		m.clear();
	}

	bool book(int start, int end) {

		// check start
		auto it = m.lower_bound(start);		if (it == m.end()) {
			if (m.find(start) != m.end()) m.erase(start);  else m[start] = 1;
			if (m.find(end) != m.end()) m.erase(end); else  m[end] = 0;
			return true;
		}
		
		while ((*it).first > start && it != m.begin()) it--;

		if ((*it).first <= start && (*it).second == 1) return false;

		if (it != m.begin()) it++;  // if it is m.begin(), it should be chanecked with end

		if (it != m.end() && (*it).first < end) return false;
			   
		if (m.find(start) != m.end()) m.erase(start);  else m[start] = 1;
		if (m.find(end) != m.end()) m.erase(end); else m[end] = 0;
		return true;
	}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main() {
	char c;

	MyCalendar* obj = new MyCalendar();

	vector<vector<int>> v = { {20, 29}, {13, 22}, {44, 50}, {1, 7}, {2, 10}, {14, 20}, {19, 25}, {36, 42}, {45, 50}, {47, 50}, {39, 45}, {44, 50}, {16, 25}, {45, 50}, {45, 50}, {12, 20}, {21, 29}, {11, 20}, {12, 17}, {34, 40}, {10, 18}, {38, 44}, {23, 32}, {38, 44}, {15, 20}, {27, 33}, {34, 42}, {44, 50}, {35, 40}, {24, 31} };

	for (auto it : v) {
		cout << " " << obj->book(it[0], it[1]);
	}

//	cout << obj->book(37, 50) << endl;
//	cout << obj->book(33, 50) << endl;
//	cout << obj->book(4, 17) << endl;
//	cout << obj->book(35, 48) << endl;
//	cout << obj->book(8, 25) << endl;

	cin >> c;
}