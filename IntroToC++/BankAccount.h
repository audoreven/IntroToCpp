#pragma once
class BankAccount
{

    public:
        
        //Constructs a bank account with zero balance.
        BankAccount();

        /**
        Makes a deposit into this account.
        @param amount the amount of the deposit.
        */
        void deposit(double amount);

        // might need it to be virtual if future bank policy changed:
        //virtual void deposit(double amount);


        /**
        Makes a withdrawal from this account, or charges a penalty if
        sufficient funds are not available.
        @param amount the amount of the withdrawal.
        */
        virtual void withdraw(double amount);

        /**
        Carries out the end of month processing that is appropriate
        for this account.
        */
        virtual void month_end();


        /**
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

        /**
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
    if (get_balance() - amount > min_balance) {
        BankAccount::withdraw(amount);
    }
}

 void SavingsAccount::month_end()
 {
    /* YOUR CODE HERE*/
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
    
    if (withdrawals > FREE_WITHDRAWALS) {
        BankAccount::withdraw(WITHDRAWAL_FEE);
    }
    BankAccount::withdraw(amount);
}

void CheckingAccount::month_end()
{
    /* YOUR CODE HERE*/
}
