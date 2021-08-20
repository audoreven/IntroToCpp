#include <iostream>
using namespace std;

int main_bool()
{
	bool discrete_state;
	discrete_state = 0;
	cout << "discrete_state (0) = " << discrete_state << endl;

	discrete_state = 1;
	cout << "discrete_state (1) = " << discrete_state << endl;

	discrete_state = 88;
	cout << "discrete_state (88) = " << discrete_state << endl;

	discrete_state = -88;
	cout << "discrete_state (-88) = " << discrete_state << endl;

	discrete_state = false;
	cout << "discrete_state (false) = " << discrete_state << endl;

	discrete_state = true;
	cout << "discrete_state (true) = " << discrete_state << endl;

	cout << "the integer value of true is " << true << endl;
	cout << "the integer value of false is " << false << endl;
	return 0;
}