#include <iostream>

using namespace std;

class Person1 {

public:



	int m_A;
	int m_B;

	// ��Ա�������ؼӺ������
	/*Person1 operator+(Person1& p2) {
		Person1 tmp;
		tmp.m_A = this->m_A + p2.m_A;
		tmp.m_B = this->m_B + p2.m_B;
		return tmp;
	}*/
};

// ȫ�ֺ������ؼӺ������
Person1 operator+(Person1& p1, Person1& p2) {
	Person1 tmp;
	tmp.m_A = p1.m_A + p2.m_A;
	tmp.m_B = p1.m_B + p2.m_B;
	return tmp;
}

void plus_test1() {
	Person1 p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person1 p2;
	p2.m_A = 10;
	p2.m_B = 10;

	// ��Ա�������ر���
	//Person1 p3 = p1.operator+(p2);

	//ȫ�ֺ������ر���
	//Person1 p3 = operator+(p1,p2);

	Person1 p3 = p1 + p2;

	cout << "p3.m_A = " << p3.m_A << endl;
	cout << "p3.m_B = " << p3.m_B << endl;
}


class Person2 {
	friend ostream& operator<<(ostream& cout, Person2& person);
public:
	Person2(int a, int b)
	{
		m_A = a;
		m_B = b;
	}
private:
	int m_A;
	int m_B;
};

// �������������
ostream& operator<<(ostream& out_p, Person2& person)
{
	out_p << "m_A = " << person.m_A << " m_B = " << person.m_B;
	return out_p;
}

void leftmove_test() {

	Person2 p(20, 20);

	cout << p << endl;
}


int main() {

	plus_test1();

	leftmove_test();

	return 1;
}
