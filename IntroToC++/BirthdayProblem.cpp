/*****************************************************************************/
//  Filename:		BirthdayProblem.cpp
//
//  Author:			Audrey Zhu
//
//  Date:			2021.05.19
//
//  Modifications:	N/A
//
//  Description: 		
//	This file simulates random birthdays for a group of people and calculates the 
//	chance that at least 2 of them have the same birthday. It is simulated over 
//	and over until it gets closer to the theoretical probability. 
//
/*****************************************************************************/

/*****************************************************************************/
//							Preprocessor Directives
/*****************************************************************************/
#include <iostream>
#include <iomanip>

/*****************************************************************************/
//								  namespace
/*****************************************************************************/
using namespace std;

/*****************************************************************************/
//                            Function prototypes 
/*****************************************************************************/
float simulate(int, int);
void reset(bool[], int);
void output(int, float);

/*****************************************************************************/
//									main()
/*****************************************************************************/
/*******************
	Variables:
********************

const int	NUM_OF_PLAYERS	- number of players in the game

int			test1_iter		- number of iterations in first simulations
			test2_iter		- number of iterations in second simulations
			test3_iter		- number of iterations in third simulations
			test4_iter		- number of iterations in fourth simulations
			test4_iter		- number of iterations in fifth simulations
			final_iter		- number of iterations in final answer simulations

*************************
   Invoked Functions:
*************************

1. "simulate"	calculates the probability of having at least two players having  
				the same birthday

2. "output"	displays the following:
	 a) the number of iterations used in the simulations
	 b) the probability that resulted from the simulations

/*****************************************************************************/
int main_bday()
{
	const int NUM_OF_PLAYERS = 22;
	int test1_iter = 10, test2_iter = 50, test3_iter = 100, test4_iter = 500, test5_iter = 5000;
	int final_iter = 100000;
	// int num_of_iter = 10;

	cout << "Probability for..." << endl << endl;
	output(test1_iter, simulate(NUM_OF_PLAYERS, test1_iter));
	output(test2_iter, simulate(NUM_OF_PLAYERS, test2_iter));
	output(test3_iter, simulate(NUM_OF_PLAYERS, test3_iter));
	output(test4_iter, simulate(NUM_OF_PLAYERS, test4_iter));
	output(test5_iter, simulate(NUM_OF_PLAYERS, test5_iter));

	cout << setprecision(5) << right << endl << endl;
	cout << setw(18) << "FINAL ANSWER: "
		 << setw(9) << simulate(NUM_OF_PLAYERS, final_iter) << endl;

	return 0;
}


/*****************************************************************************/
//                             Function definitions 
/*****************************************************************************/
/*****************************************************************************/
//
// Function:	simulate(	int n, 
//							int iter)
//
// Parameters:	int n		- number of people in the group
//				int iter	- number of iterations to run
//
// Outputs:		None
//
// Returns:		float - probability that at least 2 plays have the same birthday
//
// Author:		Audrey Zhu
//
// Date:		2021.05.19
//
// Modifications: None
//
// Description:
// This function runs the simulation of choosing random birthdays for n people. It 
// generates birthdays until someone has a repeated birtday. After that, it increments
// the number of successful run there has been. After iter repeated simulations, it 
// puts that number over iter, which is the total number of trials there has been.
// This number/the probability is returned, and is representated as the ratio of 
// occurrence of same birthdays(from at least two players) over the number of 
// iterations. 
//
// To generate the birthdays, a random number is generated and modded by 365 (the number
// of days in a year). If that index in the "birthdays" array is already true, it means
// that it is a repeated birthday and that trial is over, and if it is not true, then 
// It will be marked as true.
// 
/*****************************************************************************/
float simulate(int n, int iter)
{
	int has_same_birthday = 0;
	bool birthdays[365];
	reset(birthdays, 365);

	for (int i = 0; i < iter; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// generate birthdays
			int hypo_birthday = rand() % 365;

			// if someone already has that birthday, break out of loop and add one to successes
			if (birthdays[hypo_birthday] == true) {
				has_same_birthday++;
				break;
			}

			// otherwise toggle that birthday index to true
			birthdays[hypo_birthday] = true;
		}
		reset(birthdays, 365);
	}

	return has_same_birthday / static_cast<float>(iter);
}

/*****************************************************************************/
//
// Function:	reset(	bool arr[], 
//						int len)
//
// Parameters:	bool arr[]	- array to be reset
//				int len	-	- length of the array
//
// Outputs:		None
//
// Returns:		None
//
// Author:		Audrey Zhu
//
// Date:		2021.05.19
//
// Modifications: None
//
// Description:
// This function resets a boolean array (arr) of size len to all false.
//
/*****************************************************************************/
void reset(bool arr[], int len)
{
	for (int i = 0; i < len; i++) 
		arr[i] = false;
	
}

/*****************************************************************************/
//
// Function:	output(	int iter, 
//						float probability)
//
// Parameters:	int iter			- number of iterations ran
//				float probability	- the calculated probability to display	-	- 
//
// Outputs:		None
//
// Returns:		None
//
// Author:		Audrey Zhu
//
// Date:		2021.05.19
//
// Modifications: None
//
// Description:
// This function prints out one line that displays the number of iterations ran
// and the probability calculated from that.
//
/*****************************************************************************/
void output(int iter, float probability)
{
	cout << setprecision(3) << right; 
	cout << setw(5) << iter << left
		 << setw(15) << " iterations: "
		 << setw(5) << probability << endl;

}
