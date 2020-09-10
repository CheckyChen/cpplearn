#include<iostream>

using namespace std;

template<typename T>
void mySwap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

void test1() {
	int a = 1;
	int b = 2;
	mySwap(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

int main() {
	test1();
	return 1;
}