#include <iostream>
#include <string>

using namespace std;


//���ڵ����壺������������ʵ��ڴ�ռ�

int main() {

	// 1.����
	cout << "=======����=========" << endl;
	short s = 1;// ������ 2���ֽ�
	int i = 2;	// ����   4���ֽ�
	long l = 3; // ������ 8���ֽ�
	long long ll = 4; // �������� 8���ֽ�

	// ��ռ�õ��ڴ�ռ䲻һ��

	cout << "s " << sizeof(s) << endl;
	cout << "i " << sizeof(i) << endl;
	cout << "l " << sizeof(l) << endl;
	cout << "ll " << sizeof(ll) << endl;


	// 2.��������
	cout << "=======������=========" << endl;
	float f = 1.22f; // ������ ռ4��
	double d = 3.1415926; // ˫���� ռ8���ֽ�

	cout << "f = " << f << endl;
	cout << "d = " << d << endl;

	// ��ѧ������
	float f2 = 3e2; // 3*10^2
	cout << "f2 = " << f2 << endl;

	float f3 = 3e-2; // 3*0.1^2
	cout << "f3 = " << f3 << endl;

	// 3.�ַ���
	cout << "=======�ַ���=========" << endl;
	char c = 'a'; // ռ1�ֽ�
	cout << "c = " << c << endl;
	cout << sizeof(char) << endl;

	// �ַ��Ͷ�Ӧ��ASCII��
	cout << "a=>accii��" << (int)'a' << endl;

	// 4.�ַ�����
	cout << "=======�ַ�����=========" << endl;
	char str[] = "hello";

	cout << "str = " << str <<endl;
	cout << sizeof(str) << endl;

	string str2 = "�ַ���";
	cout << "str2 = " << str2 << endl;
	cout << sizeof(str2) << endl;

	// 5.�������� bool ռ��1���ֽ� 1 �����棬0 �����
	cout << "=======������=========" << endl;
	bool flag = true; // ���1
	bool flag2 = false; // ���0
	cout << "flag = " << flag << endl;
	cout << "flag2 = " << flag2 << endl;

	// �Ӽ��̽�������
	int inputInt = 0;
	cout << "�����룺";
	cin >> inputInt;
	cout << "�����ֵΪ��" << inputInt << endl;

	return 1;
}