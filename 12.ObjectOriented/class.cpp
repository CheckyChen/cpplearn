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



public:

	int age = 20;
	string name;
	mutable string hobby;

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

	// const 修饰成员函数
	// 常函数：
	// 1.成员函数后加const后我们称为这个函数为常函数
	// 2.常函数内不可修改成员属性
	// 3.成员属性声明时加上关键字mutable后，在常函数中依然可以修改

	// this 指针的本质是是指针常量，指针的指向是不可以修改的
	// const Person * const this
	// 在成员函数后面加上const，修饰的是this指向，让指针指向的值也是不可以修改的
	void getAge() const {
		// this->age = 100; 报错，表达式左值必须是可修改的值
		cout << "Person age: " << this->age << endl;
	}

	void setHobby(string hobby) const {
		// 不会报错，hobby被mutable修饰了
		this->hobby = hobby;
		cout << "Person hobby: " << this->hobby << endl;
	}

	string getName() {
		cout << "Person name: " << this->name << endl;
	}

};

// 常对象
void test6() {
	const Person p;
	//p.age = 20;// 报错，表达式必须是可修改的左值
	p.hobby = "basketball";// 被mutable修饰的属性常对象可以修改

	// 常对象只能调用常函数
	p.getAge();// 可以调用常函数

	//p.getName();// 报错，对象含有与成员函数 Person::getName 不兼容的限定修饰符
}

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

// 友元
// 1.全局函数作为友元
// 2.类作为友元
// 3.成员函数作为友元

class Building {
	// 全局函数作为友元
	friend void goodFriend(Building* building);

	// 类友元
	friend class GoodFriend;


public:
	string m_sittingRoom;
	Building()
	{
		m_sittingRoom = "客厅";
		m_bedRoom = "卧室";
	}
private:
	string m_bedRoom;
};

// 全局函数
void goodFriend(Building* building) {
	cout << "好朋友函数正在访问 " << building->m_sittingRoom << endl;
	cout << "好朋友函数正在访问 " << building->m_bedRoom << endl;// 可以访问类的私有成员
}

void test7() {
	Building building;
	goodFriend(&building);
}

// 类作为友元
class GoodFriend {
public:
	Building* building;

	GoodFriend() {
		building = new Building;
	}

	void visit() {

		cout << "好朋友类正在访问 " << building->m_sittingRoom << endl;
		// 可以访问Building的私有成员，因为GoodFriend被修饰为 Building 类的友元了
		cout << "好朋友类正在访问 " << building->m_bedRoom << endl;
	}
};

void test8() {
	GoodFriend gf;
	gf.visit();
}

// 成员函数作为友元
class Building2;
class GoodFriend2 {

public:

	void visit(Building2& building);

	void visit3(Building2& building2);
};


class Building2 {

	friend void GoodFriend2::visit3(Building2& building2);

public:
	Building2()
	{
		m_sittingRoom = "客厅";
		m_bedRoom = "卧室";
	}
	string m_sittingRoom;
private:
	string m_bedRoom;
};

void GoodFriend2::visit3(Building2& building2) {
	cout << "好朋友类成员函数visit3正在访问 " << building2.m_bedRoom << endl;
}

void GoodFriend2::visit(Building2& building2) {
	cout << "好朋友类成员函数visit正在访问 " << building2.m_sittingRoom << endl;
}

void test9() {

	Building2 building;
	GoodFriend2 friend2;

	friend2.visit3(building);
	friend2.visit(building);
}


//int main() {
//
//	Circle c1;
//	c1.r = 20;
//	cout << "周长：" << c1.getPerimeter() << endl;
//
//	C1 c;
//	//c.p1 = 10;// 类外时访问不到的，因为是私有权限
//
//	S1 s;
//	s.p1 = 200;// 能访问到，因为默是公共权限
//
//	test();
//
//	test7();
//	test8();
//	test9();
//}

// 深拷贝、浅拷贝
// 深拷贝：在堆区重新申请空间，进行拷贝操作，这种拷贝的方式源对象如果被销毁了，不影响新的对象的值
// 浅拷贝：简单赋值拷贝，如果新对象的a属性得到的是源对象的a属性的指针，那么，源对象被销毁了的话，新对象a属性数据也丢失了，可能会出现问题