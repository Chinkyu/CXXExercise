#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template<typename T>
void pop_dump(T &q) {

	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;

}

void test_priority_queue1() {
	priority_queue<int> pq;

	for (int i : {0, 4, 6, 8, 9, 10, 2, 5}) {
		pq.push(i);
	}
	pop_dump(pq);
}

void test_priority_queue2() {
	priority_queue<int, vector<int>, std::greater<int> > pq;

	for (int i : {0, 4, 6, 8, 9, 10, 2, 5}) {
		pq.push(i);
	}
	pop_dump(pq);
}


int main() {
	test_priority_queue1();
	test_priority_queue2();
	getchar();
}