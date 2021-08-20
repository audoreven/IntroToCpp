/*****************************************************************************/
//  Filename:		ComplexTest.cpp
//
//  Author:			Audrey Zhu
//
//  Date:			2021.05.17
//
//  Modifications:	N/A
//
//  Description: 		
//	This file tests the Complex class. It adds two complex numbers together and
//  shows the attribute and information of all of them.
//
/*****************************************************************************/

/*****************************************************************************/
//							Preprocessor Directives
/*****************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>

#include "Complex.h"

/*****************************************************************************/
//								  namespace
/*****************************************************************************/
using namespace std;


/*****************************************************************************/
//									main()
/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
//  Function:      int main( void )
//
//  Inputs:        None
//
//  Outputs:       None
//
//  Returns:       int - 0 for normal
//
//
///  Description:  This function demonstrates instantiation of the Complex
//                 class.
///////////////////////////////////////////////////////////////////////////////

int main_lab8()
{
	Complex complex_a(1.2, 3.4);
	Complex complex_b(5.6, 7.8);

	double real_value = 0.0;
	double imaginary_value = 0.0;
	double magnitude = 0.0;
	double angle_rads = 0.0;

	complex_a.get_cartesian(real_value, imaginary_value);
	complex_a.get_polar(magnitude, angle_rads);

	cout << "complex_a" << endl << endl;
	cout << "Real:      " << real_value << endl;
	cout << "Imaginary: " << imaginary_value << endl << endl;
	cout << "Magnitude: " << magnitude << endl;
	cout << "Angle:     " << angle_rads << endl << endl << endl;

	complex_b.get_cartesian(real_value, imaginary_value);
	complex_b.get_polar(magnitude, angle_rads);

	cout << "complex_b" << endl << endl;
	cout << "Real:      " << real_value << endl;
	cout << "Imaginary: " << imaginary_value << endl << endl;
	cout << "Magnitude: " << magnitude << endl;
	cout << "Angle:     " << angle_rads << endl << endl << endl;


	// use the operator+
	Complex complex_c = complex_a + complex_b;

	complex_c.get_cartesian(real_value, imaginary_value);
	complex_c.get_polar(magnitude, angle_rads);

	cout << "complex_c = complex_a + complex_b" << endl << endl;
	cout << "Real:      " << real_value << endl;
	cout << "Imaginary: " << imaginary_value << endl << endl;
	cout << "Magnitude: " << magnitude << endl;
	cout << "Angle:     " << angle_rads << endl << endl << endl;

	//system("pause");

	return 0;
} // end of main()

