#include <iostream>

using namespace std;

class Circle {

public:
	double PI = 3.14;
	double r;

	/// <summary>
	/// 获取周长 
	/// </summary>
	double getPerimeter() {
		return 2 * PI * r;
	}
};


// 结构和类
// 结构的默认权限是公共的，而类的默认权限是私有的

class C1 {
	int p1; // 没有给定权限，默认为私有的
};

struct S1 {
	int p1; // 默认权限是公共的
};


// 构造函数和析构函数
class Person {

	int age;
	string name;

public:
	// 构造函数
	// ①没有返回值，不用void
	// ②函数名和类名相同，可以发生重载
	// ③创建对象，自动调用，只调用一次
	Person() {
		cout << "Person 构造函数" << endl;
	}

	Person(int id) {
		cout << "Person 有参构造函数" << endl;
	}

	// 拷贝构造函数
	Person(const Person& p) {
		// 将传进来的对象的所有属性赋值给当前的对象

		cout << "Person 拷贝构造函数" << endl;
		age = p.age;
	}

	// 析构函数
	// ①没有返回值，不写void
	// ②函数名和类名相同，没有参数，不能发生重载
	// ③对象销毁时，自动调用，只调用一次
	~Person() {
		cout << "Person 析构函数" << endl;
	}
};

class Car {
	// 默认会创建三个函数
	// 默认构造函数、析构函数、拷贝构造函数

	// 注意：如果写了有参构造函数，那么编译器不会提供默认构造函数
	//      如果写了拷贝构造函数，那么编译器不会提供其他构造函数
};

// 拷贝函数调用时机
// 1.使用一个已经创建完毕的对象来初始化一个新对象
void test1() {
	Person p1;
	Person p2 = Person(p1);
}
// 2.值传递的方式给函数传值
void test2(Person p) {}
void test3() {
	Person p;
	test2(p);
}
// 3.以值方式返回局部对象
Person test4() {
	Person p;
	return p;
}

void test5() {
	Person p = test4();
}

void test() {
	Person p; // 默认构造函数，使用该函数时，不要加小括号，类似 Person p()，这种写法会被认为是函数的申明
	Person p1(1); // 有参构造函数	
	Person p2(p1); // 拷贝构造函数

	// 显示法
	Person p11 = Person(1);
	Person p22 = Person(p11);
}


int main() {

	Circle c1;
	c1.r = 20;
	cout << "周长：" << c1.getPerimeter() << endl;

	C1 c;
	//c.p1 = 10;// 类外时访问不到的，因为是私有权限

	S1 s;
	s.p1 = 200;// 能访问到，因为默是公共权限

	test();
}

// 深拷贝、浅拷贝
// 深拷贝：在堆区重新申请空间，进行拷贝操作，这种拷贝的方式源对象如果被销毁了，不影响新的对象的值
// 浅拷贝：简单赋值拷贝，如果新对象的a属性得到的是源对象的a属性的指针，那么，源对象被销毁了的话，新对象a属性数据也丢失了，可能会出现问题