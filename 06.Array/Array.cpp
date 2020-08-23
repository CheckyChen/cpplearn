#include <iostream>

using namespace std;

int main() {
	int arr[2];
	arr[0] = 1;
	arr[1] = 2;

	int arr2[5] = { 0,1,3,5,6 };

	// 统计数组在内存中的长度
	int totalLen = sizeof(arr2);
	cout << totalLen << endl;

	// 统计数组第一个元素在内存中的长度
	int firstElLen = sizeof(arr2[0]);
	cout << firstElLen << endl;

	// 统计数组的长度
	cout << totalLen / firstElLen << endl;

	// 查看数组在内存中的首地址
	cout << "数组首地址：" << (int)&arr << endl;
	cout << "数组第一个元素地址：" << (int)&arr[0] << endl;
	cout << "数组第二个元素地址：" << (int)&arr[1] << endl;

	int length = totalLen / firstElLen;
	for (size_t i = 0; i < length; i++)
	{
		cout << i << " = " << arr2[i] << endl;
	}

	// 二维数组
	int arrtest[2][3] = {
		{1,2,3},
		{4,5,6}
	};

	return 1;
}