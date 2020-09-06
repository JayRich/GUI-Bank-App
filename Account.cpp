#include "Account.h"

Account::Account()
{
	account_number = 0;
	balance = 0.0;
	rate = 0.0;
	fee = 0.0;
	owner = 0;
}

int Account::get_account_number() const
{
	return account_number;
}

double Account::get_balance() const
{
	return balance;
}

double Account::get_rate() const
{
	return rate;
}

double Account::get_fee() const
{
	return fee;
}

int Account::get_owner() const
{
	return owner;
}

void Account::set_account_number(int n)
{
	account_number = n;
}

void Account::set_balance(double b)
{
	balance = b;
}

void Account::set_rate(double r)
{
	rate = r;
}

void Account::set_fee(double f)
{
	fee = f;
}

void Account::set_owner(int o)
{
	owner = o;
}

double Account::deposit(double amount)
{
	balance += amount;
}

double Account::withdrawl(double amount)
{
	balance -= amount;
	
}

double Account::end_of_month()
{
	balance -= fee;
	balance += (balance * rate) / 12;
	return balance;
}

std::string Account::to_string() const
{
	return std::to_string(account_number) + ", " + std::to_string(balance) + ", " + std::to_string(fee) + ", " + std::to_string(rate) + ", " + std::to_string(owner); 
}

bool Account::operator<(const Account& rhs)
{
	return (this->account_number < rhs.get_account_number());
}

std::ostream& operator<<(std::ostream& ost, const Account& account)
{
	ost << account.account_number << "," << account.balance << "," << account.fee << "," << account.rate << "," << account.owner;
}
