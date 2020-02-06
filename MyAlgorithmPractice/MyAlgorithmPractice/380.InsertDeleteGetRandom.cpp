#include <iostream>
#include <unordered_set>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

class RandomizedSet {
public:
	unordered_set<int> s;
	/** Initialize your data structure here. */
	RandomizedSet() {
		s.clear();
		srand(time(NULL));
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		bool isNotExist = s.find(val) == s.end();
		s.insert(val);
		return isNotExist;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		bool isExist = s.find(val) != s.end();
		s.erase(val);
		return isExist;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int n = s.size();
		int random_variable = rand()%n;

		unordered_set<int>::iterator it = s.begin();
		for (int i = 0; i < random_variable; ++i) {
			it++;
		}
		return *it; // s.extract(s.begin() + random_variable);
	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */