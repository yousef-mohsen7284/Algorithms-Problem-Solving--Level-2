#include<iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

int ReverseNumber(int Number)
{
	int Number2 = 0, Remainder = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number = Number / 10;

		Number2 = Number2 * 10 + Remainder;
	}
	
	return Number2;
}

bool IsPalindrome(int Number)
{
	return Number == ReverseNumber(Number);
}

int main()
{

	if (IsPalindrome(ReadPositiveNumber("Please Enter a Positive Number?")))
		cout << "\nYes,it's a Palindrome Number!\n";
	else
		cout << "\nNo,it's Not a Palindrome Number!\n";


	return 0;
}