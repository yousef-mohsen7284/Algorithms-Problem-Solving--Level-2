#include<iostream>
#include<cstdlib>

using namespace std;

enum enPrimeOrNot { Prime = 1, NotPrime = 2 };

enPrimeOrNot CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int Counter = 2;Counter <= M;Counter++)
	{
		if (Number % Counter == 0)
			return enPrimeOrNot::NotPrime;
	}
	return enPrimeOrNot::Prime;
}

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& ArrayLength)
{

	cout << "Enter Number Of Elements?\n";
	cin >> ArrayLength;

	for (int i = 0;i <= ArrayLength - 1;i++)
	{

		arr[i] = RandomNumber(0, 100);
	}

	cout << "\n";
}

void PrintArrayElements(int arr[100], int ArrayLength)
{

	for (int i = 0;i <= ArrayLength - 1;i++)
	{
		cout << arr[i];

		cout << " ";
	}

	cout << "\n";
}

void AddArrayElement(int Number, int arr[100], int& ArrayLength)
{

	ArrayLength++;

	arr[ArrayLength - 1] = Number;
}

void CopyPrimeNumbersArray(int arrSource[100], int arrDestination[100], int ArrayLength, int& Array2Length)
{

	for (int i = 0;i < ArrayLength;i++)
	{
		if (CheckPrime(arrSource[i]) == enPrimeOrNot::Prime)
		{
			AddArrayElement(arrSource[i], arrDestination, Array2Length);
		}
	}

}


int main()
{
	
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = 0,Array2Length = 0;

	FillArrayWithRandomNumbers(arr, ArrayLength);

	int arr2[100];

	CopyPrimeNumbersArray(arr, arr2, ArrayLength, Array2Length);

	cout << "\nArray 1 Elements: \n";
	PrintArrayElements(arr, ArrayLength);

	cout << "\nArray 2 Prime Numbers: \n";
	PrintArrayElements(arr2, Array2Length);


	return 0;
}