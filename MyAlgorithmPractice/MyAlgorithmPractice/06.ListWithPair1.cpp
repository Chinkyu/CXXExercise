#include <iostream>
#include <list>
using namespace std;

void list_pair_test() {
	list<pair<int, int>> lst;

	pair<int, int> p1;
	
	p1 = make_pair(1, 1);


	lst.push_back(make_pair(1, 1));
	lst.push_back(make_pair(2, 2));
	lst.push_back(make_pair(3, 3));
	lst.push_back(make_pair(4, 4));
	lst.push_back(make_pair(5, 5));

	lst.erase(lst.begin());
//	lst.erase(lst.cend());
	lst.pop_back();



}


int main() {
	char c;

	list_pair_test();
	cin >> c;
}