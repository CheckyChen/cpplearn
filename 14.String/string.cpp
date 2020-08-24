#include <iostream>
#include <string>

using namespace std;

/*
string ���캯����
��string()					// Ĭ�Ϲ��캯��
��string(const char* s)		// ʹ���ַ��� s ��ʼ��
��string(const string& str)	// ʹ��һ��string�����ʼ������һ��string����
��string(int n,char c)		// ʹ��n���ַ�c��ʼ��
*/

// ��ʼ��
void test01() {
	string s1;

	const char* s2 = "hello world!";
	string s3(s2);
	cout << "s3 = " << s3 << endl;

	string s4(s3);
	cout << "s4 = " << s4 << endl;

	string s5(5, 'h');
	cout << "s5 = " << s5 << endl;
}

// ��ֵ����
void test02() {

	string s0;
	s0 = "checky chan";
	cout << "s0 = " << s0 << endl; // checky chan

	s0 = 'a';
	cout << "s0 = " << s0 << endl; // aa

	string s1;
	s1.assign("hello C++", 5); // ���ַ�����ǰn���ַ���ֵ����ǰ�ַ��� 
	cout << "s1 = " << s1 << endl; // s1 = hello

	string s2;
	s2.assign(5, 'a');
	cout << "s2 = " << s2 << endl; // aaaaa

	string s3;
	s3.assign(s2);
	cout << "s3 = " << s3 << endl; // aaaa

	string s4;
	s4.assign("checky");
	cout << "s4 = " << s4 << endl; // checky
}

// ׷��
void test03() {
	string s1 = "��";
	s1 += "���˶�";
	cout << "s1 = " << s1 << endl; // �Ұ��˶�
	s1 += ':';
	cout << "s1 = " << s1 << endl; // �Ұ��˶�:

	s1.append(" ����");
	cout << "s1 = " << s1 << endl; // �Ұ��˶�: ����

	s1.append(" ��������",0,5);    // �Ұ��˶��� ���� ���� ע�⣺һ������ռ�����ַ�
	cout << "s1 = " << s1 << endl;

	string s2 = "������";
	s2.append("aabbcc",1,3); 
	cout << "s2 = " << s2 << endl; // ������abb

}

int main() {
	test01();
	test02();
	test03();
	return 1;
}