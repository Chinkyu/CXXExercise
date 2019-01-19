#include <iostream>
#include <list>
#include <string>

using namespace std;

void testListSplice() {
	list<string> dictionary { "aardvark", "ambulance" };
	list<string> bWords{ "bathos", "balderdash" };
	dictionary.push_back("canticle");
	dictionary.push_back("consumerism");

	if (bWords.size() > 0) {
		auto iterLastB = --(cend(bWords));
		auto it = cbegin(dictionary);
		for (; it != cend(dictionary); ++it) {
			if (*it > *iterLastB)
				break;
		}
		// add in the bwords. This action removes the elements from bWords
		dictionary.splice(it, bWords);
	}

	// print out the dictionary
	for (const auto& word : dictionary) {
		cout << word << endl;
	}
}

void main() {
	char c;

	testListSplice();

	cin >> c;
}