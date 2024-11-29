#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;

const string message{ "Test" };
const string& foo() {
	return message;
}

int main()
{
	auto x{ 123 };                // x is of type int

	auto f1{ foo() };             // f1 is of type string
	//auto去除引用和const限定符，若不想去掉可使用auto&或者const auto&
	const auto& f2{ foo() };      // f2 is of type const string&
	auto& f3{ foo() };			  // f3 is of type const string&

	string str{ "C++" };
	auto result{ as_const(str) }; // result is of type string!

	int i{ 123 };
	//auto p{ &i };               // p is of type int*
	auto* p{ &i };                // p is of type int*

	const auto p1{ &i };          // p1 is of type int* const
	auto const p2{ &i };          // p2 is of type int* const
	const auto* p3{ &i };         // p3 is of type const int*
	auto* const p4{ &i };         // p4 is of type int* const
	const auto* const p5{ &i };   // p5 is of type const int* const

	//decltype未去除引用和const限定符
	decltype(foo()) f4{foo()};

	{
		int i{ 100 };
		auto& i2 = i;
		std::cout << typeid(i2).name() << '\n';
	}
}