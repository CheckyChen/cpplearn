#include <iostream>
#include <string>

using namespace std;

/*
string 构造函数：
①string()					// 默认构造函数
②string(const char* s)		// 使用字符串 s 初始化
③string(const string& str)	// 使用一个string对象初始化另外一个string对象
④string(int n,char c)		// 使用n个字符c初始化
*/

// 初始化
void test01() {
	string s1;

	const char* s2 = "hello world!";
	string s3(s2);
	cout << "s3 = " << s3 << endl;

	string s4(s3);
	cout << "s4 = " << s4 << endl;

	string s5(5, 'h');
	cout << "s5 = " << s5 << endl;
}

// 赋值操作
void test02() {

	string s0;
	s0 = "checky chan";
	cout << "s0 = " << s0 << endl; // checky chan

	s0 = 'a';
	cout << "s0 = " << s0 << endl; // aa

	string s1;
	s1.assign("hello C++", 5); // 把字符串的前n个字符赋值给当前字符串 
	cout << "s1 = " << s1 << endl; // s1 = hello

	string s2;
	s2.assign(5, 'a');
	cout << "s2 = " << s2 << endl; // aaaaa

	string s3;
	s3.assign(s2);
	cout << "s3 = " << s3 << endl; // aaaa

	string s4;
	s4.assign("checky");
	cout << "s4 = " << s4 << endl; // checky
}

// 追加
void test03() {
	string s1 = "我";
	s1 += "爱运动";
	cout << "s1 = " << s1 << endl; // 我爱运动
	s1 += ':';
	cout << "s1 = " << s1 << endl; // 我爱运动:

	s1.append(" 篮球");
	cout << "s1 = " << s1 << endl; // 我爱运动: 篮球

	s1.append(" 足球，网球",0,5);    // 我爱运动： 篮球 足球 注意：一个中文占两个字符
	cout << "s1 = " << s1 << endl;

	string s2 = "打篮球";
	s2.append("aabbcc",1,3); 
	cout << "s2 = " << s2 << endl; // 打篮球abb

}

int main() {
	test01();
	test02();
	test03();
	return 1;
}