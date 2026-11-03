#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

enum enFoundOrNot { Found = 1, NotFound = 2 };

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

enFoundOrNot CheckArrayNumberFoundOrNot(int arr[100], int NumberToSearch, int ArrayLength)
{
	for (int i = 0;i < ArrayLength;i++)
	{
		if (NumberToSearch == arr[i])
		{
			return enFoundOrNot::Found;
		}

	}
}

int PositionOfNumber(int arr[100],int NumberToSearch,int ArrayLength)
{
	for (int i = 0;i < ArrayLength;i++)
	{
		if (NumberToSearch == arr[i])
		{
			return i;
		}

	}
}

int OrderOfNumber(int arr[100], int NumberToSearch, int ArrayLength)
{
	for (int i = 0;i < ArrayLength;i++)
	{
		if (NumberToSearch == arr[i])
		{
			return i + 1;
		}
	}
}

void NumberYouSearchFor(int arr[100], int NumberToSearch, int ArrayLength)
{
	
	cout << "\nNumber You Are Looking For is: " << NumberToSearch << "\n";

	if (CheckArrayNumberFoundOrNot(arr, NumberToSearch, ArrayLength) == enFoundOrNot::Found)
	{
		cout << "The Number Found At Position: " << PositionOfNumber(arr, NumberToSearch, ArrayLength);
		cout << "\nThe Number Found it's Order: " << OrderOfNumber(arr, NumberToSearch, ArrayLength);
	}
	else
	{
		cout << "The Number Is Not Found :-(";
	}

}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength;

	FillArrayWithRandomNumbers(arr, ArrayLength);

	cout << "\nArray 1 Elements: \n";
	PrintArrayElements(arr, ArrayLength);

	int NumberToSearch = ReadPositiveNumber("Please Enter a Number To Search For?");
	NumberYouSearchFor(arr, NumberToSearch, ArrayLength);


	return 0;
}
