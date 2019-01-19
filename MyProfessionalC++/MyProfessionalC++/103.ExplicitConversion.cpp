#include <iostream>
#include <string>
#include <vector>

using namespace std;

// explicit conversion
class IntWrapper {
public:
	IntWrapper(int i) : mInt(i) {}
	explicit operator int() const { 
		cout << "int() operator triggered" << endl;
		return mInt; 
	}
private:
	int mInt;
};

int main() {
	char c;

	IntWrapper a(123);

//	int i = a;   // - make compile due to explicit operator overloading prohibit implicit conversion
	int i = static_cast<int>(a);

	cin >> c;
	return 0;
}
