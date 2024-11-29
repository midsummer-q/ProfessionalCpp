#include <array>
#include <utility>
#include <iostream>
#include <format>
#include <map>
using namespace std;

int main()
{
	{
		// Structured bindings with std::array.
		std::array values{ 11, 22, 33 };
		auto [x, y, z] { values };
		std::cout << format("{}|{}|{}\n", x, y, z);
		x = 33;
		std::cout << format("{}|{}|{}\n", x, y, z);
	}

	{
		// Structured bindings with struct.
		struct Point {
			double m_x, m_y, m_z;
		};
		Point point{};
		point.m_x = 1.0; point.m_y = 2.0; point.m_z = 3.0;
		auto [x, y, z] { point };
	}

	{
		// Structured bindings with std::pair.
		pair myPair{ "hello", 5 };
		auto [theString, theInt] { myPair };  // Decompose using structured bindings
		cout << format("theString: {}", theString) << endl;
		cout << format("theInt: {}", theInt) << endl;
	}
	{
		std::map<int, std::string> myMap = { {1, "one"}, {2, "two"}, {3, "three"} };
		for (const auto& [key, value] : myMap) {
			//std::cout << "Key: " << key << ", Value: " << value << std::endl;
			cout << format("Key: {}, Value: {}\n", key, value);
		}
	}
}