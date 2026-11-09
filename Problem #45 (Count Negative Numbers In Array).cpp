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

		arr[i] = RandomNumber(-100, 100);
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

int CountNegativeNumbersInArray(int arr[100], int ArrayLength)
{
	int Counter = 0;

	for (int i = 0;i < ArrayLength;i++)
	{
		if (arr[i] < 0)
		{
			Counter++;
		}
	}

	return Counter;
}


int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength = 0;

	FillArrayWithRandomNumbers(arr, ArrayLength);

	cout << "\nArray Elements: ";
	PrintArrayElements(arr, ArrayLength);

	cout << "\nNegative Numbers Count Is: " << CountNegativeNumbersInArray(arr, ArrayLength) << endl;

	
	return 0;
}