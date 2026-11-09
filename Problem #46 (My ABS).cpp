#include<iostream>
#include<cmath>

using namespace std;

float ReadNumber()
{
	int Number = 0;
	cout << "Please Enter a Number? ";
	cin >> Number;
	return Number;
}

float MyABS(float Number)
{
	if (Number >= 0)
	{
		return Number;
	}
	else
	{
		return Number * -1;
	}
}

int main()
{

	float Number = ReadNumber();

	cout << "My abs Result : " << MyABS(Number) << endl;
	cout << "C++ abs Result: " << abs(Number) << endl;

	return 0;
}