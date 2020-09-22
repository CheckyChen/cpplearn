#include<iostream>
#include<string>

using namespace std;

template<typename T>
void mySwap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

void test1() {
	int a = 1;
	int b = 2;
	mySwap(a, b);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

// 具体化的模板
class Person {

public:
	string m_Name;
	int m_Age;
	Person(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}
};

template<typename T>
bool myCompare(T& a, T& b)
{
	return a == b;
}

// 提供具体化的模板函数
template<> bool myCompare(Person& p1, Person& p2) {

	return p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age;
}


void compare_test() {
	Person p1("checky", 22);
	Person p2("checky", 22);

	bool ret = myCompare(p1, p2);

	if (ret)
	{
		cout << "p1 == p2" << endl;
	}
	else
	{
		cout << "p1 != p2" << endl;
	}
}

//int main() {
//	//test1();
//	compare_test();
//	return 1;
//}