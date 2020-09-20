#include <iostream>
#include <fstream>

using namespace std;


void test1() {

	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "this is first line" << endl;
	ofs << "this is second line" << endl;
	ofs.close();

}

//int main() {
//
//	test1();
//	return 1;
//}