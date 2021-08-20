// This program will output the area and perimeter
// of a rectangle with a given length and width
//  Audrey Zhu 
#include <iostream>
using namespace std;

const  int LENGTH = 8;
const  int WIDTH = 3;

int main_rect()
{
	float area;			// definition of area of rectangle
	float perimeter;		// definition of perimeter of rectangle
	area = LENGTH * WIDTH;                // computes area
	perimeter = 2 * (LENGTH + WIDTH);           // computes perimeter

   // Fill in the code for the cout statement that will output (with description)
   // the area
	cout << "The area of a rectangle with dimensions " 
		<< LENGTH << "x" << WIDTH << " is " << area << endl;

   // Fill in the code for the cout statement that will output (with description)
   // the perimeter
	cout << "The perimeter of a rectangle with dimensions "
		<< LENGTH << "x" << WIDTH << " is " << perimeter << endl;

	return 0;
}