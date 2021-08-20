/*****************************************************************************/
//  Filename:		lab7.cpp
//
//  Author:			Audrey Zhu
//
//  Date:			2021.05.05
//
//  Modifications:	N/A
//
//  Description:		
//	This program retrieve patient information from a txt file, and processes the
//	information into a summary table of all patients sorted by id number. The 
//	data retrieved includes the patient id, age, measured max heart rate, as well
//	as 5 days of average heart rate, max heart rate, and exercise heart rate. It 
//	uses this data to find the weekly average heart rate, number of days the
//	patient exercised, estimated max heart rate, ratio of measured max heart rate
//  to estimated max heart rate, and ratio of highest commuting heart rate to 
//	the measured max heart rate.
//
/*****************************************************************************/

/*****************************************************************************/
//							Preprocessor Directives
/*****************************************************************************/
#include <iomanip>
#include <fstream>
#include <string>

/*****************************************************************************/
//								  namespace
/*****************************************************************************/
using namespace std;

/*****************************************************************************/
//								  Constants
/*****************************************************************************/
const int MAX_DAYS = 5;
const int MAX_PATIENTS = 100;

/*****************************************************************************/
//                            Function prototypes 
/*****************************************************************************/
void get_data(ifstream&, int[], int[], int[], int[], float[][MAX_DAYS], int[][MAX_DAYS], 
	 float[][MAX_DAYS]);
void selection_sort(int[], int);
void calculate_summary_stats(int[], int[], int[], float[][MAX_DAYS], int[][MAX_DAYS],
	 float[][MAX_DAYS], float[], int[], int[], float[], float[]);
float ratio_pct(int, int);
void write_output_header(ofstream&);
void write_output_data(ofstream&, int[], int[], float[], int[], int[], float[], float[]);

/*****************************************************************************/
//									main()
/*****************************************************************************/
/*******************
	Variables:
********************

int[]		id				- array of patients' id numbers
			measured_max	- array of patients' clinically measured highest HR
			num_days		- array of number of days each patient exercised that week
			age				- array of patients' ages
			est_max_hr		- array of each patient's estiimated max HR
			sorted_ids		- sorted version of the id array
			
int[][]		max_comm		- double array of maximum commuting HR

float[]		week_avg		- array of weekly average HRs for each patient
			ratio_meas_est	- array of ratio between highest measured HR to estimated 
							  highest for each patient
			ratio_high_meas	- array of ratio between max commuting HR to highest 
							  measured for each patient
			
float[][]	avg_comm		- double array of average commuting HR
			exercise_hr		- double array of exercise HR

ifstream	in_file			- the input file

ofstream	out_file		- the output file


*************************
   Invoked Functions:
*************************

1. "get_data" retrieves heart rate data from external file
	a) id number
	b) clinically measured max heart rate
	c) age
	d) 5 days of avg commuting heart rate
	e) 5 days max commuting heart rate
	f) 5 days exercise heart rate

2. "selection_sort" used to sort the ids from least to greatest

3. "calculate_summary_stats" calculates the following:
	 a) weekly average HR
	 b) number of days the patient exercised
	 c) estimated max HR
	 d) ratio of measured max HR to estimated max
	 e) ratio of highest commuting HR to measured max

4. "write_output_header" writes the header of the output file


5. "write_output_line" writes the data to the output file

/*****************************************************************************/

int main_lab7() 
{
	/******************************/
	//		    variable
	/*****************************/
	// int arrays
	int id[MAX_PATIENTS], measured_max[MAX_PATIENTS], age[MAX_PATIENTS],
		num_days[MAX_PATIENTS], est_max_hr[MAX_PATIENTS], sorted_ids[MAX_PATIENTS];


	// float arrays
	float week_avg[MAX_PATIENTS], ratio_meas_est[MAX_PATIENTS],
		  ratio_high_meas[MAX_PATIENTS];

	// double arrays
	int max_comm[MAX_PATIENTS][MAX_DAYS];
	float avg_comm[MAX_PATIENTS][MAX_DAYS], exercise_hr[MAX_PATIENTS][MAX_DAYS];

	ifstream in_file;
	ofstream out_file;


	/******************************/
	//         open files
	/******************************/
	in_file.open("HR.txt");
	out_file.open("HR-summary.txt");

	// check if input file exists, otherwise exit program
	if (in_file.fail())
	{
		out_file << "File does not exist." << endl;
		return -1;
	}

	/******************************/
	//         get input
	/******************************/
	get_data(in_file, sorted_ids, id, measured_max, age, avg_comm, max_comm, exercise_hr);

	// sort ids
	selection_sort(sorted_ids, MAX_PATIENTS);

	/******************************/
	//         calculate
	/******************************/
	calculate_summary_stats(id, measured_max, age, avg_comm, max_comm, exercise_hr, week_avg, num_days,
							est_max_hr, ratio_meas_est, ratio_high_meas);

	/******************************/
	//        output header
	/******************************/
	write_output_header(out_file);

	/******************************/
	//       output summary
	/******************************/
	write_output_data(out_file, id, sorted_ids, week_avg, num_days, est_max_hr, ratio_meas_est, 
					  ratio_high_meas);

	/******************************/
	//	 	  close files
	/******************************/
	in_file.close();
	out_file.close();

	return 0;
}


/*****************************************************************************/
//                             Function definitions 
/*****************************************************************************/

/*****************************************************************************/
//
// Function:	get_data(	ifstream& input, 
//							int id[], 
//							int sort_id[], 
//							int meas[], 
//							int age[], 
//							float avg[][MAX_DAYS], 
//							int max[][MAX_DAYS], 
//							float ex_hr[][MAX_DAYS])
//
// Parameters:	ifstream& input			- reference of the input file
//				int id[]				- array of patients' id numbers
//				int sort_id[]			- array of id numbers to be sorted
//				int meas[]				- array of patients' clinically measured highest HR
//				int age[]				- array of patients' ages
//				float avg[][MAX_DAYS]	- double array of average commuting HR
//				int max[][MAX_DAYS]		- double array of maximum commuting HR
//				float ex_hr[][MAX_DAYS]	- double array of exercise HR
//
// Outputs:		None
//
// Returns:		None
//
// Author:		Audrey Zhu
//
// Date:		2021.05.05
//
// Modifications: None
//
// Description:
// This function prompts the patient id, clinically measuered max HR, and age on the
// first line. The next 5 lines contain the average and maximum commuting HR and the 
// exercise HR of the patient. It keeps doing this for multiple patients until the
// input file ends.
//
/*****************************************************************************/
void get_data(ifstream& input, int id[], int sort_id[], int meas[], int age[], float
	 avg[][MAX_DAYS], int max[][MAX_DAYS], float ex_hr[][MAX_DAYS]) 
{
	// local varibles
	int patient_num = 0;

	while (input.eof() == 0) 
	{
		input >> id[patient_num] >> meas[patient_num] >> age[patient_num];
		sort_id[patient_num] = id[patient_num];
		for (int day = 0; day < MAX_DAYS; day++)
		{
			input >> avg[patient_num][day] >> max[patient_num][day] >> 
				  ex_hr[patient_num][day];
		}
		patient_num++;
	}
}

/*****************************************************************************/
//
// Function:	selection_sort(	int lst[], 
//								int size)
//
// Parameters:	int lst[]	- array to be sorted
//				int size	- size of the array
//
// Outputs:		None
//
// Returns:		None
//
// Author:		Audrey Zhu
//
// Date:		2021.05.05
//
// Modifications: None
//
// Description:
// The function sorts a given array from least to greatest using the selection
// sort algorithm.
//
/*****************************************************************************/
void selection_sort(int lst[], int size) {
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

/*****************************************************************************/
//
// Function:	calculate_summary_stats(int id[], 
//										int meas[], 
//										int age[], 
//										float avg[][MAX_DAYS], 
//										int meas_max[][MAX_DAYS], 
//										float ex_hr[][MAX_DAYS],
//										float wkly_avg[], 
//										int num_days[],
//										int est_max[],
//										float rat_meas_est[], 
//										float rat_hi_meas[])
//
// Parameters:	int id[]					- array of patients' id numbers
//				int meas[]					- array of patients' clinically measured highest HR
//				int age[]					- array of patients' ages
//				float avg[][MAX_DAYS]		- double array of average commuting HR
//				int meas_max[][MAX_DAYS]	- double array of maximum commuting HR
//				float ex_hr[][MAX_DAYS		- double array of exercise HR
//				float wkly_avg[]			- array of weekly average HRs for each patient
//				int num_days[]				- array of number of days each patient exercised
//				int est_max[]				- array of each patient's estiimated max HR
//				float rat_meas_est[]		- array of ratio between highest measured HR to  
//											  estimated highest for each patient
//				float rat_hi_meas[]			- array of ratio between max commuting HR to  
//											  highest measured for each patient
//
// Outputs:		None
//
// Returns:		None
//
// Author:		Audrey Zhu
//
// Date:		2021.05.05
//
// Modifications: None
//
// Description:
// This function calculates the weekly average, estimated max HR, ratio of measured 
// max HR to estimated max HR, and ratio of highest commuting HR to measured max. It
// also finds the number of days each patient exercised on their own. This process
// is repeated for all patients.
//
/*****************************************************************************/
void calculate_summary_stats(int id[], int meas[], int age[], float avg[][MAX_DAYS], 
							 int meas_max[][MAX_DAYS], float ex_hr[][MAX_DAYS], 
							 float wkly_avg[], int num_days[], int est_max[], 
							 float rat_meas_est[], float rat_hi_meas[])
{
	// local variables
	int valid = 0, count = 0, magic_hr_num = 220;
	float sum = 0, max = INT_MAX;

	for (int patient_num = 0; patient_num < MAX_PATIENTS; patient_num++) 
	{
		// calc weekly avg
		valid = 0, sum = 0;
		for (int day = 0; day < MAX_DAYS; day++) 
		{
			if (avg[patient_num][day] != -1)
			{
				valid++;
				sum += avg[patient_num][day];
			}
		}
		wkly_avg[patient_num] = static_cast<float>(sum) / valid;

		// find days exercised
		count = 0;

		for (int day = 0; day < MAX_DAYS; day++)
		{
			if (ex_hr[patient_num][day] != 0)
			{
				count++;
			}
		}
		num_days[patient_num] = count;

		// estimate max heart rate
		est_max[patient_num] = magic_hr_num - age[patient_num];

		// ratio of measure to estimated max
		rat_meas_est[patient_num] = ratio_pct(meas[patient_num], est_max[patient_num]);

		// ratio of highest to measured max
		// find max 
		max = 0;
		for (int day = 0; day < MAX_DAYS; day++)
		{
			if (meas_max[patient_num][day] > max)
			{
				max = meas_max[patient_num][day];
			}
		}

		rat_hi_meas[patient_num] = ratio_pct(max, meas[patient_num]);

	}
}

/*****************************************************************************/
//
// Function:	ratio_pct(	int top, 
//							int bottom)
//
// Parameters:	int top		- top of the ratio
//				int bottom	- bottom of the ratio
//
// Outputs:    None
//
// Returns:    float - the ratio of top to bottom 
//
// Author:     Audrey Zhu
//
// Date:       2021.05.05
//
// Modifications: None
//
// Description:
// This function takes the ratio of 2 numbers, top and bottom. It basically 
// decimal point of top divided by bottom.
//
/*****************************************************************************/
float ratio_pct(int top, int bottom) 
{
	return (static_cast<float>(top) / bottom) * 100;
}

/*****************************************************************************/
//
// Function:	write_output_header(ofstream& output)
//
// Parameters:	ofstream& output	- reference of the output file
//
// Outputs:		None
//
// Returns:		None
//
// Author:		Audrey Zhu
//
// Date:		2021.05.05
//
// Modifications: None
//
// Description:
// This function writes the header of the output file.
//
/*****************************************************************************/
void write_output_header(ofstream& output)
{

	const int COL1 = 10, COL2 = 12, COL3 = 12, COL4 = 12, COL5 = 16, COL6 = 20;

	output << setprecision(1) << left << fixed;
	output << setw(COL1 + COL2 + COL3 + COL4 + COL5 + COL6) 
		   << "COMMUTING AND EXERCISE HEART RATE SUMMARY" << endl << endl;

	// line 1 of table header
	output << setw(COL1) << "SUBJECT" 
		   << setw(COL2) << " AVERAGE" 
		   << setw(COL3) << "  DAYS" 
		   << setw(COL4) << "ESTIMATED"
		   << setw(COL5) << " MEASURED TO" 
		   << setw(COL6) << "MAX COMMUTING" << endl;

	// line 2 of table header
	output << setw(COL1) << "NUMBER"
		   << setw(COL2) << "COMMUTING"
	   	   << setw(COL3) << "EXERCISED"
		   << setw(COL4) << "MAX HEART"
		   << setw(COL5) << "ESTIMATED MAX"
		   << setw(COL6) << "HEART RATE TO" << endl;

	// line 3 of table header
	output << setw(COL1) << "  "
		   << setw(COL2) << "HEART RATE"
		   << setw(COL3) << " "
		   << setw(COL4) << " "
		   << setw(COL5) << " HEART RATE"
		   << setw(COL6) << "  MEASURED" << endl;

}

/*****************************************************************************/
//
// Function:	write_output_data(	ofstream& output, 
//									int ids[], 
//									int sorted[], 
//									float wkly_avg[], 
//									int num_days[], 
//									int est_max[], 
//									float rat_meas_est[], 
//									float rat_hi_meas[])
//
// Parameters:	ofstream& output		- reference of the output file
//				int ids[]				- array of patients' id numbers
//				int sorted[]			- sorted version of the id array
//				float wkly_avg[]		- array of weekly average HRs for each patient
//				int num_days[]			- array of number of days each patient exercised
//				int est_max[]			- array of each patient's estiimated max HR
//				float rat_meas_est[]	- array of ratio between highest measured HR to estimated 
//										  highest for each patient
//				float rat_hi_meas[]		- array of ratio between max commuting HR to highest 
//										  measured for each patient
//
// Outputs:		None
//
// Returns:		None
//
// Author:		Audrey Zhu
//
// Date:		2021.05.05
//
// Modifications: None
//
// Description:
// This function writes the calculations to the output file in an organized 
// and neat format.
//
/*****************************************************************************/
void write_output_data(ofstream& output, int ids[], int sorted[], float wkly_avg[], 
	int num_days[], int est_max[], float rat_meas_est[], float rat_hi_meas[]) 
{
	// local variables
	const int COL1 = 5, COL2 = 12, COL3 = 10, COL4 = 13, COL5 = 14, COL6 = 15;
	int indx;

	// set precision and alignment
	output << setprecision(1) << right << fixed;

	for (int patient_num = 0; patient_num < MAX_PATIENTS; patient_num++) 
	{
		// in case there are extra entries in array that aren't filled up
		if (sorted[patient_num] > 0) 
		{
			// find the index of it in the parallel arrays
			for (int i = 0; i < MAX_PATIENTS; i++) {
				if (sorted[patient_num] == ids[i])
					indx = i;
			}

			// print indx-th index of all arrays
			// printing out 1 line
			output << setw(COL1) << ids[indx]
				<< setw(COL2) << wkly_avg[indx]
				<< setw(COL3) << num_days[indx]
				<< setw(COL4) << est_max[indx]
				<< setw(COL5) << rat_meas_est[indx] << "%"
				<< setw(COL6) << rat_hi_meas[indx] << "%" << endl;
		}

	}

}

