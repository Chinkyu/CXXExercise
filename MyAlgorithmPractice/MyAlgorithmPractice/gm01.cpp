#include <iostream>
#include <string>
using namespace std;

int main() {
	string line;
	int num;
	long long sum;
	while (getline(cin, line)) {
		num = stoi(line);
		sum = 0;

		// Assert num should larger than 0
		if (num <= 0) return -1;

		for (int i = 1; i <= num; i++) {
			if (i % 5 == 0) continue;
			if (i % 7 == 0) continue;
			sum += i;
		}
		cout << sum << endl;
	}
}
