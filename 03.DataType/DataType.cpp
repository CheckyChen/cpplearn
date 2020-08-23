#include <iostream>
#include <string>

using namespace std;


//存在的意义：给变量分配合适的内存空间

int main() {

	// 1.整型
	cout << "=======整型=========" << endl;
	short s = 1;// 短整型 2个字节
	int i = 2;	// 整型   4个字节
	long l = 3; // 长整型 8个字节
	long long ll = 4; // 长长整型 8个字节

	// 所占用的内存空间不一样

	cout << "s " << sizeof(s) << endl;
	cout << "i " << sizeof(i) << endl;
	cout << "l " << sizeof(l) << endl;
	cout << "ll " << sizeof(ll) << endl;


	// 2.浮点类型
	cout << "=======浮点型=========" << endl;
	float f = 1.22f; // 单精度 占4个
	double d = 3.1415926; // 双精度 占8个字节

	cout << "f = " << f << endl;
	cout << "d = " << d << endl;

	// 科学计数法
	float f2 = 3e2; // 3*10^2
	cout << "f2 = " << f2 << endl;

	float f3 = 3e-2; // 3*0.1^2
	cout << "f3 = " << f3 << endl;

	// 3.字符型
	cout << "=======字符型=========" << endl;
	char c = 'a'; // 占1字节
	cout << "c = " << c << endl;
	cout << sizeof(char) << endl;

	// 字符型对应的ASCII码
	cout << "a=>accii码" << (int)'a' << endl;

	// 4.字符串型
	cout << "=======字符串型=========" << endl;
	char str[] = "hello";

	cout << "str = " << str <<endl;
	cout << sizeof(str) << endl;

	string str2 = "字符串";
	cout << "str2 = " << str2 << endl;
	cout << sizeof(str2) << endl;

	// 5.布尔类型 bool 占用1个字节 1 代表真，0 代表假
	cout << "=======布尔型=========" << endl;
	bool flag = true; // 输出1
	bool flag2 = false; // 输出0
	cout << "flag = " << flag << endl;
	cout << "flag2 = " << flag2 << endl;

	// 从键盘接收输入
	int inputInt = 0;
	cout << "请输入：";
	cin >> inputInt;
	cout << "输入的值为：" << inputInt << endl;

	return 1;
}