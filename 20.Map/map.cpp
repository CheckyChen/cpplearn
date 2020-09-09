#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int>& m) {

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
	cout << endl;
}

void test1() {
	map<int, int>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(5, 50));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));

	printMap(m);

	/*
	* 按照key自动升序排序
	key:1 value:10
	key:2 value:20
	key:3 value:30
	key:4 value:40
	key:5 value:50
	*/
}

void test2() {
	map<int, int>m1;
	m1.insert(make_pair(1, 10));
	m1.insert(make_pair(2, 20));
	m1.insert(make_pair(3, 30));
	m1.insert(make_pair(4, 40));

	map<int, int>m2;
	m2.insert(make_pair(5, 100));
	m2.insert(make_pair(6, 200));
	m2.insert(make_pair(7, 300));
	m2.insert(make_pair(8, 400));

	cout << "交换前：" << endl;
	printMap(m1);
	printMap(m2);

	m1.swap(m2);
	cout << "交换后：" << endl;
	printMap(m1);
	printMap(m2);
}

void test3() {
	map<int, int>m1;
	m1.insert(make_pair(1, 10));
	m1.insert(make_pair(2, 20));
	m1.insert(make_pair(3, 30));
	m1.insert(make_pair(4, 40));

	if (m1.empty())
	{
		cout << "map为空" << endl;
	}
	else {
		cout << "map不为空" << endl;
		cout << "map的大小：" << m1.size() << endl;
	}
}

void test4() {
	map<int, int>m1;
	m1.insert(make_pair(1, 10));
	m1.insert(make_pair(2, 20));
	m1.insert(make_pair(3, 30));
	m1.insert(make_pair(4, 40));

	// 删除第一个元素
	m1.erase(m1.begin());
	// 按照 key 删除
	m1.erase(3);
	// 清空
	m1.erase(m1.begin(), m1.end());
}

void test5() {
	map<int, int>m1;
	m1.insert(make_pair(1, 10));
	m1.insert(make_pair(2, 20));
	m1.insert(make_pair(3, 30));
	m1.insert(make_pair(4, 40));

	map<int, int>::iterator pos = m1.find(1);
	if (pos != m1.end())
	{
		cout << "查找到了元素：" << pos->first << " - " << pos->second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	// map 不允许插入重复key元素，cout统计而言，结果要么是1，要么是0
	// multimap count 的统计可能大于1
	int num = m1.count(3);
	cout << "num = " << num << endl;
}

class MyCompare {
public:
	bool operator()(int v1, int v2) const{
		return v1 > v2;
	}
};
void test6() {
	// 传入自定义的比较仿函数，按照从大到小的排序排序
	map<int, int, MyCompare>m1;
	m1.insert(make_pair(1, 10));
	m1.insert(make_pair(2, 20));
	m1.insert(make_pair(3, 30));
	m1.insert(make_pair(4, 40));

	for (map<int, int, MyCompare>::iterator i = m1.begin(); i != m1.end(); i++)
	{
		cout << i->first << " - " << i->second << endl;
	}
}


int main() {
	test1();
	test2();
	test3();

	test6();
	return 1;
}