// File Name: one_billion_seconds.cpp
// Description: This code example shows the application of using / and % together to do 
// units conversion from 1 billion seconds to years; days; hours; minutes; seconds. 
//

#include <iostream>
using namespace std;

int main_1bil()
{
	int secs = 1000000000;
	int days_per_year = 365;
	int yrs, days, hrs, mins;
	mins = secs / 60;
	secs = secs % 60;
	hrs = mins / 60;
	mins = mins % 60;
	days = hrs / 24;
	hrs = hrs % 24;
	yrs = days / days_per_year;
	days %= days_per_year;

	cout << "How many days, hours, minutes and seconds do One Billion Seconds equal to ?" << endl;
	cout << "Answer:  " << yrs << " years; "
		<< days << " days;  "
		<< hrs << " hours;  "
		<< mins << " mins;  "
		<< secs << " secs; " << endl;
	return 0;
}