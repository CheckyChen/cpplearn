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


// 类模板与继承
template<class T1>
class Base {
public:
	Base()
	{

	}
	T1 t;
};

// 继承时指定类型
class Son :public Base<int> {
public:
	Son()
	{
		cout << "T1的数据类型：" << typeid(t).name() << endl;
	}

	void print() {
		cout << "print()" << endl;
	}
};

// 子类也提供类模板列表
template<class T1, class T2>
class Son2 :public Base<T2> {
public:
	Son2()
	{
		cout << "T1的数据类型：" << typeid(T1).name() << endl;
		cout << "T2的数据类型：" << typeid(T2).name() << endl;
	}
	T1 t1;
};

void class_tmplate_test3() {

	Son s1;

	Son2<char, int> s2;
}

// 类模板成员函数类外实现
template<class T1, class T2>
class BaseClass {

public:
	BaseClass(T1 t1, T2 t2);
	void print();

	T1 name;
	T2 age;
};

// 需要指定类模板的参数列表
template<class T1, class T2>
BaseClass<T1, T2>::BaseClass(T1 t1, T2 t2) {
	this->name = t1;
	this->age = t2;
}

template<class T1, class T2>
void BaseClass<T1, T2>::print() {
	cout << "name = " << this->name << " ,age = " << this->age << endl;
}

void class_template_test4() {
	BaseClass<string, int> base("frank",22);
	base.print(); // name = frank ,age = 22
}


int main() {

	//class_tmplate_test();
	//class_tmplate_test1();
	//class_tmplate_test2();
	//class_tmplate_test3();
	class_template_test4();
	return 1;
}