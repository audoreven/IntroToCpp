///////////////////////////////////////////////////////////////////////////////
//  Filename:      simple_class.cpp
//
//
//                
//  Description:   This program contains code that demonstrates the basics of
//                 a class for complex numbers.
///////////////////////////////////////////////////////////////////////////////

/**************************/
// Preprocessor Directives
/**************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>

/**************************/
// namespace
/**************************/
using namespace std;

/**************************/
// classes
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

int main_complex()
{
	Complex complex_a(1.0, 2.0);
	Complex complex_b(2.0, 4.0);

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


