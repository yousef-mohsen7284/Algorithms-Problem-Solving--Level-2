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


void PrintNumberPattern(int Number)
{
	cout << "\n";

	for (int i = 1;i <= Number;i++)
	{
		for (int Counter = 1;Counter <= i;Counter++)
		{
			cout << i;
		}
		cout << "\n";
	}

}

int main()
{

	PrintNumberPattern(ReadPositiveNumber("Please Enter a Positive Number?"));

	return 0;

}