#include <iostream>
using namespace std;

// �ζ� ��ȣ ������

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
		// i ��° ���� ���� ���� �ĺ���� ����
		int best = i;

		// �ٸ� �ĺ��� �񱳸� ���� ���� ���� �ĺ��� ã��
		for (int j = i+1; j < count; j++)
		{
			if (numbers[j] < numbers[best])
				best = j;
		}

		// ���� ���� �ĺ��� ��ü�ϴ� ����
		if (i != best)
			Swap(numbers[i], numbers[best]);
	}
}

void ChooseLottobyMe(int numbers[])
{
	// �������� 1~45 ������ ���� 6���� ����. (��, �ߺ��� ����� ��)

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

		// �̹� ã�� ������?
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				// �̹� ã�� ��
				found = true;
				break;
			}
		}

		// �� ã������ �߰�
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
	// 1) Swap �Լ� �����
	int a = 1;
	int b = 2;
	//Swap(&a, &b);
	Swap(a, b);

	// 2) ���� �Լ� ����� (���� ���ڰ� ���� ������ ����)
	int numbers[6] = { 1, 42, 3, 15, 5, 6 };

	int size1 = sizeof(numbers); // 6*4=24
	int size2 = sizeof(int); // 4

	Sort(numbers, sizeof(numbers) / sizeof(int)); // sizeof(numbers) / sizeof(int) == 6
		
	// 3) �ζ� ��ȣ ������
	ChooseLotto(numbers);

	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << endl;
	}

	return 0;
}