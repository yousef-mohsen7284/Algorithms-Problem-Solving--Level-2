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

void CopyOddNumbers(int arrSource[100], int arrDestination[100], int ArrayLength, int& Array2Length)
{

	for (int i = 0;i < ArrayLength;i++)
	{
		if (arrSource[i] % 2 != 0)
		{
			AddArrayElement(arrSource[i], arrDestination, Array2Length);
		}
	}
}

int main()
{

	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = 0, Array2Length = 0;

	FillArrayWithRandomNumbers(arr, ArrayLength);

	int arr2[100];
	CopyOddNumbers(arr, arr2, ArrayLength, Array2Length);

	cout << "\nArray 1 Elements: \n";
	PrintArrayElements(arr, ArrayLength);

	cout << "\nArray 2 Odd Numbers: \n";
	PrintArrayElements(arr2, Array2Length);


	return 0;
}