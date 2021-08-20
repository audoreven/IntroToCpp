#include <iostream>
#include <ctime>

using namespace std;


void add_one(int& total)
{
    total++;
}


int main_rand()
{
    float rand_num;
    int num = 0;

    srand(unsigned(time(0)));

    for (int idx = 1; idx < 10; idx++)
    {
        rand_num = static_cast<float>(rand()) / RAND_MAX;  // RAND_MAX is provided by the c-library
        cout << rand_num << endl;
    }
    // int numbers[4] = { 99, 87 };
    // cout << numbers[3] << endl;

    int numbers[] = { 99, 87, 66, 55, 101 };
    cout << numbers[3] << endl;

    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += i;
    }
    cout << sum << endl;

    return 0;
}