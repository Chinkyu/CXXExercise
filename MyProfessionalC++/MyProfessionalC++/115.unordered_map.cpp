#include <iostream>
#include <unordered_map>

using namespace std;

template<class T>
void printMap(const T& m) {

	for (auto& p : m) {
		std::cout << p.first.c_str() << " (Phone: " << p.second.c_str() << ")" << endl;
	}
	cout << "-------" << endl;
}

int main() {
	char c;

	// Create a hash table
	unordered_map<string, string> um = {
		{"Marc G.", "123-456789" },
		{"Scott K.", "654-987321" } };
	printMap(um);

	// Add,remove some phone number.
	um.insert(make_pair("John D.", "321-987654"));
	um["Jonh G."] = "963-256147";
	um["Freddy K."] = "999-256256";
	um.erase("Freddy K.");
	printMap(um);

	// Find the bucket index for a specific key
	int bucket = um.bucket("Marc G.");
	cout << "Marc G. is in bucket" << bucket
		<< " which contains the following "
		<< um.bucket_size(bucket) << " elements:" << endl;

	// get begin and end iterator
	auto liter = um.begin(bucket);
	auto literEnd = um.cend(bucket);
	while (liter != literEnd) {
		cout << "\t" << liter->first.c_str() << " (Phone: " << liter->second.c_str() << ")" << endl;
		++liter;
	}
	cout << "---------------" << endl;

	// print some statics about the hash table 
	cout << "There are" << um.bucket_count() << " buckets." << endl;
	cout << "Average number of elements in bucket is " << um.load_factor() << endl;

	cin >> c;
	return 0;
}