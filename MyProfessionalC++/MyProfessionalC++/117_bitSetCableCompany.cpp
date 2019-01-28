#include <iostream>
#include <bitset>
#include <map>

using namespace std;

const size_t kNumChannels = 10;
class CableCompany {
public:
	void addPackage(const string& packageName, const bitset<kNumChannels>& channels);
	void removePackage(const string& packageName);
	void newCustomer(const string& name, const string& package);
	void newCustomer(const string& name, const bitset<kNumChannels>& channels);

	void addChannel(const string&name, int channel);
	void removeChannel(const string&name, int channel);
	void addPackageToCustomer(const string& name, const string& package);

	void deleteCustomer(const string& name);
	bitset<kNumChannels>& getCustomerChannels(const string& name);
private:
	typedef map <string, bitset<kNumChannels>> MapType;
	MapType mPackages, mCustomers;
};

void CableCompany::addPackage(const string& packageName, const bitset<kNumChannels>& channels) {
	mPackages.insert({ packageName, channels });
}

void CableCompany::removePackage(const string& packageName) {
	mPackages.erase(packageName);
}

void CableCompany::newCustomer(const string& name, const string& package) {
	auto it = mPackages.find(package);
	if (it == end(mPackages)) {
		// there is no package
		throw out_of_range("Invalid package");
	}

	auto result = mCustomers.insert({ name, it->second });
	if (!result.second) {
		throw invalid_argument("Duplicated customer");
	}
}

void CableCompany::newCustomer(const string& name, const bitset<kNumChannels>& channels) {

	auto result = mCustomers.insert({ name, channels });
	if (!result.second) {
		throw invalid_argument("Duplicated customer");
	}
}

void CableCompany::addChannel(const string& name, int channel) {
	auto it = mCustomers.find(name);
	if (it != end(mCustomers)) {
		it->second.set(channel);
	}
	else {
		throw invalid_argument("Unknown customer");
	}
}

void CableCompany::removeChannel(const string& name, int channel) {
	auto it = mCustomers.find(name);
	if (it != mCustomers.end()) {
		it->second.reset(channel);
	}
	else {
		throw invalid_argument("Unknown customer");
	}
}

void CableCompany::addPackageToCustomer(const string& name, const string& package) {
	auto itPack = mPackages.find(package);
	if (itPack == end(mPackages)) {
		throw out_of_range("Invalid package");
	}

	auto itCust = mCustomers.find(name);
	if (itCust != end(mCustomers)) {
		itCust->second |= itPack->second;
	}
	else {
		throw invalid_argument("Unknown customer");
	}
}

void CableCompany::deleteCustomer(const string& name) {
	auto it = mCustomers.erase(name);
}

bitset<kNumChannels>& CableCompany::getCustomerChannels(const string& name) {
	auto it = mCustomers.find(name);

	if (it == end(mCustomers)) {
		throw invalid_argument("Unknown customer");
	}

	return it->second;
}

int  main() {
	char c;
	CableCompany myCC;
	auto basic_pkg = "1111000000";
	auto premium_pkg = "1111111111";
	auto sports_pkg = "0000100111";
	myCC.addPackage("basic", bitset<kNumChannels>(basic_pkg));
	myCC.addPackage("premium", bitset<kNumChannels>(premium_pkg));
	myCC.addPackage("sports", bitset<kNumChannels>(sports_pkg));
	myCC.newCustomer("Marc G.", "basic");
	myCC.addPackageToCustomer("Marc G.", "sports");
	cout << myCC.getCustomerChannels("Marc G.") << endl;

	cin >> c;
}