#include <utility>
#include <iostream>
#include <format>

using namespace std;

int main()
{
	pair<double, int> myPair{ 1.23, 5 };
	// pair myPair { 1.23, 5 };  // Using CTAD
	cout << format("{} {}\n", myPair.first, myPair.second);

	pair<string, int> myPair1{"hello world", 1024};
	cout << format("{} {}", myPair1.first, myPair1.second);
}