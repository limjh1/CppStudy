#include <iostream>
using namespace std;

#pragma region �б⹮
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

#pragma region �ݺ���
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
//	//	cout << "Round " << round << " ���� ü�� " << hp << endl;
//
//	//	if (hp == 0)
//	//	{
//	//		cout << "���� óġ" << endl;
//	//		break;
//	//	}
//
//	//	if (round == 5)
//	//	{
//	//		cout << "���� ���� ����" << endl;
//	//		break;
//	//	}
//
//	//	round++;
//	//}
//
//	// 1~10 Ȧ��
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

#pragma region �����, ������
//int main()
//{
//	// ���� �Է½� N*N���� ���� ����
//	int input;
//	cin >> input;
//
//	//�� ���
//	for (int i = 0; i < input; i++)
//	{
//		for (int j = input; j > i; j--)
//		{
//			cout << "*";
//		}
//		cout << endl;
//	}	
//
//	// ������
//	for (int i = 2; i < 10; i++)
//	{
//		for (int j = 1; j < 10; j++)
//		{
//			cout << i << "*" << j << "=" << i * j << endl;
//		}
//	}
//}
#pragma endregion

#pragma region ����������

const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

// ���� �������ϸ� ù ���� 0���� ���� ++1
enum ENUM_SRP // �̸� �����ֱ�
{
	ENUM_SCISSORS = 1, // �����ϸ� �� ������ ++1
	ENUM_ROCK,
	ENUM_PAPER
};

// #�� ���� �� -> ��ó�� ���ù�
// ����
// 1) ��ó�� 2) ������ 3) ��ũ ����
#define DEFINE_SCISSORS 1
#define DEFINE_TEST cout << "HELLO" << endl;


int main()
{
	DEFINE_TEST;


	int input = 0;
	int win = 0;
	int count = 0;


	while (true) {

		srand(time(NULL)); // �õ� ����

		int value = (rand() % 3) + 1;

		cout << ">";;

		if (count == 0) cout << "�·� x" << endl;
		else {
			int percentage = ((float)win / count) * 100;
			cout << "�·� " << percentage << endl;
		}

		cin >> input;

		if (input == SCISSORS) 
		{
			if (value == SCISSORS) cout << "����" << endl;
			else if (value == ROCK) 
			{ 
				cout << "�� ��" << endl; 				
				count++;
			}
			else if (value == PAPER)
			{
				cout << "�� ��" << endl;				
				win++;				
				count++;
			}
		}
		else if (input == ROCK) 
		{ 
			if (value == ROCK) cout << "����" << endl;
			else if (value == PAPER)
			{
				cout << "�� ��" << endl;
				count++;
			}
			else if (value == SCISSORS)
			{
				cout << "�� ��" << endl;
				win++;
				count++;
			}
		}
		else if (input == PAPER)
		{
			if (value == PAPER) cout << "����" << endl;
			else if (value == SCISSORS)
			{
				cout << "�� ��" << endl;
				count++;
			}
			else if (value == ROCK)
			{
				cout << "�� ��" << endl;
				win++;
				count++;
			}
		}
		else break;			
	}
}
#pragma endregion
