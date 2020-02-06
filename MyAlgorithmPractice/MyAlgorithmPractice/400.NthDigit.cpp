#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
	// date: 2016-09-18     location: Vista Del Lago III Apartments
public:
	int findNthDigit(int n)
	{
		// step 1. calculate how many digits the number has.
		long base = 9, digits = 1;
		while (n - base * digits > 0)
		{
			n -= base * digits;
			base *= 10;
			digits++;
		}

		// step 2. calculate what the number is.
		int index = n % digits;
		if (index == 0)
			index = digits;
		long num = 1;
		for (int i = 1; i < digits; i++)
			num *= 10;
		num += (index == digits) ? n / digits - 1 : n / digits;;

		// step 3. find out which digit in the number is we wanted.
		for (int i = index; i < digits; i++)
			num /= 10;
		return num % 10;
	}
};
class _Solution {
public:
	int findNthDigit(int n) {

		int rdx = 1;
		int idx = 0;

		int i = 1;
		do {
			if (i < (1 * pow(10,rdx))) {
				idx += rdx;
			}
			else {
				rdx++;
				idx += rdx;
			}
			i++;
		} while (idx < n);

		int bk = idx - n;
		string st = to_string(i-1);

		return st[st.size() - bk - 1] - '0';
	}
};

int main() {
	char c;
	Solution sol;

	cout << sol.findNthDigit(1000000000);
	cin >> c;
}