#include <iostream>
#include <list>
#include <map>

using namespace std;

class BuddyList {
public:
	void addBuddy(const string& name, const string& buddy);
	void removeBuddy(const string & name, const string& buddy);
	bool isBuddy(const string& name, const string & buddy) const;
	list<string> getBuddies(const string& name) const;

private:
	multimap<string, string> mBuddies;
};

void BuddyList::addBuddy(const string& name, const string& buddy) {
	if (!isBuddy(name, buddy)) {
		mBuddies.insert({ name, buddy }); //using initializer_list
	}
}

void BuddyList::removeBuddy(const string& name, const string& buddy) {
	auto iter = mBuddies.lower_bound(name);
	auto end = mBuddies.upper_bound(name);

	for (; iter != end; ++iter) {
		if (iter->second == buddy) {
			mBuddies.erase(iter);
			break;
		}
	}
}

bool BuddyList::isBuddy(const string& name, const string& buddy) const {
	// using equal_range();
	auto range = mBuddies.equal_range(name);
	auto iter = range.first;
	auto end = range.second;

	for (; iter != end; ++iter) {
		if (iter->second == buddy) {
			return true;
		}
	}
	return false;
}

list<string> BuddyList::getBuddies(const string& name) const {
	auto range = mBuddies.equal_range(name);
	auto iter = range.first;
	auto end = range.second;

	list<string> buddies;
	for (; iter != end; ++iter) {
		buddies.push_back(iter->second);
	}
	return buddies;
}

int main() {
	char c;
	BuddyList buddies;

	buddies.addBuddy("Harry Potter", "Ron Weasley");
	buddies.addBuddy("Harry Potter", "Hermione Granger");
	buddies.addBuddy("Harry Potter", "Hagrid");
	buddies.addBuddy("Harry Potter", "Draco Malfoy");

	// Remove Draco
	buddies.removeBuddy("Harry Potter", "Draco Malfoy");
	buddies.addBuddy("Hagrid", "Harry Potter");
	buddies.addBuddy("Hagrid", "Ron Weasley");
	buddies.addBuddy("Hagrid", "Hermione Granger");
	auto harryBuds = buddies.getBuddies("Harry Potter");
	
	cout << "Harry's friends : " << endl;
	for (const auto& name : harryBuds) {
		cout << "\t" << name.c_str() << endl;
	}

	cin >> c;
}