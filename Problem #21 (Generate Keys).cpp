#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };


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
	
	Key=Key+ GenerateWord(enCharType::CapitalLetter, 4) + "-";

   Key=Key+ GenerateWord(enCharType::CapitalLetter, 4) + "-";

   Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

   return Key;
}


void GenerateKeys(short KeysNumber)
{

	for (int i = 1;i <= KeysNumber;i++)
	{
		cout << "Key[" << i << "]: " << GenerateKey() << endl;
	}
}



int main()
{
	srand((unsigned)time(NULL));

	GenerateKeys(ReadPositiveNumber("Please Enter Number Of Keys You Want to Generate?"));

	return 0;
}