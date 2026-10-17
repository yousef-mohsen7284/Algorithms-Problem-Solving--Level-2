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


int DigitFrequencyCount(short DigitToCheck,int MainNumber)
{
	int DigitFrequency = 0, Remainder = 0;

	while (MainNumber > 0)
	{
		Remainder = MainNumber % 10;
		MainNumber = MainNumber / 10;

		if (Remainder == DigitToCheck)
		{
			DigitFrequency++;
		}
	}
	return DigitFrequency;
}


void PrintAllNumberDigitsFrequency(int Number)
{
	cout << endl;

	for (int i = 0;i <= 9;i++)
	{
		short DigitFrequency = 0;

	
		DigitFrequency = DigitFrequencyCount(i, Number);

		if (DigitFrequency > 0)
		{
			cout << "Digit " << i
				<< " Frequency is " << DigitFrequency << " Time(s).\n";
		}


	}
}


int main()
{

	int Number = ReadPositiveNumber("Please Enter a Positive Number?");

	PrintAllNumberDigitsFrequency(Number);

	return 0;
}