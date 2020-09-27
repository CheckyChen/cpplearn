#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void func1(int val) {
	cout << val << " ";
}

class Func2 {
public:
	void operator()(int val) {

		cout << val << " ";
	}
};

void traverse_test1() {

	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);

	// ��ͨ����,�ź�����
	for_each(v.begin(), v.end(), func1);
	cout << endl;

	// �º���
	for_each(v.begin(), v.end(), Func2());
	cout << endl;
}

class Transform {
public:
	int operator()(int val) {
		// ��Դ������ÿ��Ԫ�ص�ֵ���� +10 ����
		return val + 10;
	}
};
void transform_test1() {
	vector<int> v;
	for (size_t i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>v2;
	v2.resize(v.size()); // Ŀ������������������ռ�

	transform(v.begin(), v.end(), v2.begin(), Transform());

	for_each(v2.begin(), v2.end(), Func2());
	cout << endl;
}

//int main() {
//	traverse_test1();
//	transform_test1();
//	return 1;
//}