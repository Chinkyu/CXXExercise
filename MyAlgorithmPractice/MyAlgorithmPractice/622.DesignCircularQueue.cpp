#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyCircularQueue {
public:
	vector<int> v;
	int st = 0, ed = 0;
	int count, size;
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) : v(k) {
		st = ed = 0;
		count = 0;
		size = k;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (count >= size) return false;
		v[ed++] = value;
		count++;
		ed %= size;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (count <= 0) return false;
		//int ans = v[st++];
		st++;
		st %= size;
		count--;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (count <= 0) return -1;
		return v[st];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (count <= 0) return -1;
		int ted = ed;
		ted--;
		if (ted < 0) ted = size - 1;
		return v[ted];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return (count <= 0);
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return (count >= size);
	}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */