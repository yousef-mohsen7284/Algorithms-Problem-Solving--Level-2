#include<iostream>
#include<string>

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


int SumOfDigits(int Number)
{

	int Remainder = 0;
	int Sum = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		Sum = Sum + Remainder;
	}

	return Sum;
}


int main()
{

	int Number = ReadPositiveNumber("Please Enter a Positive Number?\n");
	cout << "\nSum of Number Digits = " << SumOfDigits(Number) << endl;

	return 0;


}

