#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

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


int SumNumbersInArray(int arr[100], int ArrayLength)
{
	int Sum = 0;

	for (int i = 0;i <= ArrayLength - 1;i++)
	{
		Sum += arr[i];
	}

	return Sum;
}


int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength;

	FillArrayWithRandomNumbers(arr,ArrayLength);


	cout << "\nArray Elements: ";
	PrintArrayElements(arr, ArrayLength);


	cout << "\nSum of All Numbers is: ";
	cout << SumNumbersInArray(arr, ArrayLength);
	cout << endl;


	return 0;
}