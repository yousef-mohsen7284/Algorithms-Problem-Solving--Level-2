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

void CopyArray(int arrSource[100], int arrDestination[100], int ArrayLength)
{

	for (int i = 0;i <= ArrayLength - 1;i++)

	{
		arrDestination[i] = arrSource[i];
	}

}

int main()
{

	srand((unsigned)time(NULL));

	int arr[100], ArrayLength;

	FillArrayWithRandomNumbers(arr, ArrayLength);

	int arr2[100];
	CopyArray(arr, arr2, ArrayLength);

	cout << "\nArray 1 Elements: \n";
	PrintArrayElements(arr, ArrayLength);

	cout << "\nArray 2 Elements after Copy: \n";
	PrintArrayElements(arr2, ArrayLength);


	cout << endl;

	return 0;



}

