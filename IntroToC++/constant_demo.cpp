// This program demonstrates constant definitions using two methods:
// 1. define a constant as fixed value store in memory
// 2. use #define macro to define and substitute the value of a constant

#include <iostream>
using namespace std;

// this is a demonstration of the general use of #define macro - 
//    for text substitution:
#define STATEMENT_MACRO << "Output statement uses a macro substitution" <<endl <<endl;

// this is a domnstration of using the #define macro to define a constant
#define SECOND_PER_MINUTE 60


int main_constant()
{   
	// Constants   
	const double PI = 3.14159;   
	double diameter = 10.0;   

	// Variable to hold the circumference   
	double circumference;   

	// Calculate the circumference.   
	circumference = PI * diameter;   

	// Display the circumference.   
	cout << "The circumference is: " << circumference << endl << endl;   
	
	// This demonstrate using macro for text substitution   
	cout STATEMENT_MACRO   
	
	// This demonstrate using a macro for constant definition:   
	int minutes = 5;   
	
	cout << "There are " << minutes * SECOND_PER_MINUTE << " seconds in "         
		<< minutes << " minutes." << endl << endl << endl;   
	
	return 0;
}