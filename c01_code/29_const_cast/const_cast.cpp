#include <iostream>

using namespace std;
class CCTest {
public:
	void setNumber(int);
	void printNumber1() const;
	void printNumber2();
private:
	int number;
};

void CCTest::setNumber(int num) {
	number = num;
}

void CCTest::printNumber1() const {  // const func can only operate const variable, by Tom Xue
	cout << "\nBefore: " << number << endl;
	const_cast<CCTest*>(this)->number--;    // but it can change this situation, by Tom Xue
	//(this)->number--;
	cout << "\nAfter: " << number << endl;
}

void CCTest::printNumber2() {
	cout << "\nBefore: " << number << endl;
	const_cast<CCTest*>(this)->number--;
	//(this)->number--;
	cout << "\nAfter: " << number << endl;
}
//--------------------------------------------------
void ThirdPartyLibraryMethod(char* str) {}

void f(const char* str)
{
	ThirdPartyLibraryMethod(const_cast<char*>(str));
	//ThirdPartyLibraryMethod(str);
}

int main()
{
	f("Hello World");

	CCTest X{};
	X.setNumber(8);
	X.printNumber1();

	{
		const int ci = 10;
		auto nonConstPtr1 = const_cast<int*>(&ci);
		auto nonConstPtr2 = &ci;
		*nonConstPtr1 = 20;
		cout << nonConstPtr1 << '\n';
		cout << &ci << '\n';
		cout << ci << '\n';

		int i{ 5 };
		int* p{ &i };
		*p = 10;
		cout << i << '\n';
	}
}