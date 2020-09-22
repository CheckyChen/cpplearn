#include <iostream>
#include <string>

using namespace std;


template<typename NameType, typename AgeType = int>
class Person1 {
public:

	string m_Name;
	int m_Age;
	Person1(NameType name, AgeType age)
	{
		m_Name = name;
		m_Age = age;
	}

	void printPerson() {
		cout << " name = " << m_Name << ", age = " << m_Age << endl;
	}
};

// 无法自动类型推导
void class_tmplate_test() {
	//Person1 p1("framce",22); // 错误，无法自动类型推导，缺少模板参数列表

	Person1<string, int> p1("framce", 22);
	p1.printPerson();
}

// 可以设置默认模板参数类型
void class_tmplate_test1() {
	Person1<string> p1("lary", 23);
	p1.printPerson();
}

// 类模板中的成员函数并不是一开始创建的，而是在调用时才去创建的
class PrintClass1 {
public:
	void print1() {
		cout << "print class 1 print1" << endl;
	}
};

class PrintClass2 {
public:
	void print2() {
		cout << "print class 2 print2" << endl;
	}
};

template<typename T>
class TempPrintClass {
public:
	T obj;

	void print1() {
		obj.print1(); // 编译的时候能通过
	}

	void print2() {
		obj.print2();
	}
};

void class_tmplate_test2() {
	TempPrintClass<PrintClass1> tmp;

	// 能运行，在调用的时候才创建
	tmp.print1(); // print class 1 print1

	// 不能与上面的print1同时调用，编译不通过，报 print2 不是 PrintClass1 的成员
	// tmp.print2();
}

int main() {
	//class_tmplate_test();
	//class_tmplate_test1();
	
	class_tmplate_test2(); 
	return 1;
}