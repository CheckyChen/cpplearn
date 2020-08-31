#include <iostream>
#include <queue>

using namespace std;

// 队列 先进先出
void test1() {

	queue<int>q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);

	cout << "队列大小：" << q.size() << endl;
	while (!q.empty())
	{
		cout << "队头元素:" << q.front() << endl;
		cout << "队尾元素:" << q.back() << endl;
		q.pop();
	}
	cout << "队列大小：" << q.size() << endl;
}

int main() {
	test1();
	return 1;
}