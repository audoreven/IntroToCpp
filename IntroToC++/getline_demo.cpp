// File Name: getline_Demo.cpp
// This program demonstrates using the getline function
// to read character data into a string object.
#include <iostream>
#include <string>
using namespace std;

int main_getline()
{
	string name;
	string city;

	cout << "Please enter your first and last names: ";
	//cin >> name;
	getline(cin, name);
	cout << "Enter the city you live in: ";
	getline(cin, city);

	cout << "Hello, " << name << endl;
	cout << "You live in " << city << endl;

	return 0;
}