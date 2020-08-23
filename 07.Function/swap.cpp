#include "swap.h"

void swap(int a, int b) {
	cout << "交换前" << a << "," << b << endl;
	int tmp = a;
	a = b;
	b = tmp;
	cout << "交换后" << a << "," << b << endl;
}