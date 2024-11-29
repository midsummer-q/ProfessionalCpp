#include<vld.h>
class Simple
{
public:
	Simple() {
		m_intPtr = new int{};
	}
	~Simple() {
		delete m_intPtr;
	}

	void setValue(int value) {
		*m_intPtr = value;
	}

private:
	int* m_intPtr;
};

void doSomething(Simple*& outSimplePtr)
{
	delete outSimplePtr;
	outSimplePtr = new Simple{}; // BUG! Doesn't delete the original.
}

int main()
{
	Simple* simplePtr{ new Simple{} }; // Allocate a Simple object.

	doSomething(simplePtr);

	delete simplePtr; // Only cleans up the second object.
	//int* p{ new int[4] };
}