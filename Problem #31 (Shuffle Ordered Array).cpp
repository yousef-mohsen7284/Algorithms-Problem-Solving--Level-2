#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

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

void PrintArrayElements(int arr[100], int ArrayLength)
{

	for (int i = 0;i <= ArrayLength - 1;i++)
	{
		cout << arr[i];

		cout << " ";
	}

	cout << "\n";
}

void Swap(int& A, int& B) {

	int Temp;
	Temp = A;
	A = B;
	B = Temp;
}

void FillArrayFrom1ToN(int arr[100], int ArrayLength)
{

	for (int i = 0;i < ArrayLength;i++)
	{
		arr[i] = i + 1;
	}
}

void ShuffleArray(int arr[100], int ArrayLength)
{

	for (int i = 0;i < ArrayLength;i++)
	{
		Swap(arr[RandomNumber(1, ArrayLength) - 1], arr[RandomNumber(1, ArrayLength)-1] );
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100];
	int ArrayLength = ReadPositiveNumber("Enter How Many Elements: ");

	FillArrayFrom1ToN(arr, ArrayLength);
	
	cout << "\nArray Elements Before Shuffle: \n";
	PrintArrayElements(arr, ArrayLength);

	ShuffleArray(arr, ArrayLength);

	cout << "\nArray Elements After Shuffle: \n";
	PrintArrayElements(arr, ArrayLength);

	return 0;
}