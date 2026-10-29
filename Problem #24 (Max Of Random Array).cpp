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

int MaxNumberInArray(int arr[100], int& ArrayLength)
{
	int MaxNumber = 0;

	for (int i = 0;i <= ArrayLength - 1;i++)
	{
		if (arr[i] > MaxNumber)
		{
			MaxNumber = arr[i];
		}
	}
	return MaxNumber;
}

int main()
{

	srand((unsigned)time(NULL));

	int arr[100], ArrayLength;

	FillArrayWithRandomNumbers(arr, ArrayLength);


	cout << "\nArray Elements: ";
	PrintArrayElements(arr, ArrayLength);


	cout << "\nMax Number is : ";
	cout << MaxNumberInArray(arr, ArrayLength);
	cout << endl;


	return 0;
}