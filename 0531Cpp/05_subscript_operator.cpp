#include <iostream>
#include <cassert>

using namespace std;

// []

class IntArray // �迭 Ŭ������ ���� ���� ������ ������ֱ⵵ ��
{
public:
	int Get(int index) { return list[index]; }
	void Set(int index, int value) { list[index] = value; }

	int* GetList() { return list; }

	int& operator[](int index)
	{
		// ������ üũ
		if (index < 0 || index > 10) // �ӵ��� ��� ����.
		{
			cout << "Array index is out of bound exception" << endl;
		}

		assert(index >= 0); // �ƿ� ���α׷��� �Ͷ߸��� ������. () ���� false �� ����

		return list[index];
	}

private:
	int list[3];
};

int main()
{
	int arr1[3] = { 1,2,3 };
	//cout << arr1[-1] << endl;
	//cout << arr1[3] << endl; --> �����Ϸ��� ���� ������ ������ ������ ��쵵 �ִ�.

	IntArray list;

	list.Set(0, 1);
	list.Set(1, 2);
	list.Set(2, 3);
	list.Set(3, 4);
	list.Set(4, 5);

	cout << list.Get(0) << endl;
	cout << list.Get(1) << endl;
	cout << list.Get(2) << endl;
	cout << list.Get(3) << endl;
	cout << list.Get(4) << endl; // ���ŷο�, �迭�� ���°� �ƴ�

	auto arr = list.GetList();
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[3] << endl;
	cout << arr[4] << endl; // �迭�� ũ�⿡ ���� ������ ����, ������������ --> [] �����ε�

	list[0] = 1;
	list[1] = 1;
	list[2] = 1;
	list[3] = 1;

	return 0;
}