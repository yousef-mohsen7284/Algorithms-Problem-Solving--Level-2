#include<iostream>

using namespace std;


int ReadNumber()
{
	int Number = 0;

	cout << "\nPlease Enter a Number?";
	cin >> Number;

	return Number;

}


void AddArrayElement(int Number, int arr[100], int& ArrayLength)
{

	ArrayLength++;

	arr[ArrayLength - 1] = Number;
}

void InputUserNumbersInArray(int arr[100], int& ArrayLength)
{

	bool AddNumber = true;

	do
	{
		AddArrayElement(ReadNumber(), arr, ArrayLength);
		
		cout << "\nDo You Want To add More Numbers? [0]:NO,[1]:Yes?";
		cin >> AddNumber;

	} while (AddNumber);

}

void PrintArrayElements(int arr[100], int& ArrayLength)
{

	for (int i = 0;i < ArrayLength;i++)
	{

		cout << arr[i] << " ";

	}
}


int main()
{

	int arr[100];
	int ArrayLength = 0;

	InputUserNumbersInArray(arr, ArrayLength);

	cout << "\nArray Length: " << ArrayLength;
	cout << "\nArray Elements: ";
	PrintArrayElements(arr, ArrayLength);


	return 0;
}