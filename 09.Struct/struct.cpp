#include <iostream>
using namespace std;
#include <string>

struct Student {
	string name;
	int age;
	int score;
};

struct Teacher {
	int id;
	string name;
	int age;

	Student stu;
};

// ����ֵ
void printStudent1(struct Student s) {

	s.score = 80;// �������޸�student�����ԣ�ʵ�ε�ֵ����ı�
	cout << "sub function1 student`s name:" << s.name << " age:" << s.age << " score:" << s.score << endl;
}

// ����ָ��
void printStudent2(struct Student* p) {

	p->score = 85;// �������޸�student�����ԣ���ôʵ�ε�ֵҲ����ű仯
	cout << "sub function2 student`s name:" << p->name << " age:" << p->age << " score:" << p->score << endl;
}

// ���ݳ���ָ�룬��ֹʵ�α����޸�
void printStudent3(const struct Student* p) {

	// p->score = 100; ���벻��ȥ����Ϊ����ָ�룬ֵ���ܱ��޸�
	cout << "sub function2 student`s name:" << p->name << " age:" << p->age << " score:" << p->score << endl;
}

int main() {

	Student s1;
	s1.name = "checky";
	s1.age = 29;
	s1.score = 80;

	cout << "name=" << s1.name << " age=" << s1.age << " score=" << s1.score << endl;

	Student s2 = { "ditor",30,70 };
	cout << "name=" << s2.name << " age=" << s2.age << " score=" << s2.score << endl;

	Student students[3] = {
		{"name1",25,70},
		{"name1",25,70},
		{"name1",25,70}
	};

	Student* p = &s1;
	// �����ָ��ṹ�壬��������ͨ�� -> ����
	cout << "name=" << p->name << " age=" << p->age << " score=" << p->score << endl;

	Teacher t;
	t.id = 10000;
	t.name = "Frank";
	t.age = 35;
	Student s3 = { "Grace",20,100 };
	t.stu = s3;
	cout << "teacher`s name:" << t.name << " age:" << t.age
		<< "student`s name:" << t.stu.name << " age:" << t.stu.age << " score:" << t.stu.score << endl;

	Student s4 = {"checky",25,99};

	printStudent1(s4);
	printStudent2(&s4);

	cout << "main function student`s name:" << s4.name << " age:" << s4.age << " score:" << s4.score << endl;

	return 0;
}