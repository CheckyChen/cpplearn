#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void rf_test1() {
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (ifs.is_open())
	{
		// 1. ��һ�ַ�ʽ
		/*char buffer[1024] = { 0 };
		while (ifs >> buffer)
		{
			cout << buffer << endl;
		}*/

		// 2. �ڶ��ַ�ʽ
		/*char buffer2[1024] = { 0 };
		while (ifs.getline(buffer2, sizeof(buffer2)))
		{
			cout << buffer2 << endl;
		}*/

		// 3. �����ַ�ʽ
		/*string buffer3;
		while (getline(ifs, buffer3))
		{
			cout << buffer3 << endl;
		}*/

		// 4. �����ַ�ʽ
		char c;
		while ((c = ifs.get())!=EOF) // EOF end of file �ļ���ĩβ
		{
			cout << c;
		}
	}
	else
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
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