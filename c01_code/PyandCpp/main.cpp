#include <Python.h>

int main()
{
	Py_Initialize();    // 初始化python解释器
	PyRun_SimpleString("print('hello python')");
	Py_Finalize();      // 释放资源
	return 0;
}