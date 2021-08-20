#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include "Old_Cellphone.h"
using namespace std;

int arr[5];


float rounding(float value)
{
	return floor((value * 100) + 0.5) / 100;
}

void sort(int lst[], int size) {
	// local variabls
	int minimum, min_index;

	for (int i = 0; i < size; i++) {
		min_index = i, minimum = lst[i];

		// find minimum in pass
		for (int j = i; j < size; j++) {
			if (lst[j] < minimum) {
				min_index = j;
				minimum = lst[j];
			}
		}

		// swap elem with smallest
		lst[min_index] = lst[i];
		lst[i] = minimum;
	}

}


void write_dash(int x)
{

	if (x > 0)

	{

		for (int i = 0; i < x; i++)

		{

			cout << "-";

		}

	}

}
int main_t()
{
	/*int nums[5] = {1};

	for (int i = 0; i < sizeof(nums)/ sizeof(nums[0]); i++) {
		cout << "index " << i << " is "<< nums[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		cout << "index " << i << " is " << arr[i] << endl;
	}

	cout << endl;

	char fName[] = "Hello";
	cout << fName << endl;

	cout << endl;

	for (int i = 0; i < sizeof(fName) / sizeof(fName[0]); i++) {
		cout << fName[i] << endl;
	}*/

	float te = 123.12354;
	cout << rounding(te) << endl;

	te = 34.1479;
	cout << rounding(te) << endl;
	int n = 1;
	for (; n <= 5;) {
		cout << n << endl;
		n++;
	}

	int age = 7;
	int* my_age_ptr = &age;
	int* your_age_ptr = &age;
	cout << *my_age_ptr << " " << *your_age_ptr << endl;

	int arr[] = { 2,34,5,67,21,1,4 };
	int sorted[7];
	for (int i = 0; i < 7; i++) {
		sorted[i] = arr[i];
	}
	sort(sorted, 7);


	for (int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < 7; i++) {
		cout << sorted[i] << " ";
	}

	char r_n = 'B';

	if (r_n != 'R' && r_n != 'N') {
		cout << "rn not r or n" << endl;
	}

	if (!(r_n =='R' || r_n =='N')) {
		cout << "rn not r or n" << endl;
	}

	int num = 30;
	// bool a = true;

	if (num) {

		cout << "rn not r or n" << endl;
	}
	int a = 10;
	int cou = 0;

	int number_series[100];

	write_dash(10);
	write_dash(-2);

	return 0;
}
