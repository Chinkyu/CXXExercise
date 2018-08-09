#include <iostream>
#include <string>
using namespace std;

int main() {
	string line;
	bool isUpper = true;
	while (getline(cin, line)) {
		
		isUpper = true;

		for (int i = 0; i < line.length(); i++) {
			if (isalpha(line[i])) {
				if (isUpper == true) {
					line[i] = toupper(line[i]);
					isUpper = false;
				}
				else {
					line[i] = tolower(line[i]);
					isUpper = true;
				}
			}
		}

		cout << line << endl;
	}
}
