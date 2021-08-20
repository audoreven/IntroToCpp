//  This program demonstrates the use of characters, strings, integers and floating point
//  Audre Zhu

#include <iostream>
#include <string>

using namespace std;

int main_data()
{
    // Declaration of constants
    const string FAVORITESODA = "Dr. Dolittle";  //  use double quotes for strings
    const int NUMBER_SURVEYED = 1000;   //
    char rating; // A, B, C product rating
    string favoriteSnack; // most preferred snack
    int numberOfPeople; // the number of people in the survey
    float price; //price of snack

    //  Fill in the code to do the following:

    //  Assign avalue to favoriteSnack
    favoriteSnack = "Takis";

    //  Assign a grade of 'B' to rating
    rating = 'B';

    //  Assign the number 202 to the numberOfPeople
    numberOfPeople = 202;

    //  Assign the number 2.49 to the price
    price = 2.49;

    // Fill in the blanks of the following with identifiers:

    cout << "The preferred soda is " << FAVORITESODA << endl;
    cout << sizeof(FAVORITESODA) << endl;

    cout << "The preferred snack is " << favoriteSnack << endl;

    cout << "Out of " << NUMBER_SURVEYED << " people "

        << numberOfPeople << " chose these items!" << endl;

    cout << "Each of these products were given a rating of " << rating;

    cout << " from our expert tasters" << endl;

    cout << "The other products were rated no higher than a " << char(rating + 1) << endl;
        
    system("pause");

    return 0;
}