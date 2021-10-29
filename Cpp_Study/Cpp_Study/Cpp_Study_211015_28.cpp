#include <iostream>
using namespace std;

#pragma region 분기문
/*
int main()
{
	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;

	int input = ROCK;

	switch (input)
	{
	case ROCK:

		break;
	case PAPER:

		break;
	case SCISSORS:

		break;
	default:
		break;
	}
}
*/
#pragma endregion

#pragma region 반복문
//int main()
//{
//	//int count = 0;
//	// 
//	//while (count < 5)
//	//{
//	//	cout << "Hello World" << endl;
//	//	++count;
//	//}
//
//	/*do
//	{
//		cout << "Hello World" << endl;
//		++count;
//	} while (count < 5);*/
//
//	/*for (int count = 0; count < 5; count++)
//	{
//		cout << "Hello World" << endl;		
//	}*/
//
//	// break continue
//
//	//int round = 1;
//	//int hp = 100;
//	//int damage = 10;
//
//	//while (true)
//	//{
//	//	hp -= damage;
//	//	if (hp < 0) hp = 0;
//
//	//	cout << "Round " << round << " 몬스터 체력 " << hp << endl;
//
//	//	if (hp == 0)
//	//	{
//	//		cout << "몬스터 처치" << endl;
//	//		break;
//	//	}
//
//	//	if (round == 5)
//	//	{
//	//		cout << "제한 라운드 종료" << endl;
//	//		break;
//	//	}
//
//	//	round++;
//	//}
//
//	// 1~10 홀수
//
//	for (int i = 1; i <= 10; i++)
//	{
//		bool isEven = ((i % 2) == 0);
//		
//		if (isEven) continue;
//				
//		cout << i << endl;
//	}
//}
#pragma endregion

#pragma region 별찍기, 구구단
//int main()
//{
//	// 정수 입력시 N*N개의 별을 찍어라
//	int input;
//	cin >> input;
//
//	//별 찍기
//	for (int i = 0; i < input; i++)
//	{
//		for (int j = input; j > i; j--)
//		{
//			cout << "*";
//		}
//		cout << endl;
//	}	
//
//	// 구구단
//	for (int i = 2; i < 10; i++)
//	{
//		for (int j = 1; j < 10; j++)
//		{
//			cout << i << "*" << j << "=" << i * j << endl;
//		}
//	}
//}
#pragma endregion

#pragma region 가위바위보

const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

// 숫자 지정안하면 첫 값은 0부터 시작 ++1
enum ENUM_SRP // 이름 지어주기
{
	ENUM_SCISSORS = 1, // 지정하면 그 값부터 ++1
	ENUM_ROCK,
	ENUM_PAPER
};

// #이 붙은 건 -> 전처리 지시문
// 빌드
// 1) 전처리 2) 컴파일 3) 링크 순서
#define DEFINE_SCISSORS 1
#define DEFINE_TEST cout << "HELLO" << endl;


int main()
{
	DEFINE_TEST;


	int input = 0;
	int win = 0;
	int count = 0;


	while (true) {

		srand(time(NULL)); // 시드 설정

		int value = (rand() % 3) + 1;

		cout << ">";;

		if (count == 0) cout << "승률 x" << endl;
		else {
			int percentage = ((float)win / count) * 100;
			cout << "승률 " << percentage << endl;
		}

		cin >> input;

		if (input == SCISSORS) 
		{
			if (value == SCISSORS) cout << "비겼다" << endl;
			else if (value == ROCK) 
			{ 
				cout << "컴 승" << endl; 				
				count++;
			}
			else if (value == PAPER)
			{
				cout << "님 승" << endl;				
				win++;				
				count++;
			}
		}
		else if (input == ROCK) 
		{ 
			if (value == ROCK) cout << "비겼다" << endl;
			else if (value == PAPER)
			{
				cout << "컴 승" << endl;
				count++;
			}
			else if (value == SCISSORS)
			{
				cout << "님 승" << endl;
				win++;
				count++;
			}
		}
		else if (input == PAPER)
		{
			if (value == PAPER) cout << "비겼다" << endl;
			else if (value == SCISSORS)
			{
				cout << "컴 승" << endl;
				count++;
			}
			else if (value == ROCK)
			{
				cout << "님 승" << endl;
				win++;
				count++;
			}
		}
		else break;			
	}
}
#pragma endregion
