#include <iostream>

using namespace std;

class Circle {

public:
	double PI = 3.14;
	double r;

	/// <summary>
	/// ��ȡ�ܳ� 
	/// </summary>
	double getPerimeter() {
		return 2 * PI * r;
	}
};


// �ṹ����
// �ṹ��Ĭ��Ȩ���ǹ����ģ������Ĭ��Ȩ����˽�е�

class C1 {
	int p1; // û�и���Ȩ�ޣ�Ĭ��Ϊ˽�е�
};

struct S1 {
	int p1; // Ĭ��Ȩ���ǹ�����
};


// ���캯������������
class Person {

	int age;
	string name;

public:
	// ���캯��
	// ��û�з���ֵ������void
	// �ں�������������ͬ�����Է�������
	// �۴��������Զ����ã�ֻ����һ��
	Person() {
		cout << "Person ���캯��" << endl;
	}

	Person(int id) {
		cout << "Person �вι��캯��" << endl;
	}

	// �������캯��
	Person(const Person& p) {
		// ���������Ķ�����������Ը�ֵ����ǰ�Ķ���

		cout << "Person �������캯��" << endl;
		age = p.age;
	}

	// ��������
	// ��û�з���ֵ����дvoid
	// �ں�������������ͬ��û�в��������ܷ�������
	// �۶�������ʱ���Զ����ã�ֻ����һ��
	~Person() {
		cout << "Person ��������" << endl;
	}
};

class Car {
	// Ĭ�ϻᴴ����������
	// Ĭ�Ϲ��캯���������������������캯��

	// ע�⣺���д���вι��캯������ô�����������ṩĬ�Ϲ��캯��
	//      ���д�˿������캯������ô�����������ṩ�������캯��
};

// ������������ʱ��
// 1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test1() {
	Person p1;
	Person p2 = Person(p1);
}
// 2.ֵ���ݵķ�ʽ��������ֵ
void test2(Person p) {}
void test3() {
	Person p;
	test2(p);
}
// 3.��ֵ��ʽ���ؾֲ�����
Person test4() {
	Person p;
	return p;
}

void test5() {
	Person p = test4();
}

void test() {
	Person p; // Ĭ�Ϲ��캯����ʹ�øú���ʱ����Ҫ��С���ţ����� Person p()������д���ᱻ��Ϊ�Ǻ���������
	Person p1(1); // �вι��캯��	
	Person p2(p1); // �������캯��

	// ��ʾ��
	Person p11 = Person(1);
	Person p22 = Person(p11);
}


int main() {

	Circle c1;
	c1.r = 20;
	cout << "�ܳ���" << c1.getPerimeter() << endl;

	C1 c;
	//c.p1 = 10;// ����ʱ���ʲ����ģ���Ϊ��˽��Ȩ��

	S1 s;
	s.p1 = 200;// �ܷ��ʵ�����ΪĬ�ǹ���Ȩ��

	test();
}

// �����ǳ����
// ������ڶ�����������ռ䣬���п������������ֿ����ķ�ʽԴ��������������ˣ���Ӱ���µĶ����ֵ
// ǳ�������򵥸�ֵ����������¶����a���Եõ�����Դ�����a���Ե�ָ�룬��ô��Դ���������˵Ļ����¶���a��������Ҳ��ʧ�ˣ����ܻ��������