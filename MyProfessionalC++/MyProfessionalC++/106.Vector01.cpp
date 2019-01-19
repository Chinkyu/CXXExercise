
#include <vector>
#include <iostream>

using namespace std;

void vector_test1() {

	vector<double> doubleVector; // Create a vector with zero elements.
	// Initialize max to smallest number
	double max = -numeric_limits<double>::infinity();
	for (size_t i = 1; true; i++) {
		double temp;
		cout << "Enter score " << i << " (-1 to stop): ";
		cin >> temp;
		if (temp == -1) {
			break;
		}
		doubleVector.push_back(temp);
		if (temp > max) {
			max = temp;
		}
	}
	max /= 100.0;
	for (auto& element : doubleVector) {
		element /= max;
		cout << element << " ";
	}
}

class Element {
public:
	int e1;
	string name;

	Element(string n) : name(n) {};
};


void vector_test2(vector<Element> &v1) {
	Element e1("e1");
	Element *e2 = new Element("e2");
	auto e3 = make_unique<Element>("e3");

	v1.push_back(e1);
	v1.push_back(*e2);
	v1.push_back(*e3);
}

int main() {
	char c;
	vector <Element> v1;

//	vector_test1();
	vector_test2(v1);

	for (auto e : v1) {
		cout << e.name.c_str() << endl;
	}

	for (auto &e : v1) {
		cout << e.name.c_str() << endl;
	}

	cin >> c;
}