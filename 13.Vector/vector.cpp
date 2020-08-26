#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


// vector 存放内置数据类型
void print(int a) {
	cout << a << endl;
}

// vector 存放自定义数据类型
class Person {
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

void test1() {
	Person p1("p1", 22);
	Person p2("p2", 23);
	Person p3("p3", 24);
	Person p4("p4", 25);

	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	for (vector<Person>::iterator i = v.begin(); i != v.end(); i++)
	{
		//cout << "name: " << (*i).name << " age:" << (*i).age << endl;
		cout << "name: " << i->name << " age:" << i->age << endl;
	}
}
// vector存放指针
void test2() {
	Person p1("p5", 22);
	Person p2("p6", 23);
	Person p3("p7", 24);
	Person p4("p8", 25);

	vector<Person*> v;
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	for (vector<Person*>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << "name: " << (*i)->name << " age:" << (*i)->age << endl;
	}
}

// vector嵌套
void test3() {

	vector<vector<int>> v;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for (size_t i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
		v3.push_back(i + 2);
		v4.push_back(i + 3);
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		vector<int> p_it = *it;
		for (vector<int>::iterator cit = p_it.begin(); cit != p_it.end(); cit++)
		{
			cout << *cit << " ";
		}
		cout << endl;
	}
}

void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// vector 构造函数
void test4() {

	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	vector<int>v3(5, 20);
	printVector(v3);

	vector<int>v4(v3);
	printVector(v4);
}

// 赋值
void test5() {
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int> v2;
	v2 = v1;
	printVector(v2);

	vector<int> v3;
	v3.assign(v2.begin(), v2.end());
	printVector(v3);

	vector<int> v4;
	v4.assign(5, 30);
	printVector(v4);
}

void test6() {
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	if (v1.empty())
	{
		cout << "v1 is empty!" << endl;
	}
	else
	{
		printVector(v1);
	}

	cout << "v1 size:" << v1.size() << endl; // v1 size:10
	cout << "v1 capacity:" << v1.capacity() << endl; // v1 capacity:13

	v1.resize(15, 20); // 比原来的长度大的话，用20默认填充
	printVector(v1); // 0 1 2 3 4 5 6 7 8 9 20 20 20 20 20

	v1.resize(5);
	printVector(v1); // 0 1 2 3 4 ,比原来的长度小的话，超出的元素会被删除掉
}

// 插入和删除
void test7() {

	cout << "=============insert and erase===========" << endl;
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	v1.push_back(20); // 未插入20
	printVector(v1);

	v1.pop_back(); // 尾删
	printVector(v1);

	v1.insert(v1.begin(), 100); // 从开始处添加100
	printVector(v1);

	v1.insert(v1.begin(), 2, 100); // 从开始处添加 2个100
	printVector(v1);

	v1.erase(v1.begin()); // 删除开始处的元素
	printVector(v1);

	// 清空数组
	v1.erase(v1.begin(), v1.end());
	v1.clear();

	cout << "v1 is empty:" << v1.empty() << endl;
}

void test8() {
	cout << "=============vector取存===========" << endl;
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << " v1[" << i << "] = " << v1[i] << endl;
	}

	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << " v1.at(" << i << ") = " << v1.at(i) << endl;
	}

}

// 容器的互换
void test9() {
	cout << "=============vector 互换===========" << endl;

	vector<int>v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	vector<int>v2;
	for (size_t i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);
	v1.swap(v2);
	cout << "v1.swap(v2)" << endl;
	printVector(v1);
	printVector(v2);

	// 时机用途
	v1.clear();
	for (size_t i = 0; i < 100000; i++)
	{
		v1.push_back(i);
	}
	cout << "v1 的容量：" << v1.capacity() << endl; //v1 的容量：138255
	cout << "v1 的大小：" << v1.size() << endl; //v1 的大小：100000

	v1.resize(3);
	cout << "v1 resize 为 3：" << endl;
	cout << "v1 的容量：" << v1.capacity() << endl; //v1 的容量：138255， resize后容量的大小没有变，任然占用多余的空间，浪费资源
	cout << "v1 的大小：" << v1.size() << endl; //v1 的大小：3

	vector<int>(v1).swap(v1); //vector<int>(v1) 匿名对象和v1进行交换，匿名对象占用的内存会在这一行执行结束后自动释放内存
	cout << "v1 的容量：" << v1.capacity() << endl;//v1 的容量：3 ,交换后，容量也变小了，不会占用多余的空间
	cout << "v1 的大小：" << v1.size() << endl;//v1 的大小：3
}

int main() {

	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	// 通过迭代器访问容器中的数据
	vector<int>::iterator itBegin = v.begin(); // 指向第一个元素
	vector<int>::iterator itEnd = v.end(); // 指向数组的最后一个元素的下一个元素

	cout << "while loop:" << endl;
	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}

	cout << "for loop:" << endl;
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i << endl;
	}

	cout << "foreach loop:" << endl;
	for_each(v.begin(), v.end(), print);

	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	return 1;
}