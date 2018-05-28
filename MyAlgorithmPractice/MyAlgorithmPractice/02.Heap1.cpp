#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dump(vector<int> &v) {
	for (auto i : v) {
		cout << " " << i;
	}
	cout << endl;
}

void heap_test() {
	vector<int> v = { 3, 4, 5, 8, 6, 3, 2, 1, 1, 9 };

	make_heap(v.begin(), v.end());  // vector 를  heap으로 만들기

	dump(v);

	pop_heap(v.begin(), v.end());  // 제일 큰앞 값을 맨 뒤로 보내기

	dump(v);

	v.pop_back();                  // 맨뒤 값을 지우기..

	dump(v);

	v.push_back(10);               // 맨뒤에 새 값을 추가 하기

	dump(v);

	push_heap(v.begin(), v.end()); // 맨뒤의 값을  heap에 추가 하기. 

	dump(v);
}


int main() {
	heap_test();

	getchar();

}