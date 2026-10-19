#include<iostream>
#include<string>

using namespace std;

string ReadPassword()
{

	string Password;
	cout << "Please Enter A 3-Letter Password(All Capital)?\n";
	cin >> Password;

	return Password;
}

bool GuessPassword(string RealPassword)
{
	int Counter = 0;
	string word = "";


	for (int i = 65;i <= 90;i++)
	{

		for (int j = 65;j <= 90;j++)
		{
			for (int k = 65;k <= 90;k++)
			{
				Counter++;

				word = word + char(i);
				word = word + char(j);
				word = word + char(k);

				cout << "Trial[" << Counter << "]: " << word << endl;

				if (word == RealPassword)
				{
					cout << "\n";
					cout << "Password is: " << RealPassword << endl;
					cout << "Found after " << Counter << " Trial(s).\n";
					return true;
				}
				word = "";
			}
		}

	}
	return false;
}



int main()
{
	GuessPassword(ReadPassword());

	return 0;
}
