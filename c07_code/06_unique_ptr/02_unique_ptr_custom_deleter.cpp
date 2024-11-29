#include <memory>
#include <iostream>
#include <typeinfo>
using namespace std;

int* my_alloc(int value)
{
	return new int{ value };
}

void my_free(int* p)
{
	std::cout << "delete memory" << std::endl;
	delete p;
}

int main()
{
	auto& nInfo = typeid(decltype(&my_free));
	cout << nInfo.name() << '\n';
	unique_ptr<int, decltype(&my_free)> myIntSmartPtr{ my_alloc(42), my_free };
}