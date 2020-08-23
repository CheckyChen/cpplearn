#include <iostream>

using namespace std;

int* func() {
	// 利用new在堆区创建一个内存空间存放数据 值为 10
	int* a = new int(10);
	return a;
}

void test1() {

	// 使用 new int[10] 开辟一个数组
	int* arr = new int[10];

	for (size_t i = 0; i < 10; i++)
	{
		// 给数组赋值
		arr[i] = i * 10;
	}

	for (size_t i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	delete[] arr;
}

int main() {

	int* p = func();
	cout << *p << endl;
	cout << *p << endl;

	// 利用delete释放堆区的数据
	delete p;

	// cout << *p << endl;// 引发了异常: 读取访问权限冲突。


	test1();

	return 1;
}