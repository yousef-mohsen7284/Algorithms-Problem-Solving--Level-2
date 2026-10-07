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


int ReverseNumber(int Number)
{

	int Remainder = 0,Number2 = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;
		Number2 = Number2 * 10 + Remainder;
	}
	return Number2;
}



int main()
{

	int Number = ReadPositiveNumber("Please Enter a Positive Number?\n");
	cout << "\nReversed Number is:\n"
	<<ReverseNumber(Number);

	return 0;
}