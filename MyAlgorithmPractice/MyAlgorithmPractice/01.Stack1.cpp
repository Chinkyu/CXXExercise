#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;


void stack_test1() {
	stack<int> st;

	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.push(7);
	st.push(8);


	while (!st.empty()) {
		cout << " " << st.top();
		st.pop();
	}
	cout << endl;
}

void queue_test1() {
	queue<int> qu;

	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	qu.push(5);
	qu.push(6);
	qu.push(7);
	qu.push(8);

	while (!qu.empty()) {
		cout << " " << qu.front();
		qu.pop();
	}
	cout << endl;
}

int main() {

	stack_test1();
	queue_test1();

	getchar();

}