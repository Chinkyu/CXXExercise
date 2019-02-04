#include <iostream>
#include <queue>

using namespace std;

void pQueueTest1() {
	priority_queue<int> myQueue;

	myQueue.push(3);
	myQueue.push(6);
	myQueue.push(2);
	myQueue.push(7);
	myQueue.push(1);

	while (!myQueue.empty()) {
		cout << myQueue.top() << endl;
		myQueue.pop();
	}
}

void pQueueTest2() {
	priority_queue<int, vector<int>, greater<>> myQueue;   // <== transparent operator function

	myQueue.push(3);
	myQueue.push(6);
	myQueue.push(2);
	myQueue.push(7);
	myQueue.push(1);

	while (!myQueue.empty()) {
		cout << myQueue.top() << endl;
		myQueue.pop();
	}
}

int main() {
	char c;
	pQueueTest1();
	pQueueTest2();

	cin >> c;

}