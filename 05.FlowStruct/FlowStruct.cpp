#include <iostream>

using namespace std;

int main() {

	// if 逻辑处理
	if (true)
	{

	}
	else if (true)
	{

	}
	else
	{

	}

	// 三目运算符 ?:
	int a = 100 == 20 ? 20 : 300;


	// switch

	int value = 0;
	switch (value)
	{
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}


	// 循环，跳过循环 continue;退出循环 break;
	while (false)
	{

	}

	do {

	} while (false);

	for (size_t i = 0; i < 100; i++)
	{
		cout << i << endl;
	}

	// goto 跳转，尽量不要使用，影响可读性

	int input = 0;

	cin >> input;
	if (input == 100)
	{
		goto LABEL100;
	}

	if (input == 200)
	{
		goto LABEL200;
	}

LABEL100:
	cout << "label100" << endl;

LABEL200:
	cout << "label200" << endl;

	return 0;
}