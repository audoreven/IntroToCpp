/*****************************************************************************/
//  Filename:      vectors_of_obj.cpp
//
//  Description:
//    
//    The program carries out the following tasks, sequentially:
//
//    1. Create a number of resistor and capacitor objects; and then put the
//       resistor object references into one "vector" and the capacitor into
//       another one.
//    2. Queries the user to select a pair of resistor and capacitor values.
//    3. User the user selection input number, with minor adjustment, to index
//       each vector to get the corresponding pair of resistance and
//       capacitance value through calling the get_() functions
//    4. Use the resistor and capacitor values from the get_() functions to run
//       RC step response simulation; and output the simulated results
//
/*****************************************************************************/

/**************************/
// Preprocessor Directives
/**************************/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;


/**************************/
// Classes Definitions
/**************************/
class Resistor
{
public:
    Resistor(double res_in);

    double get_resistance(void) const;

private:
    double resistance;
}; // end class Resistor

class Capacitor
{
public:
    Capacitor(double cap_in);

    double get_capacitance(void) const;

private:
    double capacitance;
}; // end class Capacitor


/**************************/
// Function Prototype
/**************************/
double calc_step_resp(double v0, double ohm, double uF, int t_us);



/**************************************************************************/
//                                 main()
/**************************************************************************/

int main_vc()
{
    const int NUM_OF_RC_CIRCUITS = 3;
    double resistor_array[NUM_OF_RC_CIRCUITS] = { 330, 500, 670 };
    double capacitor_array[NUM_OF_RC_CIRCUITS] = { 0.1, 0.25, 0.5 };
    int resistor_selected = 1, capacitor_selected = 1;
    double r_of_RC, c_of_RC;
    double t_final = 100;
    double delta_t = 10;
    double v0 = 12;

    
    /***************************************************************/
    /***************************************************************/
    // Your task #1:
    //
    // 1. Define one vector of Resistor objects here
    // 2. Define one vector of Capacitor objects here
    //

    // vectors:
    vector<Resistor> resistor_vector;
    vector<Capacitor> capacitor_vector;

    /***************************************************************/
    /***************************************************************/



    for (int idx = 0; idx < NUM_OF_RC_CIRCUITS; idx++)
    {
        /**************************************************************************/
        /**************************************************************************/
        // Your task #2:
        //
        // 1. Instantiate a Resistor object, initialize its member(the resistance)
        //    using the resistance value from the resistor_array and idx

        // 2. Instantiate a Capacitor object, initialize its member(the capacitance)
        //    using the capacitance value from the capacitor_array and idx
        //
        // 3. Fill the vector of resistors with the resistor object by 
        //    using the .push_back method
        //
        // 4. Fill the vector of capacitors with the capacitor object by
        //    using the .push_back method
        //

        Resistor r = Resistor(resistor_array[idx]);
        Capacitor c = Capacitor(capacitor_array[idx]);

        resistor_vector.push_back(r);
        capacitor_vector.push_back(c);

        /**************************************************************************/
        /**************************************************************************/

    }

    cout << "Which resistor do you want to use? (enter a number between 1 and 3) - ";
    cin >> resistor_selected;
    cout << endl;
    cout << "Which capacitor do you want to use? (enter a number between 1 and 3) - ";
    cin >> capacitor_selected;
    cout << endl;


    /***********************************************************************/
    // Iterate the simulation runs and output each result to the output data
    // file, until the simulated time reaches t_final
    /***********************************************************************/
    for (int idx = 1, us_time = 0; us_time <= t_final; idx++, us_time += delta_t)
    {
        /***********************************************************************/
        /***********************************************************************/
        // Your task #3:
        //
        // Complete the statement below by using the vector of resistor objects
        // and the vector of capacitor objects and each's get_...() functions to
        // get the argument values for the calc_step_resp() function call
        //

        cout << setprecision(5) << fixed;
        cout << setw(5) << right << idx << setw(16) << us_time << setw(16)
             << calc_step_resp(v0, resistor_vector[resistor_selected-1].get_resistance(), 
                               capacitor_vector[capacitor_selected-1].get_capacitance(), us_time)
             << endl;  // simulation takes place when calc_step_resp() is called


         /***********************************************************************/
         /***********************************************************************/
    }

    return 0;
}
/**************************************************************************/
//                             End of main()
/**************************************************************************/



/*****************************************************************************/
//  Function:     double calc_step_resp(double v0, double ohm, 
//                                      double uF, int t_us)
//
//  Inputs:       double v0   -  Supply Voltage - v0
//                double ohm  -  Resistance in ohms - R
//                double uF   -  Capacitance in uF - C
//                int t_us    -  simulated time measured from the start of
//                               simulation - t
//  Outputs:      none
//
//  Returns:      double      - v(t), voltage value across the capacitor
//
//
//  Description:  This function calculate v(t) for the RC circuit charging
//                equation:
//
//                v(t) = v0 * ( 1 - e^(-t/RC) )
//
/*****************************************************************************/
double calc_step_resp(double v0, double ohm, double uF, int t_us)
{
    return v0 * (1 - exp(-1.0 * t_us / (uF * ohm)));
}


///////////////////////////////////////////////////////////////////////////////
//  Function:      Resistor::Resistor ( double res_init )
//
//  Inputs:        double res_init  - initial value of resistance
//
//  Outputs:       None
//
//  Returns:       None
//
//  Description:  This constructor accepts the initial value for the private 
//                member resistance 
///////////////////////////////////////////////////////////////////////////////
Resistor::Resistor(double res_init)
{
    resistance = res_init;
}


///////////////////////////////////////////////////////////////////////////////
//  Function:      double Resistor::get_resistance( void )
//
//  Inputs:        None
//
//  Outputs:       None
//
//  Returns:       double - resistance value
//
//  Description:   This function returns the resistance value of the resistor.
///////////////////////////////////////////////////////////////////////////////
double Resistor::get_resistance(void) const
{
    return resistance;
}


///////////////////////////////////////////////////////////////////////////////
//  Function:      Capacitor::Capacitor( double cap_init )
//
//  Inputs:        double cap_init  - initial value of capacitance
//
//  Outputs:       None
//
//  Returns:       None
//
//  Description:  This constructor accepts the initial value for the private 
//                member capacitance 
///////////////////////////////////////////////////////////////////////////////
Capacitor::Capacitor(double cap_init)
{
    capacitance = cap_init;
}


///////////////////////////////////////////////////////////////////////////////
//  Function:      double Capacitor::get_capacitance( void ) const
//
//  Inputs:        None
//
//  Outputs:       None
//
//  Returns:       double - capacitance value
//
//  Description:   This function returns the capacitance value of the resistor.
///////////////////////////////////////////////////////////////////////////////
double Capacitor::get_capacitance(void) const
{
    return capacitance;
}