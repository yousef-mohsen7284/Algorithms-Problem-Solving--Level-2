#include<iostream>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}


bool IsPerfect(int Number)
{
	int Sum = 0;

	for (int i = 1;i < Number;i++)
	{
		if (Number % i == 0)
		{
			Sum += i;
		}
	}

	return (Number == Sum);
}


void PrintPerfectNumbersFrom1toN(int Number)
{

	cout << "\n";
	cout << "Perfect Numbers From " << 1 << " to " << Number;
	cout << " are : " << endl;

	for (int i = 1;i <= Number;i++)
	{
		if (IsPerfect(i))
		{
			cout << i << endl;
		}
	}

}


int main()
{

	PrintPerfectNumbersFrom1toN(ReadPositiveNumber("Please Enter a Positive Number?\n"));

	return 0;
}