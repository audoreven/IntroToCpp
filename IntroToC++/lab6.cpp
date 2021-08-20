/*****************************************************************************/
//                                 File Header 
/*****************************************************************************/

/*****************************************************************************/
//  Filename:		lab6.cpp
//
//  Author:			Audrey Zhu
//
//  Date:			2021.04.21
//
//  Modifications:	N/A
//
//  Description:		
//	This file gets the balance, annual interest rate, and minimum payment percent
//	from a txt file, and uses those values to calculate the monthly balance until
//	it reaches 0. It also finds the interest, minimum payment, and the sum of 
//	interest for each month, and displays all of this information as a table in 
//  another txt file.
//
/*****************************************************************************/

/*****************************************************************************/
//							Preprocessor Directives
/*****************************************************************************/
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

/*****************************************************************************/
//								  namespace
/*****************************************************************************/
using namespace std;

/*****************************************************************************/
//                            Function prototypes 
/*****************************************************************************/
void prompt_input(ifstream &, float &, float &, float &);
void write_output_header(ofstream &, float, float, float, int, int, int, int, int);
float calc_balance(float, float, float, float &, float &);
void write_output_line(ofstream &, int, float, float, float, float, int, int, int, int, int);


/*****************************************************************************/
//									main()
/*****************************************************************************/
/*******************
	Variables:
********************

float		balance		- credit card balance
			apr			- annual interest rate
			min_pay_pct	- percent of minimum pay
			interest	- interest received (per month)
			min_pay		- minimum amount to pay (per month)
			sum_intr	- sum of interest received

int			month		- month number
			COL1		- width of column 1
			COL2		- width of column 2
			COL3		- width of column 3
			COL4		- width of column 4
			COL5		- width of column 5

ifstream	in_file		- the input file

ofstream	out_file	- the output file


*************************
   Invoked Functions:
*************************

1. "prompt_input" inputs credit card details from a file
	a) initial credit card balance
	b) annual interest rate
	c) percent minimum pay

2. "write_output_header" writes the header of the output file

3. "calc_balance" calculates the balance for the next month, also gives:
	 a) the interest amount
	 b) minimum payment amount

4. "write_output_line" writes one line of data to the output

/*****************************************************************************/
int main_lab6()
{
	/******************************/
	//		    variable
	/*****************************/
	float balance, apr, min_pay_pct, interest, min_pay, sum_intr = 0;
	int month = 0, COL1 = 5, COL2 = 15, COL3 = 15, COL4 = 15, COL5 = 20;
	ifstream in_file;
	ofstream out_file;


	/******************************/
	//         open files
	/*****************************/
	in_file.open("lab6.txt");
	out_file.open("payment_schedule.txt");

	// check if input file exists, otherwise exit program
	if (in_file.fail())
	{
		out_file << "File does not exist." << endl;
		return -1;
	}

	// get input
	prompt_input(in_file, balance, apr, min_pay_pct);

	/******************************/
	//	 output heading of file
	/*****************************/
	write_output_header(out_file, balance, apr, min_pay_pct, COL1, COL2, COL3, COL4, COL5);

	
	/******************************/
	//			calculate
	/*****************************/
	while (balance > 0)
	{
		month++;
		balance = calc_balance(balance, apr, min_pay_pct, interest, min_pay);
		sum_intr += interest;

		/******************************/
		//		   output line
		/*****************************/
		write_output_line(out_file, month, balance, interest, min_pay, sum_intr,
			COL1, COL2, COL3, COL4, COL5);

	}


	/******************************/
	//	 	  close files
	/*****************************/
	in_file.close();
	out_file.close();
	
	return 0;
}


/*****************************************************************************/
//                             Function definitions 
/*****************************************************************************/
/*****************************************************************************/
//
// Function:	prompt_input(	ifstream &input, 
//								float &bal, 
//								float &interest_rate, 
//								float &min_payment_pct)
//
// Parameters:	ifstream &input			- reference of the input file
//				float &bal				- reference of the credit card balance
//				float &interest_rate	- reference of annual interest rate
//				float &min_payment_pct	- reference of minimum payment percent
//
// Outputs:    None
//
// Returns:    None
//
// Author:     Audrey Zhu
//
// Date:       2021.04.26
//
// Modifications: None
//
// Description:
// This function prompts the balance, annual interest rate, minimum payment 
// percent to used for the credit card calculations.
//
/*****************************************************************************/

void prompt_input(ifstream& input, float& bal, float& interest_rate, float& min_payment_pct)
{
	// get input
	input >> bal >> interest_rate >> min_payment_pct;
	interest_rate /= 100;
	min_payment_pct /= 100;
}


/*****************************************************************************/
//
// Function:   write_output_header(	ofstream &output,
//									float bal, 
//									float intr_rate, 
//									float min_payment_pct, 
//									int COL1, 
//									int COL2, 
//									int COL3, 
//									int COL4, 
//									int COL5)
//
// Parameters:	ofstream &output		- reference of the output file
//				float bal				- initial balance
//				float intr_rate			- annual interest rate
//				float min_payment_pct	- percent of minimum pay
//				int COL1				- width of column 1
//				int COL2				- width of column 2
//				int COL3				- width of column 3
//				int COL4				- width of column 4
//				int COL5				- width of column 5
//
// Outputs:		None
//
// Returns:		None
//
// Author:		Audrey Zhu
//
// Date:		2021.04.21
//
// Modifications: None
//
// Description:
// This function writes the header of the output file
//
/*****************************************************************************/
void write_output_header(ofstream& output, float bal, float intr_rate,
	float min_payment_pct, int COL1, int COL2, int COL3, int COL4, int COL5)
{

	output << setprecision(2) << left << fixed;
	output << setw(29) << "Balance Owing:" << "$" << bal << endl;
	output << setprecision(0) << fixed;
	output << setw(30) << "APR: " << intr_rate * 100 << "%" << endl;
	output << setw(30) << "Percent for minimum payment: " << min_payment_pct * 100 << "%" << endl;
	output << setfill('-') << setw(COL1 + COL2 + COL3 + COL4 + COL5) << "" << endl;

	output << setprecision(2) << setfill(' ') << right << fixed;
	output << setw(COL1) << "MONTH" <<
		setw(COL2) << "BALANCE" <<
		setw(COL3) << "INTEREST" <<
		setw(COL4) << "MINIMUM PAY" <<
		setw(COL5) << "SUM OF INTEREST" << endl;
}

/*****************************************************************************/
//
// Function:   calc_balance(float curr_bal, 
//							float annual_intr_rt, 
//							float min_paymnt_pct, 
//							float &intr, 
//							float &min_paymnt)
//
// Parameters:	float curr_bal			- current credit card balance
//				float annual_intr_rt	- annual interest rate
//				float min_paymnt_pct	- percent of minimum pay
//				float &intr				- reference to interest received (per month)
//				float &min_paymnt		- reference to minimum amount to pay (per month)
// 
// Outputs:		None
//
// Returns:		float - the new balance
//
// Author:		Audrey Zhu
//
// Date:		2021.04.21
//
// Modifications: None
//
// Description: 
// This function finds and returns the new balance by calculating the interest and minimum 
// payment. The interest rate by multiplying the balance by the annual interest rate over 12. 
// The minimum payment per month is the minimum of 15 and the product of the balance + interest  
// and the minimum payment percent. If the balance itself is below $15, then the minimum 
// payment will be the balance + the interest. It returns the new balance, which if found by 
// adding interest to balance and then subtracting the minimum payment.
// 
/*****************************************************************************/
float calc_balance(float curr_bal, float annual_intr_rt, float min_paymnt_pct, float &intr, float &min_paymnt)
{
	intr = curr_bal * (annual_intr_rt / 12);
	if (curr_bal < 15.0) 
	{
		min_paymnt = curr_bal + intr;
		return 0;
	}
	min_paymnt = max((curr_bal + intr) * min_paymnt_pct, 15.0f);
	return curr_bal - min_paymnt + intr;
}

/*****************************************************************************/
//
// Function:   write_output_line(	ofstream &output, 
//									int mnth, 
//									float curr_bal, 
//									float intr, 
//									float min_payment, 
//									float sum_o_intr, 
//									int COL1, 
//									int COL2, 
//									int COL3, 
//									int COL4, 
//									int COL5)
//
// Parameters:	ofstream &output	- reference of the output file
//				int mnth			- month number
//				float curr_bal		- current credit card balance
//				float intr			- interest received that month
//				float min_payment	- minimum amount to pay that month
//				float sum_o_intr	- sum of interest received 
//				int COL1			- width of column 1
//				int COL2			- width of column 2
//				int COL3			- width of column 3
//				int COL4			- width of column 4
//				int COL5			- width of column 5
//
// Outputs:		None
//
// Returns:		None
//
// Author:		Audrey Zhu
//
// Date:		2021.04.21
//
// Modifications: None
//
// Description:
// This function writes one line of data to the output file in an organized and neat format
//
/*****************************************************************************/
void write_output_line(ofstream &output, int mnth, float curr_bal, float intr, 
	float min_payment, float sum_o_intr, int COL1, int COL2, int COL3, int COL4, int COL5)
{
	output << setw(COL1) << mnth <<
			  setw(COL2) << curr_bal <<
			  setw(COL3) << intr <<
			  setw(COL4) << min_payment <<
			  setw(COL5) << sum_o_intr << endl;

}

