/*****************************************************************************/
//  Filename:		Complex.cpp
//
//  Author:			Audrey Zhu
//
//  Date:			2021.05.17
//
//  Modifications:	N/A
//
//  Description:		
//	This function details what each of the methods of the Complex class does.
//
/*****************************************************************************/

/*****************************************************************************/
//							Preprocessor Directives
/*****************************************************************************/
#include <cmath>
#include "Complex.h"


/////////////////////////////////////////////////////////////////////////////////
//  Function:      Complex::Complex( void )
//
//  Inputs:        None
//
//  Outputs:       None
//
//  Returns:       None
//
//  Author:        ENGR 21 Team
//
//  Date:          2016.10.31
//
//  Modifications: 
//
///  Description:  This function is a non-initializing constructor for the class
//                 Complex.
////////////////////////////////////////////////////////////////////////////////

Complex::Complex(void)
{
	real_value = 0;
	imaginary_value = 0;
} // end Complex


///////////////////////////////////////////////////////////////////////////////
//  Function:      Complex::Complex( double real, double imag )
//
//  Inputs:        double real - real initial value
//                 double imag - imaginary initial value
//
//  Outputs:       None
//
//  Returns:       None
//
//
///  Description:  This function is an initializing constructor for the class
//                 Complex.
///////////////////////////////////////////////////////////////////////////////

Complex::Complex(double real, double imag)
{
	real_value = real;
	imaginary_value = imag;
} // end Complex


/////////////////////////////////////////////////////////////////////////////////
//  Function:      Complex Complex::operator+ ( Complex other_cmplx )
//
//  Inputs:        Complex oprn - the class as operand being added
//
//  Outputs:       None
//
//  Returns:       Complex - class containing the sum
//
//  Author:        ENGR 21 Team
//
//  Date:          2016.10.31
//
//  Modifications: 
//
///  Description:  This function implements the "+" operation.
////////////////////////////////////////////////////////////////////////////////
Complex Complex::operator+ (Complex other_cmplx)
{
	Complex temp_obj;

	temp_obj.real_value = this->real_value + other_cmplx.real_value;
	temp_obj.imaginary_value = this->imaginary_value + other_cmplx.imaginary_value;

	return(temp_obj);
} // end operator+


  ///////////////////////////////////////////////////////////////////////////////
//  Function:      bool Complex::set_cartesian( double real, double imag )
//
//  Inputs:        double real - real  value
//                 double imag - imaginary  value
//
//  Outputs:       None
//
//  Returns:       bool - true if set; otherwise false
//
//
///  Description:  This function sets the values of Complex with cartesian
//                 coordinates.
///////////////////////////////////////////////////////////////////////////////

bool Complex::set_cartesian(double real, double imag)
{
	real_value = real;
	imaginary_value = imag;

	return true;
} // end set_cartesian


///////////////////////////////////////////////////////////////////////////////
//  Function:      bool Complex::set_polar( double magnitude, double angle )
//
//  Inputs:        double magnitude  - polar magnitude
//                 double angle      - polar angle
//
//  Outputs:       None
//
//  Returns:       bool - true if set; otherwise false
//
//
///  Description:  This function sets the values of Complex with polar
//                 coordinates.
///////////////////////////////////////////////////////////////////////////////

bool Complex::set_polar(double magnitude, double angle)
{
	real_value = magnitude * cos(angle);
	imaginary_value = magnitude * sin(angle);

	return true;
} // end set_polar

///////////////////////////////////////////////////////////////////////////////
//  Function:  bool Complex::get_cartesian( double& real, double& imag )
//
//  Inputs:        None
//
//  Outputs:       double& real_value - real value
//                 double& imag_value - imaginary value
//
//  Returns:       bool - true if valid; otherwise false
//
//
///  Description:  This function gets the values of Complex in cartesian
//                 coordinates.
///////////////////////////////////////////////////////////////////////////////

bool Complex::get_cartesian(double& real, double& imag)
{
	real = real_value;
	imag = imaginary_value;
	return true;
}

///////////////////////////////////////////////////////////////////////////////
//  Function:      bool Complex::get_polar( double& magnitude, double& angle )
//
//  Inputs:        None
//
//  Outputs:      double magnitude  - polar magnitude
//                double angle      - polar angle
//
//  Returns:       bool - true if valid; otherwise false
//
//
///  Description:  This function gets the values of Complex in polar
//                 coordinates.
///////////////////////////////////////////////////////////////////////////////

bool Complex::get_polar(double& magnitude, double& angle)
{
	magnitude = sqrt(real_value * real_value + imaginary_value * imaginary_value);
	angle = atan(imaginary_value / real_value);

	return true;
}
