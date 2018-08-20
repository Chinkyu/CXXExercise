// comparison betwwen order map and unordered map   from geeksforgeeks


#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

void unordered_map_test() {
	unordered_map<int, int> umap;

	umap[5] = 10;
	umap[3] = 5;
	umap[20] = 100;
	umap[1] = 1;

	for (auto it = umap.begin(); it != umap.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
	cout << endl;
}


void ordered_map_test() {
	map<int, int> omap;

	omap[5] = 10;
	omap[3] = 5;
	omap[20] = 100;
	omap[1] = 1;

	for (auto it = omap.begin(); it != omap.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
	cout << endl;
}


int main() {
	char c;

	ordered_map_test();
	unordered_map_test();

	cin >> c;
}