#include <iostream>
#include <cassert>

using namespace std;

// []

class IntArray // 배열 클래스를 만들어서 범위 제한을 만들어주기도 함
{
public:
	int Get(int index) { return list[index]; }
	void Set(int index, int value) { list[index] = value; }

	int* GetList() { return list; }

	int& operator[](int index)
	{
		// 경계범위 체크
		if (index < 0 || index > 10) // 속도는 대신 느림.
		{
			cout << "Array index is out of bound exception" << endl;
		}

		assert(index >= 0); // 아예 프로그램을 터뜨리고 싶을때. () 안이 false 면 터짐

		return list[index];
	}

private:
	int list[5];
};

int main()
{
	int arr1[3] = { 1,2,3 };
	//cout << arr1[-1] << endl;
	//cout << arr1[3] << endl; --> 컴파일러에 따라 쓰레기 값으로 나오는 경우도 있다.

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
	cout << list.Get(4) << endl; // 번거로움, 배열의 형태가 아님

	auto arr = list.GetList();
	arr[0] = 6;
	arr[1] = 7;
	arr[2] = 8;
	arr[3] = 9;
	arr[4] = 10;

	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[3] << endl;
	cout << arr[4] << endl; // 배열의 크기에 대한 정보가 없음, 안전하지않음

	list[0] = 11;
	list[1] = 12;
	list[2] = 13;
	list[3] = 14;
	list[4] = 15;

	cout << list.Get(0) << endl;
	cout << list.Get(1) << endl;
	cout << list.Get(2) << endl;
	cout << list.Get(3) << endl;
	cout << list.Get(4) << endl;

	return 0;
}
