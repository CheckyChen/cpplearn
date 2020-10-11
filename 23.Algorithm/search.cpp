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

void all_of_test() {

	vector<int> v = { 3,5,7,11,13,17,19,23 ,14 };
	bool all_odd_flag = all_of(v.begin(), v.end(), [](int i) {return i % 2 != 0; });
	if (all_odd_flag)
	{
		cout << "ȫ������" << endl;
	}
	else
	{
		cout << "���ڲ���Ԫ�ز�������" << endl;
	}
}

void any_of_test() {
	vector<int> v = { 0,1,-1,3,-3,5,-5 };
	vector<int> v2 = { 0,1,1,3,3,5,5 };
	//bool any_negative_flag = any_of(v.begin(), v.end(), [](int val) {return val < 0; });
	bool any_negative_flag = any_of(v2.begin(), v2.end(), [](int val) {return val < 0; });
	if (any_negative_flag)
	{
		cout << "v�д��ڸ���" << endl;
	}
	else
	{
		cout << "v�в����ڸ���" << endl;
	}
}

void myPrint(int i) {
	cout << i << " ";
}

bool myDescSort(int i, int j) {
	return i > j;
}

void binary_search_test() {
	int arr[] = { 1,2,3,4,5,4,3,2,1 };
	vector<int> v(arr, arr + 9);

	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	bool contains4Flag = binary_search(v.begin(), v.end(), 4);
	if (contains4Flag)
	{
		cout << "�����а���4" << endl;
	}
	else
	{
		cout << "�����в�����4" << endl;
	}

	// ��������
	sort(v.begin(), v.end(), myDescSort);
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	bool contains5Flag = binary_search(v.begin(), v.end(), 5);
	if (contains5Flag)
	{
		cout << "�����а���5" << endl;
	}
	else
	{
		cout << "�����в�����5" << endl;
	}
}



int main() {
	find_test1();
	find_test2();
	all_of_test();
	any_of_test();
	binary_search_test();
	return 1;
}