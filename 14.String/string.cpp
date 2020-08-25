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

	s1.append(" ��������", 0, 5);    // �Ұ��˶��� ���� ���� ע�⣺һ������ռ�����ַ�
	cout << "s1 = " << s1 << endl;

	string s2 = "������";
	s2.append("aabbcc", 1, 3);
	cout << "s2 = " << s2 << endl; // ������abb
}

// ����
void test04() {
	string s1 = "abcdefde";
	int pos = s1.find("de");// �������Ҳ��ҵ�һ�����ֵ�λ�ã�������� -1 ��ʾδ��ѯ��
	if (pos == -1)
	{
		cout << "δ��ѯ��de�ַ���" << endl;
	}
	else {
		cout << "pos = " << pos << endl; // 3 
	}

	pos = s1.rfind("de"); // ����������ҵ�һ��de���ֵ�λ��
	cout << "pos = " << pos << endl; // 6	
}

// �ַ����ıȽ�
void test05() {
	string s1 = "hello";
	string s2 = "hello";

	int compare = s1.compare(s2);

	if (compare == 0)
	{
		cout << "s1 == s2" << endl;
	}
	else if (compare > 0) {
		cout << "s1 > s2" << endl;
	}
	else {
		cout << "s1 < s2" << endl;
	}
}

// �ַ�����ȡ��
void test06() {
	string s1 = "checky";

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		cout << s1.at(i) << " ";
	}
	cout << endl;

	s1[0] = 'f';
	cout << "s1 = " << s1 << endl; // fhecky
	s1.at(1) = 'r';
	cout << "s1 = " << s1 << endl; // frecky
}

// �����ɾ��
void test07() {
	string s1 = "checky";

	s1.insert(1,"chan");
	cout << "s1 = " << s1 << endl; // cchanecky

	s1.erase(1,4);
	cout << "s1 = " << s1 << endl; // checky
}

// �Ӵ�
void test08() {
	string s1 = "abcdefg";
	string sub = s1.substr(1,3);
	cout << "sub = " << sub << endl; // bcd
}

int main() {
	test01();
	test02();
	test03();
	test04();

	test06();
	test07();
	test08();
	return 1;
}