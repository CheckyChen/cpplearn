#include <iostream>
#include <string>
#include "swap.h"

using namespace std;


// ����������,���������Ƕ�ε�
int max(int a, int b);

void func01(int a, int b = 10, int c = 20);

int add(int a, int b) {
	return a + b;
}


// Ĭ�ϲ���
// ע�⣺������������ʵ���У�ֻ������һ����Ĭ�ϲ���
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

// �����Ķ���
int max(int a, int b) {
	return a > b ? a : b;
}

// �������ļ���д
// 1 ����.h��׺����ͷ�ļ�
// 2 ����.cpp��׺����Դ�ļ�
// 3 ��ͷ�ļ�����д����������
// 4 ��Դ�ļ���д�����Ķ���


// �����������Ѿ���Ĭ�ϲ�����ʵ���в�����Ĭ�ϲ���������ʱ�ᱨ��
void func01(int a, int b, int c) {
	cout << a + b + c << endl;
}


// ������ռλ����
void func02(int a, int) {
	cout << "this is func02!" << endl;
}
// ����ʱ���봫һ����Ӧ���������� eg: func02(1,2);

void func03(int a, int = 20) {
	cout << "this is func03!" << endl;
}
// ����ʱռλ�������Բ���ֵ eg:func03(1);

// ����������
// 1����������ͬ��������ͬһ��������
// 2������������ͬ���������Ͳ�ͬ������˳��ͬ
// 3����������ֵ��������Ϊ���ص�����
void function(){}

void function(int a) {}

void function(int a,int b) {}

void function(int a, string b) {}

void functest(int &a) {} // ���÷�ʽ int a = 10;functest(a);

void functest(const int& a) {} // ���÷�ʽ functest(10);
