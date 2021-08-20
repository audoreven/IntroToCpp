/*****************************************************************************/
//                              (1) File Header 
/*****************************************************************************/

/*****************************************************************************/
//  Filename:      lab4.cpp
//
//  Author:        Audrey Zhu
//
//  Date:          2021.03.08
//
//  Modifications: N/A
//
//  Description:   This file prompts the number of each product sold 
//				   and displays the sales data
//
/*****************************************************************************/


/*****************************************************************************/
//        (2) Preprocessor Directives, namespace, and Global Constants 
/*****************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// define profit rate constant
float PROFIT_RATE = 0.8;



/*****************************************************************************/
//                           (3) Function prototypes 
/*****************************************************************************/
int estimate_number_of_books(char, char, int);
float calculate_profit(int, float);
void output_results(string, int, float);


/*****************************************************************************/
//                                 (4) main() 
/*****************************************************************************/
int main_lab4()
{
	// variables
	string isbn;
	char req_sug, new_cont;
	float price, profit;
	int class_enroll, books_needed;

	// prompt input
	cout << "Enter book number: ";
	getline(cin, isbn);
	cout << "Enter price per copy: ";
	cin >> price;
	cout << "Enter expected class enrollment: ";
	cin >> class_enroll;
	cout << "Enter 'R' if required or 'S' if suggested: ";
	cin >> req_sug;
	cout << "Enter 'N' if new or 'C' if not a new text: ";
	cin >> new_cont;

	//call functions for calculations
	books_needed = estimate_number_of_books(req_sug, new_cont, class_enroll);
	profit = calculate_profit(books_needed, price);

	// output results by calling function
	output_results(isbn, books_needed, profit);

	return 0;
}


/*****************************************************************************/
//                           (5) Function definitions 
/*****************************************************************************/


/*****************************************************************************/
//
// Function:   estimate_number_of_books(char req_sug,
//										char new_cont, 
//										int class_size)
//
// Parameters: char req_sug		- indicates if book is required (R) or suggested (S)
// (Inputs)    char new_cont	- indicates if book is new (N) or continued (C)
//             int class_size	- expected number of people in class
//
// Outputs:    None
//
// Returns:    integer – books_needed, estimated number of books
//
// Author:     Audrey Zhu
//
// Date:       2021.03.15
//
// Modifications: None
//
// Description:
// This function is provided with whether the book is required or suggested, new or
// continued, and the expected class size, and returns a rounded number of how many
// books is needed. It uses this formula:
//			books_needed = static_cast<int>(class_size * percent + 0.5)		
//			WHERE percent is determined by if the book is new or not, 
//			required or suggested
//
/*****************************************************************************/
int estimate_number_of_books(char r_s, char n_c, int class_size)
{
	const double REQ_NEW = 0.9, REQ_CONT = 0.65, SUG_NEW = 0.4, SUG_CONT = 0.2;
	int books_needed = -1;

	if (toupper(r_s) == 'R')
	{
		if (toupper(n_c) == 'N')
		{
			books_needed = static_cast<int>(class_size * REQ_NEW + 0.5);
		}
		else if (toupper(n_c) == 'C')
		{
			books_needed = static_cast<int>(class_size * REQ_CONT + 0.5);
		}
	}
	else if (toupper(r_s) == 'S')
	{
		if (toupper(n_c) == 'N')
		{
			books_needed = static_cast<int>(class_size * SUG_NEW + 0.5);
		}
		else if (toupper(n_c) == 'C')
		{
			books_needed = static_cast<int>(class_size * SUG_CONT + 0.5);
		}
	}

	return books_needed;
}


/*****************************************************************************/
//
// Function:   double calc_resistance(	int books_needed,
//										float listed_price)
//
// Parameters: int books_needed		- estimated number of books needed
// (Inputs)    float listed_price	- price of book at book stores
//
// Outputs:    None
//
// Returns:    float – profit, prospective amount of money made
//
// Author:     Audrey Zhu
//
// Date:       2021.03.15
//
// Modifications: None
//
// Description:
// This function is provided with the number of books needed, its listed price 
// at the book store, and has access to the profit rate, and it returns the profit
// of reselling these books. It uses this formula:
//			profit = sell_price - amount_paid			WHERE
//			sell_price = books_needed * listed_price	AND 
//			amount_paid = sell_price * PROFIT_RATE
// Because the store pays less than the list price (PROFIT_RATE * list_price per book
// the prospective profit would be the supposed price of the books (books_needed * 
// listed_price) minus the amount paid (PROFIT_RATE * list_price * books_needed).
//
/*****************************************************************************/
float calculate_profit(int books_needed, float listed_price)
{
	float profit, sell_price, amount_paid;

	sell_price = books_needed * listed_price;
	amount_paid = sell_price * PROFIT_RATE;
	profit = sell_price - amount_paid;

	return profit;
}

/*****************************************************************************/
//
// Function:   output_results(	string isbn,
//								int num_of_books,
//								float profit)
//
// Parameters: string isbn			- a books 10 digit ISBN number
// (Inputs)    int num_of_books		- estimated number of books needed
//             float profit			- prospective amount of money made
//
// Outputs:    isbn
//			   number of books
//			   profit
//
// Returns:    None
//
// Author:     Audrey Zhu
//
// Date:       2021.03.15
//
// Modifications: None
//
// Description:
// This function displays the results in an adequately clear format. 
//
/*****************************************************************************/
void output_results(string isbn, int num_of_books, float profit)
{
	if (num_of_books == -1)
	{
		cout << "Error: Improper value entered." << endl;
	}
	else
	{
		cout << setprecision(2) << fixed;
		cout << "ISBN: " << isbn << endl;
		cout << "Copies Needed: " << num_of_books << endl;
		cout << "Profit: $" << profit << endl;
	}
}

