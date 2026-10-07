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

int DigitFrequencyCount(int MainNumber, short int DigitToCheck)
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


int main()
{

	int MainNumber = ReadPositiveNumber("Please Enter the Main Number?\n");
	short int DigitToCheck = ReadPositiveNumber("Please Enter one Digit To Check?\n");

	cout << "\nDigit " << DigitToCheck << " Frequency is "
		<< DigitFrequencyCount(MainNumber, DigitToCheck) << " Time(s).\n";

	return 0;

}