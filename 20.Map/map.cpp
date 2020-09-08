#include <iostream>
#include <map>

using namespace std;

void printMap(map<int, int>& m) {

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
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
	* °´ÕÕkey×Ô¶¯ÉıĞòÅÅĞò
	key:1 value:10
	key:2 value:20
	key:3 value:30
	key:4 value:40
	key:5 value:50
	*/
}


int main() {
	test1();
	return 1;
}