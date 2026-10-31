#include<iostream>
#include<string>
#include<cstdlib>

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

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

void FillArrayWithRandomNumbers(int arr[100], int ArrayLength)
{

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

void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int ArrayLength)
{

	for (int i = 0;i <= ArrayLength - 1;i++)
	{
		arrSum[i] = arr1[i] + arr2[i];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr1[100], arr2[100], arrSum[100];

	int ArrayLength = ReadPositiveNumber("Enter How Many Elements?");

	FillArrayWithRandomNumbers(arr1, ArrayLength);
	FillArrayWithRandomNumbers(arr2, ArrayLength);

	SumOf2Arrays(arr1, arr2, arrSum, ArrayLength);

	cout << "\nArray 1 Elements:\n";
	PrintArrayElements(arr1, ArrayLength);

	cout << "\nArray 2 Elements:\n";
	PrintArrayElements(arr2, ArrayLength);

	cout << "\nSum Of Array 1 and Array 2 Elements:\n";
	PrintArrayElements(arrSum, ArrayLength);

	return 0;
}