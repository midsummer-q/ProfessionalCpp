#include <Python.h>

int main()
{
	Py_Initialize();    // ��ʼ��python������
	PyRun_SimpleString("print('hello python')");
	Py_Finalize();      // �ͷ���Դ
	return 0;
}