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



public:

	int age = 20;
	string name;
	mutable string hobby;

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

	// const ���γ�Ա����
	// ��������
	// 1.��Ա�������const�����ǳ�Ϊ�������Ϊ������
	// 2.�������ڲ����޸ĳ�Ա����
	// 3.��Ա��������ʱ���Ϲؼ���mutable���ڳ���������Ȼ�����޸�

	// this ָ��ı�������ָ�볣����ָ���ָ���ǲ������޸ĵ�
	// const Person * const this
	// �ڳ�Ա�����������const�����ε���thisָ����ָ��ָ���ֵҲ�ǲ������޸ĵ�
	void getAge() const {
		// this->age = 100; �������ʽ��ֵ�����ǿ��޸ĵ�ֵ
		cout << "Person age: " << this->age << endl;
	}

	void setHobby(string hobby) const {
		// ���ᱨ��hobby��mutable������
		this->hobby = hobby;
		cout << "Person hobby: " << this->hobby << endl;
	}

	string getName() {
		cout << "Person name: " << this->name << endl;
	}

};

// ������
void test6() {
	const Person p;
	//p.age = 20;// �������ʽ�����ǿ��޸ĵ���ֵ
	p.hobby = "basketball";// ��mutable���ε����Գ���������޸�

	// ������ֻ�ܵ��ó�����
	p.getAge();// ���Ե��ó�����

	//p.getName();// �������������Ա���� Person::getName �����ݵ��޶����η�
}

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

// ��Ԫ
// 1.ȫ�ֺ�����Ϊ��Ԫ
// 2.����Ϊ��Ԫ
// 3.��Ա������Ϊ��Ԫ

class Building {
	// ȫ�ֺ�����Ϊ��Ԫ
	friend void goodFriend(Building* building);

	// ����Ԫ
	friend class GoodFriend;


public:
	string m_sittingRoom;
	Building()
	{
		m_sittingRoom = "����";
		m_bedRoom = "����";
	}
private:
	string m_bedRoom;
};

// ȫ�ֺ���
void goodFriend(Building* building) {
	cout << "�����Ѻ������ڷ��� " << building->m_sittingRoom << endl;
	cout << "�����Ѻ������ڷ��� " << building->m_bedRoom << endl;// ���Է������˽�г�Ա
}

void test7() {
	Building building;
	goodFriend(&building);
}

// ����Ϊ��Ԫ
class GoodFriend {
public:
	Building* building;

	GoodFriend() {
		building = new Building;
	}

	void visit() {

		cout << "�����������ڷ��� " << building->m_sittingRoom << endl;
		// ���Է���Building��˽�г�Ա����ΪGoodFriend������Ϊ Building �����Ԫ��
		cout << "�����������ڷ��� " << building->m_bedRoom << endl;
	}
};

void test8() {
	GoodFriend gf;
	gf.visit();
}

// ��Ա������Ϊ��Ԫ
class Building2;
class GoodFriend2 {

public:

	void visit(Building2& building);

	void visit3(Building2& building2);
};


class Building2 {

	friend void GoodFriend2::visit3(Building2& building2);

public:
	Building2()
	{
		m_sittingRoom = "����";
		m_bedRoom = "����";
	}
	string m_sittingRoom;
private:
	string m_bedRoom;
};

void GoodFriend2::visit3(Building2& building2) {
	cout << "���������Ա����visit3���ڷ��� " << building2.m_bedRoom << endl;
}

void GoodFriend2::visit(Building2& building2) {
	cout << "���������Ա����visit���ڷ��� " << building2.m_sittingRoom << endl;
}

void test9() {

	Building2 building;
	GoodFriend2 friend2;

	friend2.visit3(building);
	friend2.visit(building);
}


//int main() {
//
//	Circle c1;
//	c1.r = 20;
//	cout << "�ܳ���" << c1.getPerimeter() << endl;
//
//	C1 c;
//	//c.p1 = 10;// ����ʱ���ʲ����ģ���Ϊ��˽��Ȩ��
//
//	S1 s;
//	s.p1 = 200;// �ܷ��ʵ�����ΪĬ�ǹ���Ȩ��
//
//	test();
//
//	test7();
//	test8();
//	test9();
//}

// �����ǳ����
// ������ڶ�����������ռ䣬���п������������ֿ����ķ�ʽԴ��������������ˣ���Ӱ���µĶ����ֵ
// ǳ�������򵥸�ֵ����������¶����a���Եõ�����Դ�����a���Ե�ָ�룬��ô��Դ���������˵Ļ����¶���a��������Ҳ��ʧ�ˣ����ܻ��������