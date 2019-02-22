#include <iostream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

using VotersMap = map<string, list<string>>;
using DistrictPair = pair<const string, list<string>>;

set<string> getDuplicate(const VotersMap& votersByDistrict) {
	list<string> allNames;
	for (auto& district : votersByDistrict) {
		allNames.insert(end(allNames), begin(district.second), end(district.second));
	}

	allNames.sort();
	set<string> duplicates;
	for (auto lit = cbegin(allNames); lit != cend(allNames); ++lit) {
		lit = adjacent_find(lit, cend(allNames));
		if (lit == cend(allNames)) {
			break;
		}
		duplicates.insert(*lit);
	}
	return duplicates;
}


void auditVoterRolls(VotersMap& votersByDistrict, const list<string>& convictedFelons) {

	// get all the duplicate name 
	set<string> toRemove = getDuplicate(votersByDistrict);
	toRemove.insert(cbegin(convictedFelons), cend(convictedFelons));

	for_each(votersByDistrict.begin(), votersByDistrict.end(), 
		[&toRemove](DistrictPair& district) {
		auto it = remove_if(begin(district.second), end(district.second), 
			[&toRemove](const string& name) { return (toRemove.count(name) > 0);
		});
		district.second.erase(it, end(district.second));
		}
	);
}

int main() {
	char c;

	// Initialize map using uniform initialization
	VotersMap voters = {
	{"Orange", {"Amy Aardvark", "Bob Buffalo","Charles Cat", "Dwayne Dog"}},
	{"Los Angeles", {"Elizabeth Elephant", "Fred Flamingo", "Amy Aardvark"}},
	{"San Diego", {"George Goose", "Heidi Hen", "Fred Flamingo"}}
	};
	list<string> felons = { "Bob Buffalo", "Charles Cat" };
	// Local lambda expression to print a district
	auto printDistrict = [](const DistrictPair& district) {
		cout << district.first << ":";
		for (auto& str : district.second) {
			cout << " {" << str << "}";
		}
		cout << endl;
	};

	cout << "Before Audit:" << endl;
	for_each(cbegin(voters), cend(voters), printDistrict);
	cout << endl;
	auditVoterRolls(voters, felons);
	cout << "After Audit:" << endl;
	for_each(cbegin(voters), cend(voters), printDistrict);
	cout << endl;

	cin >> c;
}