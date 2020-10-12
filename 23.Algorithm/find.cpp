#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


void find_test1() {

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	vector<int>::iterator it = find(v.begin(), v.end(), 4);
	cout << *it << endl;
}

class Person {
public:
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}

	int m_Age;
	string m_Name;

	bool operator==(const Person& p1)
	{
		return p1.m_Age == m_Age && p1.m_Name == m_Name;
	}
};

void find_test2() {

	// �Զ�������������Ҫ ���� == ����������ʹ�� find �㷨
	vector<Person> v;
	Person p1("a", 1);
	Person p2("b", 2);
	Person p3("c", 3);
	Person p4("d", 4);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator it = find(v.begin(), v.end(), p2);

	if (it != v.end())
	{
		cout << "name: " << it->m_Name << " age:" << it->m_Age << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
}


bool myfunction(int i, int j) {
	return (i == j);
}

void find_end_test() {
	vector<int>v = { 1,2,3,4,5,1,2,3,4,5 };

	int needle1[] = { 1,2,3 };
	vector<int>::iterator it = find_end(v.begin(), v.end(), needle1, needle1 + 3);
	if (it != v.end())
	{
		cout << "needle1 ����ҵ���λ��Ϊ��" << (it - v.begin()) << endl;
		// needle1 ����ҵ���λ��Ϊ��5
	}

	int needle2[] = { 4,5,1 };
	vector<int>::iterator it2 = find_end(v.begin(), v.end(), needle2, needle2 + 3, myfunction);
	if (it2 != v.end())
	{
		cout << "needle2 ����ҵ���λ��Ϊ��" << (it2 - v.begin()) << endl;
		// needle2 ����ҵ���λ��Ϊ��3
	}

	int needle3[] = { 5,1,2 };
	it2 = find_end(v.begin(), v.end(), needle3, needle3 + 3);
	if (it2 != v.begin()) {
		cout << "needle3 ����ҵ���λ��Ϊ��" << (it2 - v.begin()) << endl;
		// needle3 ����ҵ���λ��Ϊ��4
	}

}


bool ignore_case_comp(char c1, char c2) {
	return (tolower(c1) == tolower(c2));
}

void find_first_of_test() {
	vector<char>v = {'a','b','c','A','B','C'};
	char needle1[] = { 'A','B','C' };

	vector<char>::iterator it = find_first_of(v.begin(),v.end(),needle1,needle1+3);
	if (it!=v.begin())
	{
		cout << "needle1 ��һ��ƥ�䵽�ģ�" << *it << endl;
		//needle1 ��һ��ƥ�䵽�ģ�A
	}

	vector<char>::iterator it2 = find_first_of(v.begin(), v.end(), needle1, needle1 + 3, ignore_case_comp);
	if (it2 != v.begin())
	{
		cout << "needle1 ��һ�����Դ�Сдƥ�䵽�ģ�" << *it2 << endl;
		//needle1 ��һ��ƥ�䵽�ģ�a
	}
}

int main() {
	//find_test1();
	//find_test2();
	//find_end_test();
	find_first_of_test();
	return 1;
}