/*****************************************************************************/
//                                 File Header 
/*****************************************************************************/

/*****************************************************************************/
//  Filename:      lab5.cpp
//
//  Author:        Audrey Zhu
//
//  Date:          2021.04.14
//
//  Modifications: N/A
//
//  Description:	This file asks the users for the house selling price, annual interest rate 
//					on loans, and the number of years to pay off the loans. It then uses these
//					values to calculate the monthly mortgage, utility fee, insurance, and 
//					property tax to find the total monthly cost. All of this is displayed in 
//					another txt file in a neat format.
//
/*****************************************************************************/

/*****************************************************************************/
//							Preprocessor Directives
/*****************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#define ANNUAL_TAX_RATE 0.0125
#define ANNUAL_INSURANCE_COST 550.00
#define MONTLY_UTILITY_COST 300.00

/*****************************************************************************/
//								  namespace
/*****************************************************************************/
using namespace std;


/*****************************************************************************/
//                            Function prototypes 
/*****************************************************************************/
void prompt_input(float &, float &, int &);
float calc_monthly_cost(float, float, int, float &, float &, float&, float&, float&);
void file_output(float, float, int, float, float, float, float, float, float);

float calc_down_payment(float, float);
float calc_loan(float, float);
float calc_monthly_mortgage(float, float, int);


/*****************************************************************************/
//									main()
/*****************************************************************************/
/*******************
	Variables:
********************

float selling_price		- house selling price
	  rate_of_interest	- annual interest rate on the loan
	  monthly_cost		- total monthly cost; sum of mortgage, utilities, property tax and insurance
	  down_payment		- amount of down payment
	  loan				- loan to be borrowed from the bank
	  mortgage			- monthly mortgage payment calculated from the compound interest formula
	  monthly_insurance - monthly insurance payment
	  property_tax		- monthly property tax payment

int years_for_loan		- number of years to pay off the loan
						  will be converted to months to be used in the compound interest formula

*************************
   Invoked Functions:
*************************

1. "prompt_input" inputs mortgage data from user
	 a) house selling price
	 b) loan interest rate charged by the bank
	 c) number of years for the loan

2. "calc_monthly_costs" calculates the monthly house cost and gives:
	 a) down payment,
	 b) loan amount,
	 c) monthly mortgage payment,
	 d) monthly property tax payment,
	 e) monthly insurance premium payment, and
	 f) total monthly cost - sum of mortgage, utilities, tax and insurance

3. "file_output" writes output data to a text file

/*****************************************************************************/
int main_lab5()
{
	/******************************/
	//		    variable
	/*****************************/
	float selling_price, rate_of_interest, monthly_cost, down_payment, loan, 
		mortgage, monthly_insurance, property_tax;
	int years_for_loan;

	/******************************/
	//        prompt input
	/*****************************/
	prompt_input(selling_price, rate_of_interest, years_for_loan);


	/******************************/
	//    calculate monthly cost
	/*****************************/
	monthly_cost = calc_monthly_cost(selling_price, rate_of_interest, years_for_loan, 
									 down_payment, loan, mortgage, monthly_insurance, 
									 property_tax);

	/******************************/
	//	 	 output to file
	/*****************************/
	file_output(selling_price, rate_of_interest, years_for_loan, down_payment, loan, 
				mortgage, monthly_insurance, property_tax, monthly_cost);

	return 0;
}


/*****************************************************************************/
//                             Function definitions 
/*****************************************************************************/

/*****************************************************************************/
//
// Function:	prompt_input(	float &sell_price, 
//								float &interest_rate, 
//								int	  &years_loan)
//
// Parameters:	float &sell_price		- house selling price 
//				float &interest_rate	- annual interest rate on the loan
//				int	  &years_loan		- number of years to pay the loan
//
// Outputs:    None
//
// Returns:    None
//
// Author:     Audrey Zhu
//
// Date:       2021.04.05
//
// Modifications: None
//
// Description:
// This function prompts the sell price of the house, interest rate, and the number of 
// years to pay off the loan. It stores the values as reference variables.
//
/*****************************************************************************/
void prompt_input(float &sell_price, float &interest_rate, int &years_loan)
{
	// prompting sell price
	cout << "Enter selling price: ";
	cin >> sell_price;

	// prompt interest rate
	cout << "Enter rate of interest: ";
	cin >> interest_rate;

	// prompt number of years for loan
	cout << "Enter the number of years for loan: ";
	cin >> years_loan;
}


/*****************************************************************************/
//
// Function:   calc_monthly_cost(	float sell_price, 
//									float interest_rate, 
//									int   years_loan, 
//									float &down_payment, 
//									float &loan_amount, 
//									float &monthly_mortgage,
//									float &insurance, 
//									float &property_tax)
//
// Parameters:	float sell_price		- house selling price
//				float interest_rate		- annual interest rate on the loan
//				int   years_loan		- number of years to pay the loan
//				float &down_payment		- amount of down payment
//				float &loan_amount		- loan to be borrowed from the bank
//				float &monthly_mortgage	- monthly mortgage payment calculated from the
//										  compound interest formula 
//				float &insurance		- monthly insurance payment
//				float &property_tax		- monthly property tax payment
//
// Outputs:    None
//
// Returns:    float - monthly_cost, total monthly cost, sum of mortgage, utilities, property tax and insurance
//
// Author:     Audrey Zhu
//
// Date:       2021.04.14
//
// Modifications: None
//
// Description:
// This function invokes "calc_down_payment" to get the down payment, "calc_loan" to get the loan, and
// "calc_monthly_mortgage" to get the monthly mortgage. It then adds up the monthly mortgage with
// the montly insurance cost, monthly utility cost, and monthly property tax to get the total monthly cost.
// It stores all values calculated in the corresponding reference variable
// 
/*****************************************************************************/
float calc_monthly_cost(float sell_price, float interest_rate, int years_loan, float &down_payment, 
						float &loan_amount, float &monthly_mortgage, float &insurance, float &property_tax) 
{
	const float DOWN_PAYMENT_PCT = 0.2;

	// calculate down payment
	down_payment = calc_down_payment(sell_price, DOWN_PAYMENT_PCT);
	
	// calculate loan
	loan_amount = calc_loan(sell_price, down_payment);

	// calculate mortgage
	monthly_mortgage = calc_monthly_mortgage(loan_amount, interest_rate, years_loan);

	// other calculations needed for monthly cost (monthly insurance and property tax)
	insurance = ANNUAL_INSURANCE_COST / 12;
	property_tax = (sell_price * ANNUAL_TAX_RATE) / 12;

	// add together all costs
	float monthly_cost = insurance + MONTLY_UTILITY_COST + monthly_mortgage + property_tax;

	return monthly_cost;
}


/*****************************************************************************/
//
// Function:   file_output( float sell_price, 
//							float interest_rate, 
//							int   years_loan, 
//							float down_payment, 
//							float loan_amount, 
//							float monthly_mortgage,
//							float insurance, 
//							float property_tax,
//							float monthly_cost)
//
// Parameters: float sell_price			- house selling price
//			   float interest_rate		- annual interest rate on the loan
//			   int   years_loan			- number of years to pay the loan
//			   float down_payment		- amount of down payment
//			   float loan_amount		- loan to be borrowed from the bank
//			   float monthly_mortgage	- monthly mortgage payment calculated from the 
//										  compound interest formula 
//			   float insurance			- monthly insurance payment
//			   float property_tax		- monthly property tax payment
//			   float monthly_cost		- total monthly cost; sum of mortgage, utilities,
//										  property tax and insurance
//
// Outputs:    A file that displays all of the above
//
// Returns:    None
//
// Author:     Audrey Zhu
//
// Date:       2021.04.14
//
// Modifications: None
//
// Description:
// This function writes output data to a text file in an organized and neat format
//
/*****************************************************************************/
void file_output(float sell_price, float interest_rate, int years_loan, float down_payment,
				 float loan, float mortgage, float insurance, float property_tax, float monthly_cost) 
{
	ofstream output;
	output.open("monthly-cost.txt");

	int COL1 = 30;
	int COL2 = 1;
	int COL3 = 10;
	streamsize default_precision = output.precision();

	
	// title banner
	output << setfill('*') << setw(45) << "" << endl;
	output << setfill(' ') << right << setw(33) << "MONTHLY COST OF HOUSE" << endl;
	output << setfill('*') << setw(45) << "" << endl;

	// 
	output << setfill(' ') << setprecision(2) << fixed;
	output << left << setw(COL1) << "SELLING PRICE" << setw(COL2) << "$" << setw(COL3) << right << sell_price << endl;
	output << left << setw(COL1) << "DOWN PAYMENT" << setw(COL2) << "$" << setw(COL3) << right << down_payment << endl;
	output << left << setw(COL1) << "AMOUNT OF LOAN" << setw(COL2) << "$" << setw(COL3) << right << loan << endl << endl;

	//
	output << left;
	output << setw(COL1) << "INTEREST RATE" << interest_rate * 100 << " %" << endl;
	output << setw(COL1) << "TAX RATE" << ANNUAL_TAX_RATE * 100 << " %" << endl << endl;
	output << setprecision(default_precision) << fixed;
	output << setw(COL1) << "DURATION OF LOAN (YEARS)" << years_loan << " years" << endl 
		   << endl << endl;


	// smaller banner
	output << setfill('*') << setw(17) << "" << endl;
	output <<  " MONTHLY PAYMENT " << endl;
	output << setw(17) << "" << endl;


	// 
	output << setfill(' ') << setprecision(2) << fixed;
	output << left << setw(COL1) << "MORTGAGE PAYMENT" << setw(COL2) << "$" << setw(COL3) << right << mortgage << endl;
	output << left << setw(COL1) << "UTILITIES" << setw(COL2) << "$" << setw(COL3) << right << MONTLY_UTILITY_COST << endl;
	output << left << setw(COL1) << "PROPERTY TAXES" << setw(COL2) << "$" << setw(COL3) << right << property_tax << endl;
	output << left << setw(COL1) << "INSURANCE" << setw(COL2) << "$" << setw(COL3) << right << insurance << endl;
	output << left << setw(COL1) << "" << setw(COL3 + 1) << setfill('-') << "";

	output << setfill(' ') << endl;
	output << left << setw(COL1) << " " << setw(COL2) << "$" << setw(COL3) << right << monthly_cost << endl;
	
}


/*****************************************************************************/
//
// Function:   calc_down_payment(float sell_price, 
//								 float percent)
//
// Parameters:	float sell_price	- house selling price
//				float percent		- percent of sell price that is paid as down payment
//
// Outputs:    None
//
// Returns:    float - down_payment, amount of down payment
//
// Author:     Audrey Zhu
//
// Date:       2021.04.14
//
// Modifications: None
//
// Description:
// This function multiplies the sell price by the percent to get the down payment.
//
/*****************************************************************************/
float calc_down_payment(float sell_price, float percent) 
{
	float down_payment = sell_price * percent;
	return down_payment;
}


/*****************************************************************************/
//
// Function:   calc_loan(float sell_price, 
//						 float down_paymnt)
//
// Parameters:	float sell_price	- house selling price
//				float down_paymnt	- amount of down payment
//
// Outputs:    None
//
// Returns:    float - loan, loan to be borrowed from the bank
//
// Author:     Audrey Zhu
//
// Date:       2021.04.14
//
// Modifications: None
//
// Description:
// This function subtracts the down payment from the sell price to get the loan amount.
//
/*****************************************************************************/
float calc_loan(float sell_price, float down_paymnt) 
{
	float loan = sell_price - down_paymnt;
	return loan;
}


/*****************************************************************************/
//
// Function:   calc_monthly_mortgage(float loan, 
//									 float rate, 
//									 int years)
//
// Parameters: loan		- loan to be borrowed from the bank
//			   rate		- annual interest rate on the loan
//			   years	- number of years to pay off the loan
//
// Outputs:    None
//
// Returns:    float - mortgage, monthly mortgage payment calculated from the 
//								 compound interest formula
//
// Author:     Audrey Zhu
//
// Date:       2021.04.14
//
// Modifications: None
//
// Description:
// This function uses the following formula to calculate mortgage:
//				mortgage = (a x i x (1+i)^n)/((1+i)^n−1)
//				WHERE   a = amount of loan
//						i = rate of interest per compounding period(annual rate / 12)
//						n = number of compounding periods(yrs * 12)
//
/*****************************************************************************/
float calc_monthly_mortgage(float loan, float rate, int years) 
{
	int months = years * 12;
	float interest_per_month = rate / 12;
	float mortgage = (loan * interest_per_month * pow(1 + interest_per_month, months)) / (pow(1 + interest_per_month, months) - 1);
	return mortgage;
}