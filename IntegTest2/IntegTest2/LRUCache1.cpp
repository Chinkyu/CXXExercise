#define <iostream>
#define <memory>

class Pare {
	int key;
	int value;
};

class MyQueue {
public:
	int mSize;

	MyQueue(int size) {
		mSize = size;
	}

	bool enqueue(int key, int value);
	int dequeue();  // returen key
	int dequeue(int key);
};


class MyHash {
public:
	int mSize;
	unique_ptr<Pare[]> mHt;

	MyHash(int size) {
		mSize = size*2;   // temporary *2
		mHt = make_unique<pare[]>(mSize);
	}

	~MyHash() {

	}

	int hash(int key);
	int find(int key, int &value);
};

class LRUCash {
public:
	int mCapacity = 0;
	struct pare tb[MAX_CAPACITY];

	int mCount = 0;

	int find(int key) {
		unsigned long h = hash(key);
		int cnt = mCapacity;
		int step = 1;

		if (tb[h] == key)
		{
			return tb[h].value;
		}
		else {
			// check next item... for find key... : XXX 

		}

		return -1;
	}


	int add(int key, int value) {
		unsigned long h = hash(key);

		tb[h].key = key;
		tb[h].value = value;
		return value;
	}

	LRUCache(int capacity) {
		mCapacity = capacity;
		mCount = 0;
	}


	int get(int key) {
		return find(key);
	}

	// Replace if the entry exists or add the entry otherwise 
	// If no space available, remove LRU item and add the new one. 
	void set(int key, int value) {
		add(key, value);
	}
};


int main() {

	cout << "print..." << endl;
}