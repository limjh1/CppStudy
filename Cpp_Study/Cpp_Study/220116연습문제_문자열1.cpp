#include <iostream>
using namespace std;

// 연습문제1

// 1) 문자열 길이를 출력하는 함수
int StrLen(char* str) 
{
	// str이라는 문자열의 길이를 반환
	int count = 0;
	while (str[count] != '\0')
	{
		count++;
	}

	return count;
}

// 2) 문자열 복사 함수


char* StrCpy(char* dest, char* src)
{
	//int i = 0;
	//while (src[i] != '\0')
	//{
	//	dest[i] = src[i];
	//	i++;
	//}
	//dest[i] = '\0';

	char* ret = dest; // 제일 먼저 값의 주소. (초기값 = 'H')

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;

		// *dest++ = *src++;
	}
	*dest = '\0';

	return ret;
}

// 3) 문자열을 덧붙이는 ㅎ마수
char* StrCat(char* dest, char* src)
{
	// 내 풀이
	/*int i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	int j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';*/

	//// 배열 풀이
	//int len = StrLen(dest);
	//int i = 0;

	//while (src[i] != '\0')
	//{
	//	dest[len + i] = src[i];
	//	i++;
	//}	
	//dest[len + i] = '\0';

	// 포인터 풀이
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return dest;
}

// 4) 두 문자열을 비교하는 함수
int StrCmp(char* a, char* b)
{
	int i = 0;
	
	while (a[i] != '\0' || b[i] != '\0')
	{
		if (a[i] > b[i])
			return 1;
		if (a[i] < b[i])
			return -1;
		i++;
	}

	return 0;
}


// 5) 문자열을 뒤집는 함수
void ReverseStr(char* str)
{
	// 내 풀이
	//char a[100];

	//StrCpy(a, str);
	//int i = 0;
	//while (a[i] != '\0')
	//{
	//	i++;
	//}
	//int j = 0;
	//for (int j = 0; j < StrLen(str); j++)
	//{
	//	i--;
	//	str[j] = a[i];		
	//}

	int len = StrLen(str);

	for (int i = 0; i < len / 2; i++)
	{
		int temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}

}



#pragma warning(disable: 4996)

int main()
{
	const int BUF_SIZE = 100;

	// [H][e][l][l][o][][][][][][][][][][][]...
	char a[BUF_SIZE] = "Hello";
	char b[BUF_SIZE];
	char c[BUF_SIZE] = "World";
	char d[BUF_SIZE] = "Hella";

	// strlen(a)
	// int len = StrLen(a);
	// cout << len;

	//StrCpy(b, a);	
	//cout << b << endl;
	//int len = StrLen(b);
	//cout << len;

	//cout << StrCat(a, c);

	//int value = StrCmp(a, d); // 왼쪽이 크면 1 오른쪽이면 -1 아예 같으면 0
	//cout << value << endl;

	ReverseStr(a);

	cout << a;

	return 0;
}