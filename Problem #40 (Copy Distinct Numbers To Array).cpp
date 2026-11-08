#include<iostream>

using namespace std;

void FillArray(int arr[100], int& ArrayLength)
{
	ArrayLength = 10;

	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[5] = 70;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;
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

short FindNumberPositionInArray(int arr[100], int Number, int ArrayLength)
{
	for (int i = 0;i < ArrayLength;i++)
	{
		if (Number == arr[i])
		{
			return i;
		}
	}

	return -1;
}

bool IsNumberInArray(int arr[100], int Number, int ArrayLength)
{
	return FindNumberPositionInArray(arr, Number, ArrayLength) != -1;
}

void AddArrayElement(int Number, int arr[100], int& ArrayLength)
{

	ArrayLength++;

	arr[ArrayLength - 1] = Number;
}

void CopyDistinctNumbersInArray(int arrSource[100], int arrDestination[100], int SourceLength, int &DestinationLength)
{

	for (int i = 0;i < SourceLength;i++)
	{
		if (!IsNumberInArray(arrDestination,arrSource[i], SourceLength))
		{
			AddArrayElement(arrSource[i], arrDestination, DestinationLength);
		}
	}

}


int main()
{

	int arrSource[100], SourceLength = 0, arrDestination[100], DestinationLength = 0;

	FillArray(arrSource, SourceLength);
	
	cout << "\nArray 1 Elements: \n";
	PrintArrayElements(arrSource, SourceLength);

	CopyDistinctNumbersInArray(arrSource, arrDestination, SourceLength, DestinationLength);
	
	cout << "\nArray 2 Distinct Numbers: \n";
	PrintArrayElements(arrDestination, DestinationLength);


	return 0;
}
