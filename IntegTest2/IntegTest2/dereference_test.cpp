#include <iostream>
#include <string>


void t1(int& rp) {

	auto drp = rp;


	std::cout << rp << "\n";
//	std::cout << *drp;
}



void main() {

	int p = 1;
	int q = 2;

	t1(p);

	std::string s{ "string1" };

	std::string s2(std::move(s));

	std::cout << "s:" << s << " S2:" << s2.c_str();


	getchar();
}
