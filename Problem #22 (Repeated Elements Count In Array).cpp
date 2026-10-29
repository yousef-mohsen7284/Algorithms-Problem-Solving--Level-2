#include<iostream>
#include<string>

using namespace std;

int ReadPositiveNumber(string Message)
{

	int Number = 0;
	do
	{
		cout << Message;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}


void ReadArrayElements(int arr[100], int& ArrayLength)
{

	cout << "Enter Number Of Elements?\n";
	cin >> ArrayLength;

	cout << "\nEnter Array Elements: \n";
		
	for (int i = 0;i <= ArrayLength - 1;i++)
	{
		cout << "Element[" << i + 1 << "]: ";
		cin >> arr[i];
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

int TimesRepeated(int Number, int arr[100], int ArrayLength)
{
	int Count = 0;

	for (int i = 0;i <= ArrayLength - 1;i++)
	{
		if (arr[i] == Number)
		{
			Count++;
		}
	}
	return Count;
}


int main()
{
	int arr[100], ArrayLength, NumberToCheck;

	ReadArrayElements(arr, ArrayLength);

	NumberToCheck=ReadPositiveNumber("Enter Number You Want To Check:");

	cout << "\nOriginal array: ";
	PrintArrayElements(arr, ArrayLength);

	cout << "\n" << NumberToCheck;
	cout << " Is Repeated " << TimesRepeated(NumberToCheck, arr, ArrayLength);
	cout << " Time(s).\n";

	return 0;
}