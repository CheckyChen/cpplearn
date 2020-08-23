#include <iostream>
#include <string>
#include "swap.h"

using namespace std;


// 函数的声明,声明可以是多次的
int max(int a, int b);

void func01(int a, int b = 10, int c = 20);

int add(int a, int b) {
	return a + b;
}


// 默认参数
// 注意：函数的声明和实现中，只能其中一个有默认参数
void addMulti(int a, int b = 10, int c = 30) {
	int ret = a + b + c;
	cout << "a + b + c = " << ret << endl;
}

int main() {

	int sum = add(1, 2);
	cout << sum << endl;

	int a = 10;
	int b = 20;

	cout << max(a, b) << endl;

	int c = 111;
	int d = 222;
	swap(c, d);

	addMulti(100);

	return 0;
}

// 函数的定义
int max(int a, int b) {
	return a > b ? a : b;
}

// 函数分文件编写
// 1 创建.h后缀名的头文件
// 2 创建.cpp后缀名的源文件
// 3 在头文件中书写函数的声明
// 4 在源文件中写函数的定义


// 函数声明中已经有默认参数，实现中不能有默认参数，运行时会报错
void func01(int a, int b, int c) {
	cout << a + b + c << endl;
}


// 函数的占位参数
void func02(int a, int) {
	cout << "this is func02!" << endl;
}
// 调用时必须传一个对应的类型数据 eg: func02(1,2);

void func03(int a, int = 20) {
	cout << "this is func03!" << endl;
}
// 调用时占位参数可以不传值 eg:func03(1);

// 函数的重载
// 1、函数名相同，必须在同一个作用域
// 2、函数参数不同，或者类型不同，或者顺序不同
// 3、函数返回值不可以作为重载的条件
void function(){}

void function(int a) {}

void function(int a,int b) {}

void function(int a, string b) {}

void functest(int &a) {} // 调用方式 int a = 10;functest(a);

void functest(const int& a) {} // 调用方式 functest(10);
