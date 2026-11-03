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

int ReadNumber() {

	int Number = 0;
	cout << "\nPlease Enter a Number To Search For? \n";
	cin >> Number;

	return Number;
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
	return FindNumberPositionInArray(arr, Number, ArrayLength) !=-1;
}

int main()
{
	srand((unsigned)time(NULL));

	int arr[100], ArrayLength;

	FillArrayWithRandomNumbers(arr, ArrayLength);

	cout << "Array Elements: \n";
	PrintArrayElements(arr, ArrayLength);

	int Number = ReadNumber();
	cout << "\nNumber You Are Looking for is: " << Number << endl;


	short NumberPosition = FindNumberPositionInArray(arr, Number, ArrayLength);

	if (!IsNumberInArray(arr, Number, ArrayLength))
	{

		cout << "No,The Number Is Not Found :-(\n";
		
	}
	else
	{
		cout << "Yes,The Number Is Found :-)\n";

	}
	return 0;
}