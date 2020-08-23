#include <iostream>

using namespace std;

int main() {
	int a = 10;
	int b = 2;
	cout << "a = " << a << ",b = " << b << endl;
	cout << "a+b=" << a + b << endl;
	cout << "a-b=" << a - b << endl;
	cout << "a*b=" << a * b << endl;
	cout << "a/b=" << a / b << endl;
	cout << "a%b=" << a % b << endl;

	cout << "a++=" << a++ << endl; // 10
	cout << "++b=" << ++b << endl; // 3

	// ++a,a++,--a,a--
	// ++a 前置自增 ，先+1，再执行运算
	// a++ 后置自增 ，先执行运算符，再+1

	int c = 10;
	c += 10;
	cout << "c+=10 = " << c << endl;

	int d = 10;
	d *= 10;
	cout << "d*=10 = " << d << endl;

	int e = 10;
	e /= 10;
	cout << "e/=10 = " << e << endl;

	// 比较运算符 ==,!=,>=,<=,>,<

	// 逻辑运算符 !,!!,&&,||

	return 0;
}