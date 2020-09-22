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

int main() {
	//class_tmplate_test();
	//class_tmplate_test1();
	
	class_tmplate_test2(); 
	return 1;
}