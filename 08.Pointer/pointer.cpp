#include <iostream>
using namespace std;

void pointAndArray();
void swapByPoint(int* p1, int* p2);

int main() {

	// 1.����һ��ָ��

	// ����һ������
	int a = 11;

	// ����һ��ָ�����
	int* p;
	// ָ�������ֵ��ָ�����ָ�����a�ĵ�ַ
	p = &a;

	cout << "a=" << a << endl;
	cout << "p=" << p << endl;
	cout << "*p=" << *p << endl; // *p ����ȡ��ָ��ָ���ڴ������

	*p = 200; // �޸�ָ��ָ���ڴ������
	cout << "a=" << a << endl;
	cout << "p=" << p << endl;
	cout << "*p=" << *p << endl; // *p ����ȡ��ָ��ָ���ڴ������

	// 2.��ָ��
	// ָ����� p1 ָ���ڴ��ַ���Ϊ 0 �Ŀռ�
	int* p1 = NULL;

	// ���ʿ�ָ�뱨��,"�������쳣: ��ȡ����Ȩ�޳�ͻ��"
	// �ڴ���Ϊ 0~255 Ϊϵͳռ���ڴ棬�������û�����
	//cout << "*p1=" << *p1 << endl;

	// 3.Ұָ�룬ָ�����ָ��Ƿ����ڴ�ռ�
	// �ڳ����У���������ʹ��Ұָ��
	int* p2 = (int*)0x1100;
	//cout << "*p2" << *p2 << endl; // ����Ұָ��ᱨ���������쳣: ��ȡ����Ȩ�޳�ͻ��

	// 4.����ָ�룬ָ�볣����const����ָ��ͳ���

	// �ٳ���ָ��,ָ��ָ��ĵ�ַ���Ըģ�ָ���ֵ���ܸ�
	int ptest = 333;
	const int* p3 = &ptest;
	p3 = &a;	// ��ȷ
	//*p3 = 200; // ����

	// ��ָ�볣����ָ��ָ���ֵ���Ըģ�ָ��ĵ�ַ�����Ը�
	int* const p4 = &ptest;
	*p4 = 500;// ��ȷ
	//p4 = &a; // ����

	// ��const����ָ��ͱ���
	const int* const p5 = &ptest;
	//*p5 = 600; // ����
	//p5 = &a;// ����

	pointAndArray();

	cout << endl;
	int b = 2;
	int c = 3;
	// ͨ�����ַ�ʽ����ʱ�Ὣ b �� c ��ֵ���н���
	swapByPoint(&b,&c);
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	system("pause");
}

// ָ�������
void pointAndArray() {

	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	// ָ�������ָ��
	int* p = arr;

	cout << "���ʵ�һ��Ԫ�� " << arr[0] << endl;
	cout << "ʹ��ָ����ʵ�һ��Ԫ�� " << *p << endl;

	// ʹ��ָ���������
	cout << "ʹ���������ָ��" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << *p << " ";
		p++;
	}
}

// ͨ����ַ���ݿ����޸��βε�ֵ
// ͨ����ַ���ݣ��޸ĵ��ڴ��ַ�����ֵ
void swapByPoint(int* p1, int* p2) {
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}