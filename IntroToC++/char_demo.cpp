#include <iostream>
using namespace std;

int main_char()
{
	char my_char, first_char;

	cout << "Welcome to the char demo program!" << endl << endl << endl;

	cout << "Enter a character: ";
	cin >> my_char;
	first_char = my_char;
	cout << "ASCII code for " << first_char << " is: " << int(first_char) << endl << endl;

	my_char = my_char + 2;
	cout << "ASCII code for " << first_char << "+2 is: " << int(my_char) << endl << endl;

	my_char = '1';
	cout << "The character(display) for the literal '1'(ASCII) is: " << my_char << endl << endl;
	cout << "ASCII code for " << my_char << " is: " << int(my_char) << endl << endl;

	my_char = 'a';
	cout << "The character(display) for the literal 'a' is: " << my_char << endl << endl;

	my_char = 67;
	cout << "The character(display) for 67(ASCII code) is: " << my_char << endl << endl;

	cout << endl << endl << endl;
	cout << "Non-visible(special) character example:" << endl;
	cout << "--------------------------------------" << endl << endl;

	// set it to the escape sequence - '\n'
	my_char = '\n';
	cout << "The character(display) for the literal '\\n' is: " << my_char; // no endl here
	cout << "<--- new line" << endl << endl;

	// set it to the escape sequence - '\n' by using the code directly
	my_char = 10;
	cout << "The character(display) for 10(ASCII code for \\n) is: " << my_char; // no endl here
	cout << "<--- new line" << endl << endl;


	cout << endl << endl << endl;
	cout << "Not-for-display character example:" << endl;
	cout << "---------------------------------" << endl << endl;
	// set it to BEL, twice
	my_char = 7;
	cout << "The character(display) for 7(ASCII code for BEL) is: " << my_char << endl << endl;
	my_char = 7;
	cout << "The character(display) for 7(ASCII code for BEL) is: " << my_char << endl << endl;

	cout << endl << endl;
	return 0;
}