/*****************************************************************************/
//  Filename:      lab3.cpp
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

#include <iostream>
#include <string>
#include <iomanip>

// define state sales tax rate using macro
#define TAX_RATE 0.0875

using namespace std;


/*****************************************************************************/
//                                  main() 
/*****************************************************************************/
int main_lab3()
{
	// defining memory constants
	const double TV_UNIT_PRICE = 500.00;
	const double DVD_UNIT_PRICE = 380.00;
	const double REMOTE_UNIT_PRICE = 35.20;
	const double CD_UNIT_PRICE = 74.50;
	const double AV_PROCESSOR_UNIT_PRICE = 1500.00;

	// declare other variables
	int tv_amt, dvd_amt, remote_amt, cd_amt, av_processor_amt;
	double subtotal, tax, total;

	// ask for how many of each product were sold
	cout << "How many TVs were sold? ";
	cin >> tv_amt;
	cout << "How many DVD players were sold? ";
	cin >> dvd_amt;
	cout << "How many remote controllers were sold? ";
	cin >> remote_amt;
	cout << "How many CD players were sold? ";
	cin >> cd_amt;
	cout << "How many AV processors were sold? ";
	cin >> av_processor_amt;
	cout << endl;
	
	// calculate subtotal, tax, andtotal
	subtotal = tv_amt * TV_UNIT_PRICE + dvd_amt * DVD_UNIT_PRICE +
		remote_amt * REMOTE_UNIT_PRICE + cd_amt * CD_UNIT_PRICE +
		av_processor_amt * AV_PROCESSOR_UNIT_PRICE;
	tax = subtotal * TAX_RATE;
	total = subtotal + tax;

	// display results of each specific product
	cout << left << setw(4) << "QTY" << setw(25) << "Description" << setw(15) << "Unit Price"  << setw(11) << "Total Price" << endl;
	cout << setprecision(2) << fixed;
	if (tv_amt > 0) 
	{
		cout << left << setw(4) << tv_amt << setw(25) << "TV" << "$" << right << setw(10) 
			<< TV_UNIT_PRICE << setw(5) << "$" << setw(10) << TV_UNIT_PRICE * tv_amt << endl;
	}

	if (dvd_amt > 0)
	{
		cout << left << setw(4) << dvd_amt << setw(25) << "DVD PLAYER" << "$" << right << setw(10) 
			 << DVD_UNIT_PRICE << setw(5) << "$" << setw(10) << DVD_UNIT_PRICE * dvd_amt << endl;
	}

	if (remote_amt > 0)
	{
		cout << left << setw(4) << remote_amt << setw(25) << "REMOTE CONTROLLER" << "$" << right 
			 << setw(10) << REMOTE_UNIT_PRICE << setw(5) << "$" << setw(10) 
			 << REMOTE_UNIT_PRICE * remote_amt << endl;
	}

	if (cd_amt > 0)
	{
		cout << left << setw(4) << cd_amt << setw(25) << "CD PLAYER" << "$"<< right << setw(10) 
			 << CD_UNIT_PRICE << setw(5) << "$" << setw(10) << CD_UNIT_PRICE * cd_amt << endl;
	}

	if (av_processor_amt > 0)
	{
		cout << left << setw(4) << av_processor_amt << left << setw(25) << "AV PROCESSOR" 
			 << "$" << right << setw(10) << AV_PROCESSOR_UNIT_PRICE << setw(5) << "$" 
			 << setw(10) << AV_PROCESSOR_UNIT_PRICE * av_processor_amt << endl;
	}

	// displaying subtotal, tax, and total
	cout << endl;
	cout << left << setw(4) << " " << setw(25) << " " << setw(15) << "SUBTOTAL" << right 
		 << "$" << right << setw(10) << subtotal << endl;
	cout << left << setw(4) << " " << setw(25) << " " << setw(15) << "TAX" << right 
		 << "$" << right << setw(10) << tax << endl;
	cout << left << setw(4) << " " << setw(25) << " " << setw(15) << "TOTAL" << right  
		 << "$" << right << setw(10) << total << endl;


	return 0;
}

/*------------------------ SAMPLE OUTPUT 1 ------------------------

How many TVs were sold? 13
How many DVD players were sold? 2
How many remote controllers were sold? 3
How many CD players were sold? 1
How many AV processors were sold? 21

QTY Description              Unit Price     Total Price
13  TV                       $    500.00    $   6500.00
2   DVD PLAYER               $    380.00    $    760.00
3   REMOTE CONTROLLER        $     35.20    $    105.60
1   CD PLAYER                $     74.50    $     74.50
21  AV PROCESSOR             $   1500.00    $  31500.00

							 SUBTOTAL       $  38940.10
							 TAX            $   3407.26
							 TOTAL          $  42347.36

-----------------------------------------------------------------*/

/*------------------------ SAMPLE OUTPUT 2 ------------------------

How many TVs were sold? 0
How many DVD players were sold? 2
How many remote controllers were sold? 0
How many CD players were sold? 1
How many AV processors were sold? 0

QTY Description              Unit Price     Total Price
2   DVD PLAYER               $    380.00    $    760.00
1   CD PLAYER                $     74.50    $     74.50

							 SUBTOTAL       $    834.50
							 TAX            $     73.02
							 TOTAL          $    907.52

-----------------------------------------------------------------*/