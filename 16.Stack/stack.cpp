#include<iostream>
#include<stack>

using namespace std;

// ջ ����ȳ�
void test1() {

	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "ջ�Ĵ�С��" << s.size() << endl; //ջ�Ĵ�С��4
	while (!s.empty())
	{
		cout << "ջ��Ԫ�أ�" << s.top() << endl;
		s.pop();
		//ջ��Ԫ�أ�40
		//ջ��Ԫ�أ�30
		//ջ��Ԫ�أ�20
		//ջ��Ԫ�أ�10
	}
	cout << "ջ�Ĵ�С��" << s.size() << endl; //ջ�Ĵ�С��0
}

int main() {
	test1();
	return 1;
}