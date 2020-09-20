#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person {

public:

	char m_name[64]; // 用 string 类型的话  会报异常 -》 引发了异常: 读取访问权限冲突。
	int m_age;
};

void write_binary_file() {

	ofstream ofs("person.txt", ios::out | ios::binary);
	Person person = { "checky",22 };
	ofs.write((const char*)&person, sizeof(Person));
	ofs.close();
	cout << "写入成功" << endl;
}

void read_binary_file() {
	ifstream ifs;

	ifs.open("person.txt", ios::in | ios::binary);

	if (ifs.is_open())
	{
		Person p;
		ifs.read((char*)&p, sizeof(p));
		cout << "name = " << p.m_name << " age = " << p.m_age << endl;
		ifs.close();
	}
	else
	{
		cout << "打开文件失败" << endl;
	}
}


int main() {

	//write_binary_file();

	read_binary_file();
	return 1;
}