#include <iostream>
#include <set>
#include <list>

using namespace std;

class AccessList {
public:
	AccessList() = default;
	AccessList(const initializer_list<string>& initlst);
	void addUser(const string& user);
	void removeUser(const string& user);
	bool isAllowed(const string& user) const;
	list<string> getAllUsers() const;

private:
	set<string> mAllowed;
};

AccessList::AccessList(const initializer_list<string>& initlst) {
	for (auto& user : initlst) {
		addUser(user);
	}
}

void AccessList::addUser(const string& user) {
	mAllowed.insert(user);
}

void AccessList::removeUser(const string& user) {
	mAllowed.erase(user);
}

bool AccessList::isAllowed(const string& user) const {
	return (mAllowed.count(user) != 0);
}

list<string> AccessList::getAllUsers() const {
	list<string> users;
	users.insert(end(users), begin(mAllowed), end(mAllowed));
	return users;
}


int main() {
	char c;
	AccessList fileX = { "pvw", "mgregoire", "baduser" };
	fileX.removeUser("baduser");
	if (fileX.isAllowed("mgregoire")) {
		cout << "mgregoire has permissions" << endl;
	}
	if (fileX.isAllowed("baduser")) {
		cout << "baduser has permission" << endl;
	}
	auto users = fileX.getAllUsers();
	for (const auto& user : users) {
		cout << user.c_str() << " ";
	}

	cin >> c;
}