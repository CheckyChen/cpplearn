#include <iostream>

using namespace std;

// 引用作为函数参数传递
void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int& test() {
	int a = 20;
	return a;
}

int& test1() {
	static int a = 30; // static 数据存放在全局区，由系统释放
	return a;
}

void showValue(const int& ref) {

	//ref = 200; // 加入const后，ref的值就不能进行修改，防止误操作实参的值
	cout << "ref = " << ref << endl;
}

int main() {

	int tmp = 100;
	int& tmp_t = tmp;
	cout << "tmp = " << tmp << endl;
	cout << "tmp_t = " << tmp_t << endl;

	tmp_t = 200;
	cout << "tmp = " << tmp << endl;
	cout << "tmp_t = " << tmp_t << endl;

	int a = 10;
	int b = 20;

	swap(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	int& val = test();
	cout << "val = " << val << endl; // 第一次的值是正确的，因为编译器会保留下
	cout << "val = " << val << endl; // 第二次的值就不对了

	int& val1 = test1(); // 以下输出的值都为 30 
	cout << "val1 = " << val1 << endl;
	cout << "val1 = " << val1 << endl;
	cout << "val1 = " << val1 << endl;
	cout << "val1 = " << val1 << endl;

	// 作为左值,
	test1() = 21000; // output 21000
	cout << "val1 = " << val1 << endl;
	cout << "val1 = " << val1 << endl;
	cout << "val1 = " << val1 << endl;
	cout << "val1 = " << val1 << endl;


	// 常量引用

	// int& ref = 10;//这个会报错，引用本身需要一个合法的内存空间

	// 加入const就可以了，编译器优化，int tmp = 10;const int& ref = tmp;
	const int& ref = 10;

	// ref = 100;// 加入const后不可以修改变量

	return 1;
}

// 引用的本质：在C++内部实现是一个指针常量
void func(int& ref) {
	ref = 100; // ref是引用，转化为 *ref = 100 
}

void func1() {
	int a = 10;

	// 自动转化为 int* const ref = &a; 指针常量是指指针指向不可改变，也说明为什么引用不可更改
	int& ref = a;

	ref = 20;// 内部发现ref是引用，自动帮我们转换为：*ref = 20;

	cout << "a: " << a << endl;
	cout << "ref: " << ref << endl;

	func(a);
}