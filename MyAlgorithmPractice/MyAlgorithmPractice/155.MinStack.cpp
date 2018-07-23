// Solution
// Solve this problem from hint...... -> This is very important hint for me


#include <iostream>
#include <stack>

using namespace std;

#define  MIN_MAX INT_MAX

class MinStack {
public:

	stack<pair<int, int>> stk;
	int min;

	/** initialize your data structure here. */
	MinStack() {
		min = MIN_MAX;
	}

	void push(int x) {
		stk.push(make_pair(x, min));
		if (min > x) min = x;
	}

	void pop() {
		min = stk.top().second;
		stk.pop();
	}

	int top() {
		return stk.top().first;
	}

	int getMin() {
		return min;
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/



int main() {
	char c;
	MinStack minStack;

	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << endl;   //--> Returns - 3.
	minStack.pop();
	cout << minStack.top() << endl;      //--> Returns 0.
	cout << minStack.getMin() << endl;   //--> Returns - 2.

	cin >> c;
}