/*
* Name: Audrey Zhu
* Email: audreyzhu059@gmail.com
* Lab 2: prompts date and total amount collected and calculates sales,
*		county sales tax, state sales tax, and total sales tax with a 
*		preset tax rates
*/

#include <iostream>
#include <string>
#include <iomanip>

// define state sales tax rate
#define STATE_SALES_TR 0.053

using namespace std;

int main_lab2()
{
	// define county sales_tax rate
	const double COUNTY_SALES_TR = 0.031;
	const double COMB_TR = STATE_SALES_TR + COUNTY_SALES_TR;

	// declare other variables
	string date;
	double total_collected, sales, county_sales_tax, 
		state_sales_tax, total_sales_tax;

	// ask for date
	cout << "Month: ";
	getline(cin, date);

	// ask for total amount collected
	cout << "Total collected: ";
	cin >> total_collected;

	// calculate sales
	sales = total_collected / (1 + COMB_TR);

	// calculate total sales tax
	total_sales_tax = total_collected - sales;

	// calculate county sales tax
	county_sales_tax = total_sales_tax * COUNTY_SALES_TR / COMB_TR;

	// calculate state sales tax
	state_sales_tax = total_sales_tax - county_sales_tax;

	//display results
	cout << "Month: " << date << endl;
	cout << "-------------------" << endl;
	cout << setprecision(2) << fixed;
	cout << "Total Collected: \t$" << setw(12) << total_collected << endl;
	cout << "Sales: \t\t\t$" << setw(12) << sales << endl;
	cout << "County Sales Tax: \t$" << setw(12) << county_sales_tax << endl;
	cout << "State Sales Tax: \t$" << setw(12) << state_sales_tax << endl;
	cout << "Total Sales Tax: \t$" << setw(12) << total_sales_tax << endl;

	return 0;
}

/*
 
Month: March, 2019
Total collected: 81673.67
Month: March, 2019
-------------------
Total Collected:        $    81673.67
Sales:                  $    75344.71
County Sales Tax:       $     2335.69
State Sales Tax:        $     3993.27
Total Sales Tax:        $     6328.96

*/