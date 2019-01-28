#include <iostream>
#include <map>

using namespace std;

class BankAccount {
public:
	BankAccount(int acctNum, const std::string& name)
		: mAcctNum(acctNum), mClientName(name) {}
	void setAcctNum(int acctNum) { mAcctNum = acctNum; }
	int getAcctNum() const { return mAcctNum; }
	void setClientName(const string& name) { mClientName = name; }
	const string& getClientName() const { return mClientName; }
private:
	int mAcctNum;
	string mClientName;
};

class BankDB {
public:
	bool addAccount(const BankAccount& acct);
	void deleteAccount(int acctNum);
	BankAccount& findAccount(int acctNum);
	BankAccount& findAccount(const string& name);
	void mergeDatabase(BankDB& db);

private:
	map<int, BankAccount> mAccounts;
};

bool BankDB::addAccount(const BankAccount& acct) {
	auto res = mAccounts.insert(make_pair(acct.getAcctNum(), acct));
	return res.second;
}

void BankDB::deleteAccount(int acctNum) {
	mAccounts.erase(acctNum);
}

BankAccount& BankDB::findAccount(int accNum) {
	auto it = mAccounts.find(accNum);
	if (it == end(mAccounts)) {
		throw out_of_range("No account with that number.");
	}
	return it->second;
	
	//	return mAccounts[accNum];
}

BankAccount& BankDB::findAccount(const string& name) {

	for (auto& p : mAccounts) {
		if (p.second.getClientName() == name) {
			// found it;
			return p.second;
		}
	}
	throw out_of_range("No account with that name.");
}

void BankDB::mergeDatabase(BankDB& db) {
	mAccounts.insert(begin(db.mAccounts), end(db.mAccounts));
	db.mAccounts.clear();
}


int main() {
	char c;

	BankDB db;
	db.addAccount(BankAccount(100, "Nicholas Solter"));
	db.addAccount(BankAccount(200, "Scott Kleper"));
	try {
		auto& acct = db.findAccount(100);
		cout << "Found account 100" << endl;
		acct.setClientName("Nicholas A Solter");

		auto& acct2 = db.findAccount("Scott Kleper");
		cout << "Found account of Scott kleper" << endl;
		auto& acct3 = db.findAccount(1000);
	} catch (const out_of_range&) {
		cout << "Unable to find account" << endl;
	}

	cin >> c;
}