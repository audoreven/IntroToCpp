/*****************************************************************************/
//  Filename:		Complex.h
//
//  Author:			Audrey Zhu
//
//  Date:			2021.05.17
//
//  Modifications:	N/A
//
//  Description:		
//	This file defines the class Complex. It includes the methods and the attributes
//  of the class.
//
/*****************************************************************************/


/**************************/
//			class
/**************************/
class Complex
{
public:
	Complex(void);
	Complex(double real, double imag);
	Complex operator + (Complex);

	bool set_cartesian(double real, double imag);
	bool set_polar(double magnitude, double angle);
	bool get_cartesian(double& real, double& imag);
	bool get_polar(double& magnitude, double& angle);
private:
	double real_value;
	double imaginary_value;
};

