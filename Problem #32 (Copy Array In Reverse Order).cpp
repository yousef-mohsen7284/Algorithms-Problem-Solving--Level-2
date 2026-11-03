#include<iostream>
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

void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int ArrayLength)
{

	for (int i = 0;i < ArrayLength;i++)
	{
		arrDestination[i] = arrSource[ArrayLength - 1 - i];
	}

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

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength;

	FillArrayWithRandomNumbers(arr, ArrayLength);

	int arr2[100];
	CopyArrayInReverseOrder(arr, arr2, ArrayLength);

	cout << "\nArray 1 Elements: \n";
	PrintArrayElements(arr, ArrayLength);

	cout << "\nArray 2 Elements After Copy: \n";
	PrintArrayElements(arr2, ArrayLength);

	return 0;
}