#include <iostream>
#include <queue>

using namespace std;

// ���� �Ƚ��ȳ�
void test1() {

	queue<int>q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	cout << "���д�С��" << q.size() << endl;
	while (!q.empty())
	{
		cout << "��ͷԪ��:" << q.front() << endl;
		cout << "��βԪ��:" << q.back() << endl;
		q.pop();
	}
	cout << "���д�С��" << q.size() << endl;
}

int main() {
	test1();
	return 1;
}