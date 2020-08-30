#include <iostream>
#include<deque>
using namespace std;

// ���ܣ�˫�����飬���Զ�ͷ�˽���ɾ������
// ��vector������
// 1.vector����ͷ���Ĳ���ɾ��Ч�ʽϵͣ�������Խ��Ч��Խ��
// 2.deque��Զ��ԣ�ͷ���Ĳ���ɾ���ٶȱ�vector��
// 3.vector����Ԫ��ʱ���ٶȻ��deque�죬��������ڲ�ʵ���й�

// ʵ��ԭ��
// deque�ڲ��и��п�����ά��ÿ�λ������е����ݣ��������д����ʵ���ݣ��п���ά������ÿ���������ĵ�ַ��ʹ��ʹ��dequeʱ��һƬ�������ڴ�ռ�


void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// ���캯��
void test1() {

	deque<int>d;
	for (size_t i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printDeque(d); // 0 1 2 3 4 5 6 7 8 9

	deque<int> d1(d.begin(), d.end());
	printDeque(d1);// 0 1 2 3 4 5 6 7 8 9

	deque<int>d2(10, 100);
	printDeque(d2); // 100 100 100 100 100 100 100 100 100 100

	deque<int>d3 = d2;
	printDeque(d3); // 100 100 100 100 100 100 100 100 100 100
}

// ��ֵ����
void test2() {
	deque<int>d;
	for (size_t i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printDeque(d); // 0 1 2 3 4 5 6 7 8 9

	deque<int> d2 = d;
	printDeque(d2); // 0 1 2 3 4 5 6 7 8 9

	deque<int> d3(d2.begin(), d2.end());
	printDeque(d3); // 0 1 2 3 4 5 6 7 8 9

	deque<int>d4;
	d4.assign(d.begin(), d.end());
	printDeque(d4); // 0 1 2 3 4 5 6 7 8 9

	deque<int>d5;
	d5.assign(10, 100);
	printDeque(d5); // 100 100 100 100 100 100 100 100 100 100
}

// ��С����
void test3() {
	deque<int> d1;
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1); // 0 1 2 3 4 5 6 7 8 9
	deque<int> d2;
	// �ж��Ƿ�Ϊ��
	cout << "d1 �Ƿ�Ϊ�գ�" << d1.empty() << endl; // d1 �Ƿ�Ϊ�գ�0 
	cout << "d2 �Ƿ�Ϊ�գ�" << d2.empty() << endl; // d1 �Ƿ�Ϊ�գ�1

	// ��ȡ��С
	cout << "d1 �Ĵ�С��" << d1.size() << endl; //d1 �Ĵ�С��10

	// ����ָ����С
	d1.resize(15, 1); // ��ԭ���Ĵ�Ĭ����1���
	printDeque(d1); //0 1 2 3 4 5 6 7 8 9 1 1 1 1 1

	d1.resize(5);// ��ԭ����С���򳬳��Ļᱻ������
	printDeque(d1); // 0 1 2 3 4 
}

void test4() {
	deque<int> d1;
	// β��
	d1.push_back(10);
	d1.push_back(20);
	// ͷ��
	d1.push_front(100);
	d1.push_front(200);

	printDeque(d1); //200 100 10 20

	// βɾ
	d1.pop_back();
	// ͷɾ
	d1.pop_front();
	printDeque(d1); // 100 10

	d1.insert(d1.begin(), 1000);
	printDeque(d1); // 1000 100 10

	deque<int> d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d1.insert(d1.begin(), d2.begin(), d2.end());
	printDeque(d1); //1 2 3 1000 100 10
}

// ɾ������
void test5() {
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1); // 200 100 10 20

	d1.erase(d1.begin());
	printDeque(d1); // 100 10 20

	//d1.erase(d1.begin(),d1.end());
	d1.clear();// ���
	printDeque(d1); 
}

int main() {

	//test1();
	//test2();
	//test3();
	//test4();
	test5();

	return 1;
}