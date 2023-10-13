//  not hard
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

class NumberContainers {
public:
	map<int, set<int>> number_indexes;
	map<int, int>  index_number;
	NumberContainers() {
		number_indexes.clear();
	}

	void change(int index, int number) {
		if (index_number.find(index) != index_number.end()) {
			int pre_num = index_number[index];
			index_number[index] = number;

			number_indexes[pre_num].erase(index);
			//number_indexes[number].insert(index);
		}

		number_indexes[number].insert(index);
		index_number[index] = number;

	}

	int find(int number) {
		//return begin(number_indexes[number])
		if (number_indexes[number].size() <= 0) return -1;
		return *begin(number_indexes[number]);
	}
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

int main() {
	char c;

	FoodRatings sol;

	vector<int> edges = { 4,4,8,-1,9,8,4,4,1,1 };
	cout << sol.closestMeetingNode(edges, 5, 6);

	cin >> c;

}