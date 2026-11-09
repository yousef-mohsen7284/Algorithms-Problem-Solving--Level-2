#include<iostream>

using namespace std;

void FillArray(int arr[100], int& ArrayLength)
{
	ArrayLength = 6;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 30;
	arr[4] = 20;
	arr[5] = 10;
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

bool IsPalindromeArray(int arr[100], int ArrayLength)
{

	for (int i = 0;i < ArrayLength;i++)
	{

		if (arr[i] != arr[ArrayLength - 1 - i])
		{
			return false;
		}
	};

	return true;
}

int main()
{
	int arr[100], ArrayLength = 0;

	FillArray(arr, ArrayLength);

	cout << "\nArray Elements: \n";
	PrintArrayElements(arr, ArrayLength);

	if (IsPalindromeArray(arr, ArrayLength))
	{
		cout << "\nYes,Array Is Palindrome!\n";
	}
	else
	{
		cout << "\nNo,Array Is NOT Palindrome!\n";
	}

	return 0;
}