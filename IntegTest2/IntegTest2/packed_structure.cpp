// unique ptr testing... 
#include <iostream>
#include <utility>
#include <memory>
#include <array>

using namespace std;

class Solution {
public:

	typedef struct {
		union {
			struct {
				uint8_t c;
				array<uint8_t, 10> ar;
			};
			array<uint8_t, 11> data;
		};
	} my_struct;


	void test() {

		array<uint8_t, 10> arr = { 0 };

		cout << arr.size() << " " << sizeof(arr) << endl;


		my_struct ms;
		ms.c = 1;
		ms.ar = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		cout << " " << sizeof(ms) << " " << endl;

		for (auto it : ms.data) {
			cout << it + '0' << " ";
		}
	}

};


int main()
{

	char c;

	Solution sol;

	sol.test();

	cin >> c;
}
