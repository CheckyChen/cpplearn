#include <iostream>

using namespace std;

// ������Ϊ������������
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
	static int a = 30; // static ���ݴ����ȫ��������ϵͳ�ͷ�
	return a;
}

void showValue(const int& ref) {

	//ref = 200; // ����const��ref��ֵ�Ͳ��ܽ����޸ģ���ֹ�����ʵ�ε�ֵ
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
	cout << "val = " << val << endl; // ��һ�ε�ֵ����ȷ�ģ���Ϊ�������ᱣ����
	cout << "val = " << val << endl; // �ڶ��ε�ֵ�Ͳ�����

	int& val1 = test1(); // ���������ֵ��Ϊ 30 
	cout << "val1 = " << val1 << endl;
	cout << "val1 = " << val1 << endl;
	cout << "val1 = " << val1 << endl;
	cout << "val1 = " << val1 << endl;

	// ��Ϊ��ֵ,
	test1() = 21000; // output 21000
	cout << "val1 = " << val1 << endl;
	cout << "val1 = " << val1 << endl;
	cout << "val1 = " << val1 << endl;
	cout << "val1 = " << val1 << endl;


	// ��������

	// int& ref = 10;//����ᱨ�����ñ�����Ҫһ���Ϸ����ڴ�ռ�

	// ����const�Ϳ����ˣ��������Ż���int tmp = 10;const int& ref = tmp;
	const int& ref = 10;

	// ref = 100;// ����const�󲻿����޸ı���

	return 1;
}

// ���õı��ʣ���C++�ڲ�ʵ����һ��ָ�볣��
void func(int& ref) {
	ref = 100; // ref�����ã�ת��Ϊ *ref = 100 
}

void func1() {
	int a = 10;

	// �Զ�ת��Ϊ int* const ref = &a; ָ�볣����ָָ��ָ�򲻿ɸı䣬Ҳ˵��Ϊʲô���ò��ɸ���
	int& ref = a;

	ref = 20;// �ڲ�����ref�����ã��Զ�������ת��Ϊ��*ref = 20;

	cout << "a: " << a << endl;
	cout << "ref: " << ref << endl;

	func(a);
}