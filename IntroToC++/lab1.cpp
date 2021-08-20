/*
* Name: Audrey Zhu
* Email: audreyzhu059@gmail.com
* Lab 1
*/

#include <iostream>
using namespace std;

int main_lab1()
{
	cout << "Solution provided by Audrey Zhu" << endl << endl;

	// define variables to be used
	int quarters, dimes, nickels, pennies;
	float total;

	// get number of quarters from user
	cout << "Please enter the number of quarters: ";
	cin >> quarters;

	// get number of dimes from user
	cout << "Please enter the number of dimes: ";
	cin >> dimes;

	// get number of nickels from user
	cout << "Please enter the number of nickels: ";
	cin >> nickels;

	// get number of pennies from user
	cout << "Please enter the number of pennies: ";
	cin >> pennies;
	cout << "Thank you." << endl;

	// calculate total
	total = 0.25 * quarters + 0.10 * dimes + 0.05 * nickels + 0.01*pennies;

	// output total
	cout << endl << "The total of " << quarters << " quarters, "
		<< dimes << " dimes, " << nickels << " nickels, and "
		<< pennies << " pennies is $" << total << "." << endl;

	return 0;
}


/*
Solution provided by Audrey Zhu

Please enter the number of quarters : 3
Please enter the number of dimes : 0
Please enter the number of nickels: 5
Please enter the number of pennies : 23
Thank you.

The total of 3 quarters, 0 dimes, 5 nickels, and 23 pennies is $1.23.

*/
