#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}


bool IsPerfectNumber(int Number)
{
	int Sum = 0;

	for (int i = 1;i < Number;i++)
	{
		if (Number % i == 0)
		{
			Sum += i;
		}
	}

	return(Sum == Number);
}



void PrintPerfectionStatus(int Number)
{
	if (IsPerfectNumber(Number))
	{
		cout << Number << " Is a Perfect Number!\n";
	}
	else
	cout << Number << " Is NOT a Perfect Number!\n";
}

int main()
{

	PrintPerfectionStatus(ReadPositiveNumber("Please Enter a Positive Number?\n"));

	return 0;


}