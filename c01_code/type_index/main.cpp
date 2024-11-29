#include<iostream>
#include<boost/type_index.hpp>
#include <string>
using boost::typeindex::type_id_with_cvr;
using namespace std;

const string message{ "Test" };
const string& foo() {
	return message;
}

int main()
{
	auto x{ 123 };                // x is of type int

	auto f1{ foo() };             // f1 is of type string
	cout << type_id_with_cvr<decltype(f1)>().pretty_name() << '\n';
	//auto去除引用和const限定符，若不想去掉可使用auto&或者const auto&
	const auto& f2{ foo() };      // f2 is of type const string&
	cout << type_id_with_cvr<decltype(f2)>().pretty_name() << '\n';
	auto& f3{ foo() };			  // f3 is of type const string&
	cout << type_id_with_cvr<decltype(f3)>().pretty_name() << '\n';
	string str{ "C++" };
	auto result{ as_const(str) }; // result is of type string!
	cout << type_id_with_cvr<decltype(result)>().pretty_name() << '\n';
	int i{ 123 };
	//auto p{ &i };               // p is of type int*
	auto* p{ &i };                // p is of type int*
	cout << type_id_with_cvr<decltype(p)>().pretty_name() << '\n';
	const auto p1{ &i };          // p1 is of type int* const
	auto const p2{ &i };          // p2 is of type int* const
	const auto* p3{ &i };         // p3 is of type const int*
	auto* const p4{ &i };         // p4 is of type int* const
	const auto* const p5{ &i };   // p5 is of type const int* const

	//decltype未去除引用和const限定符
	decltype(foo()) f4{foo()};
	cout << type_id_with_cvr<decltype(foo)>().pretty_name() << '\n';
}