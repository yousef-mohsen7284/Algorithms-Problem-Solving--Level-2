#include<iostream>
#include<string>

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



void PrintInvertedLetterPattern(int Number)
{

	cout << "\n"; 

	for (int i = 65 + Number - 1;i >= 65;i--)
	{
		
		for (int Counter = 1;Counter <= Number - (65 + Number - 1 - i);Counter++)
		{
			cout << char(i);

		}
		cout << "\n";
	}
}


int main()
{

	PrintInvertedLetterPattern(ReadPositiveNumber("Please Enter a Positive Number?"));

	return 0;
}