#include <iostream>
using namespace std;

void pointAndArray();
void swapByPoint(int* p1, int* p2);

int main() {

	// 1.定义一个指针

	// 声明一个变量
	int a = 11;

	// 定义一个指针变量
	int* p;
	// 指针变量赋值，指针变量指向变量a的地址
	p = &a;

	cout << "a=" << a << endl;
	cout << "p=" << p << endl;
	cout << "*p=" << *p << endl; // *p 可以取到指针指向内存的数据

	*p = 200; // 修改指针指向内存的数据
	cout << "a=" << a << endl;
	cout << "p=" << p << endl;
	cout << "*p=" << *p << endl; // *p 可以取到指针指向内存的数据

	// 2.空指针
	// 指针变量 p1 指向内存地址编号为 0 的空间
	int* p1 = NULL;

	// 访问空指针报错,"引发了异常: 读取访问权限冲突。"
	// 内存编号为 0~255 为系统占用内存，不允许用户访问
	//cout << "*p1=" << *p1 << endl;

	// 3.野指针，指针变量指向非法的内存空间
	// 在程序中，尽量避免使用野指针
	int* p2 = (int*)0x1100;
	//cout << "*p2" << *p2 << endl; // 访问野指针会报错，引发了异常: 读取访问权限冲突。

	// 4.常量指针，指针常量，const修饰指针和常量

	// ①常量指针,指针指向的地址可以改，指向的值不能改
	int ptest = 333;
	const int* p3 = &ptest;
	p3 = &a;	// 正确
	//*p3 = 200; // 错误

	// ②指针常量，指针指向的值可以改，指向的地址不可以改
	int* const p4 = &ptest;
	*p4 = 500;// 正确
	//p4 = &a; // 错误

	// ③const修饰指针和变量
	const int* const p5 = &ptest;
	//*p5 = 600; // 错误
	//p5 = &a;// 错误

	pointAndArray();

	cout << endl;
	int b = 2;
	int c = 3;
	// 通过这种方式传递时会将 b 和 c 的值进行交换
	swapByPoint(&b,&c);
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	system("pause");
}

// 指针和数组
void pointAndArray() {

	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	// 指向数组的指针
	int* p = arr;

	cout << "访问第一个元素 " << arr[0] << endl;
	cout << "使用指针访问第一个元素 " << *p << endl;

	// 使用指针遍历数组
	cout << "使用数组遍历指针" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << *p << " ";
		p++;
	}
}

// 通过地址传递可以修改形参的值
// 通过地址传递，修改的内存地址里面的值
void swapByPoint(int* p1, int* p2) {
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}