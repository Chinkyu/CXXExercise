#include <iostream>

#define MAX_NUM 10

#define MAX_CAPACITY  100
struct pare {
	int key;
	int value;
};

	int mCapacity = 0;
	struct pare tb[MAX_CAPACITY];

	int mCount = 0;

	int find(int key) {
		unsigned long h = hash(key);
		int cnt = mCapacity;
		int step = 1;

		if (strcmp(tb[h].key, key) == 0)
		{
			return tb[h].value;
		}

		return -1;
	}


	int add(int key, int value) {
		unsigned long h = hash(key);

		tb[h].key = key;
		tb[h].value = value;
		return value;
	}

	void LRUCache(int capacity) {
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

int main(int argc, char* argv[])
{
	int T, N, Q;

	LRUCache(10);





	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		memset(tb, 0, sizeof(tb));
		scanf("%d", &N);
		char k[MAX_KEY + 1];
		char d[MAX_DATA + 1];
		for (int i = 0; i < N; i++)
		{
			scanf("%s %s\n", &k, &d);
			add(k, d);
		}
		printf("#%d\n", test_case);
		scanf("%d", &Q);
		for (int i = 0; i < Q; i++)
		{
			char k[MAX_KEY + 1];
			char d[MAX_DATA + 1];

			scanf("%s\n", &k);
			if (find(k, d))
			{
				printf("%s\n", d);
			}
			else
			{
				printf("not find\n");
			}
		}
	}
	return 0;
}


void dump() {
	for (int i = 0; i < MAX_NUM; i++) {
		cout << i << " " << b[i] << endl;
	}
}

int main() {


	cout << "testing..." << endl;

	production2();
	dump();
	production3();
	dump();

}