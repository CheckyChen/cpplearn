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

// �޷��Զ������Ƶ�
void class_tmplate_test() {
	//Person1 p1("framce",22); // �����޷��Զ������Ƶ���ȱ��ģ������б�

	Person1<string, int> p1("framce", 22);
	p1.printPerson();
}

// ��������Ĭ��ģ���������
void class_tmplate_test1() {
	Person1<string> p1("lary", 23);
	p1.printPerson();
}

// ��ģ���еĳ�Ա����������һ��ʼ�����ģ������ڵ���ʱ��ȥ������
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
		obj.print1(); // �����ʱ����ͨ��
	}

	void print2() {
		obj.print2();
	}
};

void class_tmplate_test2() {
	TempPrintClass<PrintClass1> tmp;

	// �����У��ڵ��õ�ʱ��Ŵ���
	tmp.print1(); // print class 1 print1

	// �����������print1ͬʱ���ã����벻ͨ������ print2 ���� PrintClass1 �ĳ�Ա
	// tmp.print2();
}


// ��ģ����̳�
template<class T1>
class Base {
public:
	Base()
	{

	}
	T1 t;
};

// �̳�ʱָ������
class Son :public Base<int> {
public:
	Son()
	{
		cout << "T1���������ͣ�" << typeid(t).name() << endl;
	}

	void print() {
		cout << "print()" << endl;
	}
};

// ����Ҳ�ṩ��ģ���б�
template<class T1, class T2>
class Son2 :public Base<T2> {
public:
	Son2()
	{
		cout << "T1���������ͣ�" << typeid(T1).name() << endl;
		cout << "T2���������ͣ�" << typeid(T2).name() << endl;
	}
	T1 t1;
};

void class_tmplate_test3() {

	Son s1;

	Son2<char, int> s2;
}

// ��ģ���Ա��������ʵ��
template<class T1, class T2>
class BaseClass {

public:
	BaseClass(T1 t1, T2 t2);
	void print();

	T1 name;
	T2 age;
};

// ��Ҫָ����ģ��Ĳ����б�
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