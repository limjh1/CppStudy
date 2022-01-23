//Baekjoon 2753

#include <iostream>
using namespace std;

int year = 0;

int f_year()
{
	if (year % 4 == 0)
	{
		if (year % 100 != 0 || year % 400 == 0)
		{
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

int main()
{	
	cin >> year;
	cout << f_year() << endl;	

	return 0;
} 
