#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/****************************************/
//        Base  Class Definitions
/****************************************/
class BankAccount
{

public:

    //Constructs a bank account with zero balance.
    BankAccount();

    /*
    Makes a deposit into this account.
    @param amount the amount of the deposit.
    */
    void deposit(double amount);

    // might need it to be virtual if future bank policy changed:
    //virtual void deposit(double amount);


    /*
    Makes a withdrawal from this account, or charges a penalty if
    sufficient funds are not available.
    @param amount the amount of the withdrawal.
    */
    virtual void withdraw(double amount);

    /*
    Carries out the end of month processing that is appropriate
    for this account.
    */
    virtual void month_end();


    /*
    Gets the current balance of this bank account.
    @return the current balance
    */
    double get_balance() const;

private:
    double balance;

};


/****************************************/
//      Derived Class Definitions
/****************************************/
class SavingsAccount : public BankAccount
{
public:

    //Constructs a savings account with a zero balance

    SavingsAccount();

    /*
    Sets the interest rate for this account.
    @param rate the monthly interest rate in percent
    */
    void set_interest_rate(double rate);
    virtual void withdraw(double amount);
    virtual void month_end();
private:
    double interest_rate;
    double min_balance;
};

/****************************************/

class CheckingAccount : public BankAccount
{
public:
    // Constructs a checking account with a zero balance.
    CheckingAccount();
    virtual void withdraw(double amount);
    virtual void month_end();
private:
    int withdrawals;
};


/*****************************************************************************/
//
//								int main( void )
//
/*****************************************************************************/
int main_account()
{
    cout << fixed << setprecision(2);

    // Create accounts
    const double MONTHLY_INTEREST_RATE = 0.75;
    const int NUM_OF_ACCOUNTS = 10;
    BankAccount* accounts[NUM_OF_ACCOUNTS];
    for (int i = 0; i < NUM_OF_ACCOUNTS / 2; i++)
    {
        accounts[i] = new CheckingAccount;
    }
    for (int i = NUM_OF_ACCOUNTS / 2; i < NUM_OF_ACCOUNTS; i++)
    {
        SavingsAccount* account = new SavingsAccount;
        account->set_interest_rate(MONTHLY_INTEREST_RATE);
        accounts[i] = account;
    }

    for (int i = NUM_OF_ACCOUNTS; i < NUM_OF_ACCOUNTS; i++) {
        cout << accounts[i]<< endl;
    }

    // Execute commands
    bool query = true;
    while (query)
    {
        cout << "D)eposit  W)ithdraw  M)onth end  Q)uit: ";
        string input;
        cin >> input;
        cout << endl;

        if (input == "D" || input == "d" || input == "W" || input == "w") // Deposit or withdrawal
        {
            cout << "Enter account number and amount: ";
            int num;
            double amount;
            cin >> num >> amount;
            cout << endl;

            if (input == "D" || input == "d")
            {
                accounts[num]->deposit(amount);
            }
            else
            {
                accounts[num]->withdraw(amount);
            }

            cout << "Balance: " << accounts[num]->get_balance() << endl;
        } // if (input is D or W)

        else if (input == "M" || input == "m") // Month end processing
        {
            for (int n = 0; n < NUM_OF_ACCOUNTS; n++)
            {
                accounts[n]->month_end();
                cout << n << " " << accounts[n]->get_balance() << endl;
            }
        }
        else if (input == "Q" || input == "q")
        {
            query = false;
        }

        cout << endl << endl;
    } // end of while(more)

    return 0;
}



/****************************************/
//          Base Class Function
/****************************************/

BankAccount::BankAccount()
{
    balance = 0;
}

void BankAccount::deposit(double amount)
{
    balance = balance + amount;
}

void BankAccount::withdraw(double amount)
{
    balance = balance - amount;
}

void BankAccount::month_end()
{
}

double BankAccount::get_balance() const
{
    return balance;
}


/*****************************************************************************/
// Derived Class functions
/*****************************************************************************/
SavingsAccount::SavingsAccount()
{
    interest_rate = 0;
    min_balance = 0;
}

void SavingsAccount::set_interest_rate(double rate)
{
    interest_rate = rate;
}

void SavingsAccount::withdraw(double amount)
{
    BankAccount::withdraw(amount);
    if (get_balance() < min_balance) {
        min_balance = get_balance();
    }
}

void SavingsAccount::month_end()
{
    BankAccount::deposit((interest_rate/100.0) * min_balance);
    min_balance = get_balance();
}

/*****************************************************************************/

CheckingAccount::CheckingAccount()
{
    withdrawals = 0;
}

void CheckingAccount::withdraw(double amount)
{
    const int FREE_WITHDRAWALS = 3;
    const int WITHDRAWAL_FEE = 1;

    if (++withdrawals > FREE_WITHDRAWALS) {
        BankAccount::withdraw(WITHDRAWAL_FEE);
    }
    BankAccount::withdraw(amount);
}

void CheckingAccount::month_end()
{
    withdrawals = 0;
}
