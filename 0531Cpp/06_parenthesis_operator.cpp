#include <iostream>

using namespace std;

// ��ȣ������() �����ε� - ��ü�� �Լ�ó�� ����ϰ� ���� ��

class Counter
{
	int count = 0;

public:
	int operator()(int i) { return count += i; }
};

class Point
{
	int xpos, ypos;

public:
	Point(int x = 0,int y=0): xpos(x), ypos(y) {}

	Point operator+(const Point& pos) const
	{
		return Point(xpos + pos.xpos, ypos + pos.ypos);
	}

	friend ostream& operator << (ostream& os, const Point& pos)
	{
		os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return os;
	}
};

class Adder
{
public:
	int operator()(const int& n1, const int& n2)
	{
		return n1 + n2;
	}
	double operator()(const double& n1, const double& n2)
	{
		return n1 + n2;
	}
	Point operator()(const Point& n1, const Point& n2)
	{
		return n1 + n2;
	}
};

int main()
{
	Counter ct;

	ct.operator()(1); // ���� ����
	cout << ct(10) << endl; // () �����ε��� ���� �Լ������� ȣ�� --> Functor(function object)
	cout << ct(20) << endl;
	cout << ct(30) << endl;

	{
		Adder adder;

		cout << adder(1, 3) << endl;
		cout << adder(1.5, 3.7) << endl;
		cout << adder(Point(3,4), Point(7,9)) << endl; // �Լ��� ȣ�⹮������ �ӽð�ü ������ �����ϴ�
	}
	return 0;
}

/*
	homework (next week)
	�����̰��� �����
	������ �ϳ��� ���� +
	���� ������ġ
	���� ������ ���� +1
	���� ������ ����
	��������� �Ųٷ� ���� ����
*/