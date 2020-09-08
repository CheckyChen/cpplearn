#include <iostream>
#include <set>
#include <string>

using namespace std;


void printSet(const set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test1() {
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(30);

	// set�ڲ���ʱ�ᱻ�Զ�����
	// set����������ظ���ֵ
	printSet(s1); // 10 20 30 40

	// ��������
	set<int>s2(s1);
	printSet(s2);// 10 20 30 40

	// ��ֵ
	set<int>s3 = s1;
	printSet(s3);// 10 20 30 40
}

void test2() {
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	if (s1.empty())
	{
		cout << "s1Ϊ��" << endl;
	}
	else {
		cout << "s1��Ϊ��" << endl;
		cout << "s1�Ĵ�СΪ��" << s1.size() << endl;
		printSet(s1);
	}
}

void test3() {
	set<int>s1;
	s1.insert(10);
	s1.insert(20);
	s1.insert(30);
	s1.insert(40);

	set<int>s2;
	s2.insert(100);
	s2.insert(200);
	s2.insert(300);
	s2.insert(400);

	cout << "����ǰ��" << endl;
	printSet(s1);
	printSet(s2);

	cout << "������" << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);

}

void test4() {
	set<int>s1;
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);

	s1.erase(s1.begin());
	printSet(s1); //20 30 40

	s1.erase(30);
	printSet(s1); //20 40

	s1.clear();
	printSet(s1); // 
}

void test5() {
	set<int>s1;
	s1.insert(30);
	s1.insert(10);
	s1.insert(20);
	s1.insert(40);

	set<int>::iterator pos = s1.find(10);
	cout << *pos << endl;

	// ����set���ԣ�ͳ��Ԫ�صĸ���Ҫô�� 0 Ҫô�� 1 ��ԭ���ǲ���������ظ�Ԫ��
	cout << "10�ĸ�����" << s1.count(10) << endl;;
}

// ����Ĵ���
void test6() {
	pair<string, int>p1("checky", 29);
	cout << p1.first << " : " << p1.second << endl; // checky : 29

	pair<string, int>p2 = make_pair("tom", 28);
	cout << p2.first << " : " << p2.second << endl;	// tom : 28
}

class MyCompare {
public:
	bool operator()(int v1, int v2) const {
		return v1 > v2;
	}
};
// ����
void test7() {
	// �ڶ����ʱ����һ���º������Ӵ�С����
	set<int, MyCompare>s;
	s.insert(30);
	s.insert(10);
	s.insert(20);
	s.insert(40);

	for (set<int, MyCompare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

class Person {
public:
	string name;
	int age;
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
};

class PersonCompare {
public:
	bool operator()(const Person& p1, const Person& p2)const {
		return p1.age > p2.age;
	}
};

void test8() {

	set<Person, PersonCompare> s;
	Person p1("france", 20);
	Person p2("grace", 29);
	Person p3("yello", 27);
	Person p4("gray", 25);
	Person p5("kobe", 23);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);

	for (set<Person, PersonCompare>::iterator it = s.begin(); it != s.end(); it++) {
		cout << " name :" << it->name << " age :" << it->age << endl;
	}
}

int main() {

	test1();
	test2();
	test3();
	test4();
	test6();
	test7();

	test8();
	return 1;
}