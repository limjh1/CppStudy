#include <iostream>
using namespace std;

// 로또 번호 생성기

//void Swap(int *a, int *b)
//{
//	int temp = 0;
//
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void SortbyMe(int numbers[], int count)
{
	for (int j = 0; j < count; j++)
	{
		for (int i = 0; i < count - 1; i++)
		{
			if (numbers[i] > numbers[i + 1])
			{
				Swap(numbers[i], numbers[i + 1]);
			}
		}
	}
}

void Sort(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		// i 번째 값이 제일 좋은 후보라고 가정
		int best = i;

		// 다른 후보와 비교를 통해 제일 좋은 후보를 찾음
		for (int j = i+1; j < count; j++)
		{
			if (numbers[j] < numbers[best])
				best = j;
		}

		// 제일 좋은 후보와 교체하는 과정
		if (i != best)
			Swap(numbers[i], numbers[best]);
	}
}

void ChooseLottobyMe(int numbers[])
{
	// 랜덤으로 1~45 사이의 숫자 6개를 골라라. (단, 중복이 없어야 함)

	bool a = false;

	srand((unsigned)time(0));

	int random = 0;

	for (int i = 0; i < 6; i++)
	{
		random = rand() % 45 + 1;		

		for (int j = 0; j < 6; j++)
		{
			if (numbers[j] == random)
			{
				a = false;
				break;
			}
				
			a = true;
			
		}

		if (a == true)
			numbers[i] = random;
		
	}

	Sort(numbers, 6);

	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << endl;
	}		
}

void ChooseLotto(int numbers[])
{
	srand((unsigned)time(0));

	int count = 0;
	while (count != 6)
	{
		int randValue = rand() % 45 + 1;

		// 이미 찾은 값인지?
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				// 이미 찾은 값
				found = true;
				break;
			}
		}

		// 못 찾았으면 추가
		if (found == false)
		{
			numbers[count] = randValue;
			count++;
		}
	}

	Sort(numbers, 6);
}

int main()
{
	// 1) Swap 함수 만들기
	int a = 1;
	int b = 2;
	//Swap(&a, &b);
	Swap(a, b);

	// 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
	int numbers[6] = { 1, 42, 3, 15, 5, 6 };

	int size1 = sizeof(numbers); // 6*4=24
	int size2 = sizeof(int); // 4

	Sort(numbers, sizeof(numbers) / sizeof(int)); // sizeof(numbers) / sizeof(int) == 6
		
	// 3) 로또 번호 생성기
	ChooseLotto(numbers);

	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << endl;
	}

	return 0;
}