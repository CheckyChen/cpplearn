#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person {

public:

	char m_name[64]; // �� string ���͵Ļ�  �ᱨ�쳣 -�� �������쳣: ��ȡ����Ȩ�޳�ͻ��
	int m_age;
};

void write_binary_file() {

	ofstream ofs("person.txt", ios::out | ios::binary);
	Person person = { "checky",22 };
	ofs.write((const char*)&person, sizeof(Person));
	ofs.close();
	cout << "д��ɹ�" << endl;
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
		cout << "���ļ�ʧ��" << endl;
	}
}


int main() {

	//write_binary_file();

	read_binary_file();
	return 1;
}