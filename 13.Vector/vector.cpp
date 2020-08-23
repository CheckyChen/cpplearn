#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


// vector 存放内置数据类型
void print(int a) {
	cout << a << endl;
}

// vector 存放自定义数据类型
class Person {
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

void test1() {
	Person p1("p1", 22);
	Person p2("p2", 23);
	Person p3("p3", 24);
	Person p4("p4", 25);

	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	for (vector<Person>::iterator i = v.begin(); i != v.end(); i++)
	{
		//cout << "name: " << (*i).name << " age:" << (*i).age << endl;
		cout << "name: " << i->name << " age:" << i->age << endl;
	}
}
// vector存放指针
void test2() {
	Person p1("p5", 22);
	Person p2("p6", 23);
	Person p3("p7", 24);
	Person p4("p8", 25);

	vector<Person*> v;
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	for (vector<Person*>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << "name: " << (*i)->name << " age:" << (*i)->age << endl;
	}
}

// vector嵌套
void test3() {

	vector<vector<int>> v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for (size_t i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
		v3.push_back(i + 2);
		v4.push_back(i + 3);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		vector<int> p_it = *it;
		for (vector<int>::iterator cit = p_it.begin(); cit != p_it.end(); cit++)
		{
			cout << *cit << " ";
		}
		cout << endl;
	}
}


int main() {

	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	// 通过迭代器访问容器中的数据
	vector<int>::iterator itBegin = v.begin(); // 指向第一个元素
	vector<int>::iterator itEnd = v.end(); // 指向数组的最后一个元素的下一个元素

	cout << "while loop:" << endl;
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}

	cout << "for loop:" << endl;
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i << endl;
	}

	cout << "foreach loop:" << endl;
	for_each(v.begin(), v.end(), print);

	test1();

	test2();

	test3();

	return 1;
}