#include <iostream>

using namespace std;

int* func() {
	// ����new�ڶ�������һ���ڴ�ռ������� ֵΪ 10
	int* a = new int(10);
	return a;
}

void test1() {

	// ʹ�� new int[10] ����һ������
	int* arr = new int[10];

	for (size_t i = 0; i < 10; i++)
	{
		// �����鸳ֵ
		arr[i] = i * 10;
	}

	for (size_t i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	delete[] arr;
}

int main() {

	int* p = func();
	cout << *p << endl;
	cout << *p << endl;

	// ����delete�ͷŶ���������
	delete p;

	// cout << *p << endl;// �������쳣: ��ȡ����Ȩ�޳�ͻ��


	test1();

	return 1;
}