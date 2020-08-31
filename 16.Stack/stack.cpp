#include<iostream>
#include<stack>

using namespace std;

// 栈 后进先出
void test1() {

	stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << "栈的大小：" << s.size() << endl; //栈的大小：4
	while (!s.empty())
	{
		cout << "栈顶元素：" << s.top() << endl;
		s.pop();
		//栈顶元素：40
		//栈顶元素：30
		//栈顶元素：20
		//栈顶元素：10
	}
	cout << "栈的大小：" << s.size() << endl; //栈的大小：0
}

int main() {
	test1();
	return 1;
}