#include <iostream>

using namespace std;

int main()
{
	int x;
	x = 3 / static_cast<int>(4.5 + 6.4);
	cout << x << endl << endl;

	double pay = 25.00;
	pay /= 2;
	cout << pay << endl << endl;


	return 0;
}