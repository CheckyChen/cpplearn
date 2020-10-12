#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;




void all_of_test() {

	vector<int> v = { 3,5,7,11,13,17,19,23 ,14 };
	bool all_odd_flag = all_of(v.begin(), v.end(), [](int i) {return i % 2 != 0; });
	if (all_odd_flag)
	{
		cout << "ȫ������" << endl;
	}
	else
	{
		cout << "���ڲ���Ԫ�ز�������" << endl;
	}
}

void any_of_test() {
	vector<int> v = { 0,1,-1,3,-3,5,-5 };
	vector<int> v2 = { 0,1,1,3,3,5,5 };
	//bool any_negative_flag = any_of(v.begin(), v.end(), [](int val) {return val < 0; });
	bool any_negative_flag = any_of(v2.begin(), v2.end(), [](int val) {return val < 0; });
	if (any_negative_flag)
	{
		cout << "v�д��ڸ���" << endl;
	}
	else
	{
		cout << "v�в����ڸ���" << endl;
	}
}

void myPrint(int i) {
	cout << i << " ";
}

bool myDescSort(int i, int j) {
	return i > j;
}

void binary_search_test() {
	int arr[] = { 1,2,3,4,5,4,3,2,1 };
	vector<int> v(arr, arr + 9);

	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	bool contains4Flag = binary_search(v.begin(), v.end(), 4);
	if (contains4Flag)
	{
		cout << "�����а���4" << endl;
	}
	else
	{
		cout << "�����в�����4" << endl;
	}

	// ��������
	sort(v.begin(), v.end(), myDescSort);
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	bool contains5Flag = binary_search(v.begin(), v.end(), 5);
	if (contains5Flag)
	{
		cout << "�����а���5" << endl;
	}
	else
	{
		cout << "�����в�����5" << endl;
	}
}



//int main() {

//	all_of_test();
//	any_of_test();
//	binary_search_test();
//	return 1;
//}