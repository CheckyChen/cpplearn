#include <iostream>

using namespace std;

#define DayOfWeek 7 // 通过宏定义

int main() {

	cout << "一星期有" << DayOfWeek << "天" << endl;

	const int dayOfMonth = 30;
	cout << "一个月有" << dayOfMonth << "天" << endl;

	const int monthOfYear = 12;
	cout << "一个月有" << monthOfYear << "天" << endl;
}