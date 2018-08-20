#include <iostream>
#include <unordered_map>

using namespace std;

void unordered_map_test() {
	unordered_map<int, int> umap;

	for (int i = 0; i < 10; i++) {
		umap[i] = i * 10;
	}

	cout << umap.size() << endl;
}


int main() {
	char c;

	unordered_map_test();
	cout << "unordered_map_test" << endl;
	cin >> c;
}