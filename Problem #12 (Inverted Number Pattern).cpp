#include<iostream>
#include<string>

using namespace std;

short ReadPositiveDigit(string Message)
{
	short Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

void PrintInvertedPattern(short Number)
{
	cout << "\n";

	for (int i = Number;i >= 1;i--)
	{

		for (int Counter = 1;Counter <= i;Counter++)
		{
			cout << i;
		}

		cout <<"\n";
	}
}



int main()
{
	PrintInvertedPattern(ReadPositiveDigit("Please Enter a Positive Digit?"));

	return 0;
}