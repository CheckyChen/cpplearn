#include <iostream>

using namespace std;

int main() {
	int arr[2];
	arr[0] = 1;
	arr[1] = 2;

	int arr2[5] = { 0,1,3,5,6 };

	// ͳ���������ڴ��еĳ���
	int totalLen = sizeof(arr2);
	cout << totalLen << endl;

	// ͳ�������һ��Ԫ�����ڴ��еĳ���
	int firstElLen = sizeof(arr2[0]);
	cout << firstElLen << endl;

	// ͳ������ĳ���
	cout << totalLen / firstElLen << endl;

	// �鿴�������ڴ��е��׵�ַ
	cout << "�����׵�ַ��" << (int)&arr << endl;
	cout << "�����һ��Ԫ�ص�ַ��" << (int)&arr[0] << endl;
	cout << "����ڶ���Ԫ�ص�ַ��" << (int)&arr[1] << endl;

	int length = totalLen / firstElLen;
	for (size_t i = 0; i < length; i++)
	{
		cout << i << " = " << arr2[i] << endl;
	}

	// ��ά����
	int arrtest[2][3] = {
		{1,2,3},
		{4,5,6}
	};

	return 1;
}