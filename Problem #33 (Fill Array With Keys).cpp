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

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

char GetRandomCharacter(enCharType CharType)
{

	switch (CharType)
	{
	case enCharType::SmallLetter:
	{
		return char(RandomNumber(97, 122));

		break;
	}
	case enCharType::CapitalLetter:
	{

		return char(RandomNumber(65, 90));
		break;
	}
	case enCharType::SpecialCharacter:
	{
		return char(RandomNumber(33, 47));
		break;
	}
	case enCharType::Digit:
	{
		return char(RandomNumber(48, 57));
		break;
	}
	}


}

string GenerateWord(enCharType CharType, short Length)
{

	string Word = "";

	for (int i = 1;i <= Length;i++)
	{
		Word = Word + GetRandomCharacter(CapitalLetter);
	}

	return Word;
}

string GenerateKey()
{

	string Key = "";

	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";

	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";

	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";

	Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

	return Key;
}

void FillArrayWithKeys(string arr[100], int ArrayLength)
{

	for (int i = 0;i < ArrayLength;i++)
	{
		arr[i] = GenerateKey();
	}

}

void PrintStringArray(string arr[100], int ArrayLength)
{

	cout << "\nArray Elements: \n\n\n";

	for (int i = 0;i < ArrayLength;i++)
	{
		cout << "Array[" << i << "]: ";
		cout << arr[i] << "\n";
	}

	cout << "\n";
}


int main()
{
	srand((unsigned)time(NULL));

	string arr[100];
	int ArrayLength = 0;

	ArrayLength = ReadPositiveNumber("Enter How Many Keys? ");
	
	FillArrayWithKeys(arr, ArrayLength);

	PrintStringArray(arr, ArrayLength);

	return 0;
}