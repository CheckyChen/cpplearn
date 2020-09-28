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

	// 自定义数据类型需要 重载 == 操作符才能使用 find 算法
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
		cout << "没有找到" << endl;
	}
}

int main() {
	find_test1();
	find_test2();
	return 1;
}