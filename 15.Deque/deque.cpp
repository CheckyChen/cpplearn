#include <iostream>
#include<deque>
using namespace std;

// 功能：双端数组，可以对头端进行删除操作
// 与vector的区别
// 1.vector对于头部的插入删除效率较低，数据量越大，效率越低
// 2.deque相对而言，头部的插入删除速度比vector快
// 3.vector访问元素时的速度会比deque快，这和两者内部实现有关

// 实现原理：
// deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据，中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间


void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// 构造函数
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

// 赋值操作
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

// 大小操作
void test3() {
	deque<int> d1;
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1); // 0 1 2 3 4 5 6 7 8 9
	deque<int> d2;
	// 判断是否为空
	cout << "d1 是否为空：" << d1.empty() << endl; // d1 是否为空：0 
	cout << "d2 是否为空：" << d2.empty() << endl; // d1 是否为空：1

	// 获取大小
	cout << "d1 的大小：" << d1.size() << endl; //d1 的大小：10

	// 重新指定大小
	d1.resize(15, 1); // 比原来的大，默认以1填充
	printDeque(d1); //0 1 2 3 4 5 6 7 8 9 1 1 1 1 1

	d1.resize(5);// 比原来的小，则超出的会被舍弃掉
	printDeque(d1); // 0 1 2 3 4 
}

void test4() {
	deque<int> d1;
	// 尾插
	d1.push_back(10);
	d1.push_back(20);
	// 头插
	d1.push_front(100);
	d1.push_front(200);

	printDeque(d1); //200 100 10 20

	// 尾删
	d1.pop_back();
	// 头删
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

// 删除操作
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
	d1.clear();// 清空
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