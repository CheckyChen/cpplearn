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
	// ++a ǰ������ ����+1����ִ������
	// a++ �������� ����ִ�����������+1

	int c = 10;
	c += 10;
	cout << "c+=10 = " << c << endl;

	int d = 10;
	d *= 10;
	cout << "d*=10 = " << d << endl;

	int e = 10;
	e /= 10;
	cout << "e/=10 = " << e << endl;

	// �Ƚ������ ==,!=,>=,<=,>,<

	// �߼������ !,!!,&&,||

	return 0;
}