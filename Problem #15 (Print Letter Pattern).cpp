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


void PrintLetterPattern(int Number)
{

	cout << "\n";


	for (int i = 65;i <= 65 + Number - 1;i++)
	{

		for (int Counter = 1;Counter <= i - 65 + 1;Counter++)
		{
			cout << char(i);
		}

		cout << "\n";
	}


}


int main()
{

	PrintLetterPattern(ReadPositiveNumber("Please Enter a Positive Number?"));


	return 0;

}