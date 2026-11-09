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

float MySqrt(float Number)
{
	return pow(Number, 0.5);
}

int main()
{
	float Number = ReadNumber();
	cout << "\nMy Sqrt Result : " << MySqrt(Number) << endl;
	cout << "C++ Sqrt Result : " << sqrt(Number) << endl;

	return 0;
}