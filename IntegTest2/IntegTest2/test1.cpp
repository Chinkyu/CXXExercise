#if 0

#include <iostream>


void main()
{
	const int theAnswer = 42;

	auto x = theAnswer;
	auto y = &theAnswer;


	std::cout << "auto x=" << typeid(x).name() << "    auto y=" << typeid(y).name();

	getchar();
}

#endif