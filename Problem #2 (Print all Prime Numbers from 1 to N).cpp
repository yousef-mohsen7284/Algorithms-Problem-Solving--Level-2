#include<iostream>
#include<string>

using namespace std;

enum enPrimeOrNot { Prime = 1, NotPrime = 2 };

int ReadPositiveNumber(string Message)
{

	int Number = 0;
	do
	{
		cout << Message;
		cin >> Number;
	} while (Number < 0);

	return Number;
}


enPrimeOrNot CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int Counter=2;Counter <= M;Counter++)
	{
		if (Number % Counter == 0)
			return enPrimeOrNot::NotPrime;
	}
	return enPrimeOrNot::Prime;
}


void PrintPrimeNumbersFrom1toN(int Number)
{
	cout << "\n";
	cout << "Prime Numbers From " << 1 << " to " << Number << " are :" << endl;
	
	for (int i = 1;i <= Number;i++)
	{

		if (CheckPrime(i) == enPrimeOrNot::Prime)
			cout << i << endl;
	}
}



int main()
{

	PrintPrimeNumbersFrom1toN(ReadPositiveNumber("Please Enter a Positive Number?\n"));


	return 0;
}