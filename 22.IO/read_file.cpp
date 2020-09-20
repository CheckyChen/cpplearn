#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void rf_test1() {
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (ifs.is_open())
	{
		// 1. 第一种方式
		/*char buffer[1024] = { 0 };
		while (ifs >> buffer)
		{
			cout << buffer << endl;
		}*/

		// 2. 第二种方式
		/*char buffer2[1024] = { 0 };
		while (ifs.getline(buffer2, sizeof(buffer2)))
		{
			cout << buffer2 << endl;
		}*/

		// 3. 第三种方式
		/*string buffer3;
		while (getline(ifs, buffer3))
		{
			cout << buffer3 << endl;
		}*/

		// 4. 第四种方式
		char c;
		while ((c = ifs.get())!=EOF) // EOF end of file 文件的末尾
		{
			cout << c;
		}
	}
	else
	{
		cout << "文件打开失败！" << endl;
	}
	ifs.close();
}
//
//int main() {
//
//	rf_test1();
//
//	return 1;
//}