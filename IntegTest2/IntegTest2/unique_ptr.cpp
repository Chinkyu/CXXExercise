#if 0
// unique ptr testing... 
#include <iostream>
#include <utility>
#include <memory>

class father {
public:
	std::unique_ptr<int> uptr1;

	father() {
		uptr1 = std::make_unique<int>();
	};

	void process() {
		std::cout << *uptr1 << std::endl;
	}

};

class son : public father {

};

int main()
{

	father fd;

	fd.process();

	getchar();
}

#endif