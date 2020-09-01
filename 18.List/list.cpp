#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test1() {
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);

	list<int>l2(l1.begin(), l1.end());
	printList(l2);

	list<int>l3(l2);
	printList(l3);

	list<int> l4(10, 100);
	printList(l4);
}

void test2() {

	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);//10 20 30 40

	list<int> l2;
	l2.assign(l1.begin(), l1.end());
	printList(l2);//10 20 30 40

	list<int>l3;
	l3.assign(10, 200);
	printList(l3);//200 200 200 200 200 200 200 200 200 200

	list<int>l4;
	l4 = l3;
	printList(l4);//200 200 200 200 200 200 200 200 200 200

	cout << "����ǰ��" << endl;
	printList(l4);
	printList(l1);
	l4.swap(l1);
	cout << "������" << endl;
	printList(l4);
	printList(l1);
}

void test3() {
	list<int>l1;
	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	printList(l1);//10 20 30 40

	// �ж��Ƿ�Ϊ��
	bool flag = l1.empty();

	// ����
	int l_size = l1.size();

	// ����ָ����С
	l1.resize(10);
	printList(l1);

	l1.resize(10, 200);
	printList(l1);

	l1.resize(2);
	printList(l1);
}

void test4() {
	// ͷ��
	list<int>l1;
	l1.push_front(10);
	l1.push_front(20);
	l1.push_front(30);
	printList(l1);//30 20 10

	// β��
	l1.push_back(40);
	l1.push_back(50);
	printList(l1);//30 20 10 40 50

	// ͷɾ
	l1.pop_front();
	printList(l1);//20 10 40 50

	// βɾ
	l1.pop_back();
	printList(l1);//20 10 40

	list<int>::const_iterator it = l1.begin();
	l1.insert(it, 1000);// ��һ��λ�ò���1000
	printList(l1);//1000 20 10 40

	l1.insert(it++, 2000);// �ڶ���λ�ò���2000
	printList(l1);// 1000 2000 20 10 40

	list<int>::const_iterator it1 = l1.begin();
	l1.erase(it1);
	//l1.erase(++it1);
	printList(l1);//2000 20 10 40

	l1.push_back(10000);
	l1.push_back(10000);
	l1.push_back(10000);
	printList(l1);//2000 20 10 40 10000 10000 10000

	// ɾ������������10000��Ԫ��
	l1.remove(10000); 
	printList(l1);//2000 20 10 40

	// ���
	l1.clear();
}

int main() {

	//test1();
	//test2();
	//test3();
	test4();

	return 1;
}