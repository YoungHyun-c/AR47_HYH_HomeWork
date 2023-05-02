﻿// 087_UnionAndDataPadding.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//typedef union _MyClass
//{} MyClass;


//typedef union _LARGE_INTEGER {
//	struct {
//		int LowPart;
//		int HighPart;
//	};
//	struct {
//		DWORD LowPart;
//		LONG HighPart;
//	}u;
//	LONGLONG QuadPart;
//}LARGE_INTEGER;

union LARGE_INTEGER
{
	// 곧바로 변수화 시켜서 내부에서 사용하는 문법.
	struct {
		int LowPart;
		int HighPart;
	}u;
	__int64 QuadPart;
};

class Player
{
public:
	struct MyClass
	{
		int LowPart;
		int HighPart;
	};
	MyClass u;
	__int64 QuadPart;
};

class tPlayer
{
public:
	// 300번지부터 304
	int LowPart;
	// 304번지부터 308
	int HightPart;
	// 308번지부터 316
	__int64 QuadPart;
};

// 메모리의 구성을 변수가 존재한다면
union UPlayer
{
public:
	// 내부에 의미있는 변수가 있다면
	// 그 중 가장 큰 변수를 중심으로 같은 위치에 다른 이름을 준다.
	// [][][][]

	// 300번지 308
	__int64 C;
	// 0 을 붙이면 A,B,C의 값이 다 똑같고, 0을 안붙이면 A,B만 같고, C는 다름.
	// 300번지 304
	int A;
	// 300번지 304
	int B;
};

int main()
{

	{
		// 200번지에 만들어졌다고 치면.
		tPlayer NewPlayer;

		// 200번지 부터 204번지까지 사용
		NewPlayer.LowPart = 1;

		// 204번지 부터 208번지 까지 사용
		NewPlayer.HightPart = 1;

		// 208번지 부터 216번지 까지 사용.
		NewPlayer.QuadPart;

		int Value = sizeof(NewPlayer);

		int a = 0;
	}

	{
		UPlayer NewPlayer;

		// 00000001 00000000 00000000 00000000 00000000 00000000 00000000 00000000

		// 300번지 304번지를 사용하곘다.
		NewPlayer.A = 20;

		// 300번지 304번지를 사용하겠다.
		NewPlayer.B;

		NewPlayer.C;

		int Value = sizeof(UPlayer);

		int a = 0;
	}
}