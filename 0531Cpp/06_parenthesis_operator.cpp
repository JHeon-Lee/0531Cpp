#include <iostream>

using namespace std;

// 괄호연산자() 오버로딩 - 객체를 함수처럼 사용하고 싶을 때

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

	ct.operator()(1); // 원래 형식
	cout << ct(10) << endl; // () 오버로딩을 통한 함수형태의 호출 --> Functor(function object)
	cout << ct(20) << endl;
	cout << ct(30) << endl;

	{
		Adder adder;

		cout << adder(1, 3) << endl;
		cout << adder(1.5, 3.7) << endl;
		cout << adder(Point(3,4), Point(7,9)) << endl; // 함수의 호출문에서도 임시객체 생성이 가능하다
	}
	return 0;
}

/*
	homework (next week)
	지렁이게임 만들기
	움직임 하나당 점수 +
	먹이 랜덤위치
	먹이 먹으면 길이 +1
	벽에 닿으면 실패
	진행방향의 거꾸로 가면 실패
*/