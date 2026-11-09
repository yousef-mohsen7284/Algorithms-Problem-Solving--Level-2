#include<iostream>
#include<cmath>

using namespace std;

float ReadNumber()
{
	float Number = 0;
	cout << "Please Enter a Number? ";
	cin >> Number;
	return Number;
}

int MyFloor(float Number)
{
	if (Number > 0)
		return int(Number);
	else
		return int(Number) - 1;
}

int main()
{

	float Number = ReadNumber();

	cout << "\nMy Floor Result : " << MyFloor(Number) << endl;
	cout << "C++ Floor Result : " << floor(Number) << endl;

	return 0;
}