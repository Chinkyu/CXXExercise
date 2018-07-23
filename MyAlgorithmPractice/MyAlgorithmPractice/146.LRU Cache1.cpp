// list의 remove를 사용하는 솔루션으로 정리 하였으나
// 내용이 간단하지 않음...  좀 깐깐한 문제 임. 

#include <iostream>
#include <map>
#include <queue>
#include <list>

using namespace std;

class LRUCache {
public:
	list<int> mList;
	map<int, int> mMap;
	int mCapacity;

	LRUCache(int capacity) {
		mCapacity = capacity;
	}

	int get(int key) {
		if (mMap.find(key) == mMap.end()) return -1;

		// hit -> move to front
		mList.remove(key);
		mList.push_front(key);
		return mMap[key];
	}

	void put(int key, int value) {

		if (mMap.find(key) != mMap.end()) {  // if there is 
			mMap[key] = value;

			// hit -> move to front
			mList.remove(key);
			mList.push_front(key);
		}
		else {
			if (mList.size() >= mCapacity) {  // If there is no room remove one
				int k = mList.back();
				mList.pop_back();
				mMap.erase(k);
			}

			mList.push_front(key);
			mMap[key] = value;
		}
	}
};

/*
// Map을  list의  iterator로 만들어서 처리 하고자 하는 어려운 솔루션임.... 
// using list<int>::iterator
class LRUCache2 {
public:
//	map<int, int> mMap;
	list<pair<int, int>> mList;
	map<int, list<pair<int, int>>::iterator> mMap;  // make map for iterator of mList
	int mCapacity;

	LRUCache2(int capacity) {
		mCapacity = capacity;
	}

	int get(int key) {
		if (mMap.find(key) == mMap.end()) return -1;

		// if there is in cache
		int v = (*mMap[key]).second;  // get value 
		mList.erase(mMap[key]);  // erase function use iterator
		mList.push_front(make_pair(key, v));
		mMap[key] = mList.begin();
		return v;
	}

	void put(int key, int value) {

		if (mList.size() >= mCapacity) {
			int k = mList.back().first;
			mList.erase(mMap[k]);
//			mList.pop_back();
			mMap.erase(k);
		}
		
		mList.push_front(make_pair(key, value));
		mMap[key] = mList.begin();
	}
};

*/

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache obj = new LRUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/

int main() {
	int i;
	LRUCache cache = LRUCache(2 /* capacity */);

	cache.put(2, 1);
	cache.put(1, 2);
	cache.put(2, 3);
	cache.put(4, 1);
	cout << cache.get(1) << " ";       // returns 1
	cout << cache.get(2) << " ";       // returns 1


	cout << cache.get(1) << " ";       // returns 1
	cache.put(3, 3);    // evicts key 2
	cout << cache.get(2) << " ";       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cout << cache.get(1) << " ";       // returns -1 (not found)
	cout << cache.get(3) << " ";       // returns 3
	cout << cache.get(4) << " ";       // returns 4
	
	cin >> i;
}
