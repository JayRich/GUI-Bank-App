#include "Bank.h"

Bank::Bank()
{
	name = "";
	fdic_number = 0;
}

std::string Bank::get_name()
{
	return name;
}

int Bank::get_fdic_number()
{
	return fdic_number;
}

void Bank::set_name(std::string n)
{
	name = n;
}

void Bank::set_fdic_number(int fdic)
{
	fdic_number = fdic;
}

void Bank::add_account(int account_number, double balance, double rate, double fee, int owner)
{
	accounts.push_back(Account(account_number, balance, rate, fee, owner));
}

void Bank::close_account(int account_number, int owner)
{
	for(auto it = accounts.begin(); it != accounts.end(); it++)
	{
		if(it->get_account_number() == account_number)
		{
			if(it->get_owner() == owner)
			{
				accounts.erase(it);
				return;
			}
			else
			{
				std::cout << "Client does not have access to this account to close it" << std::endl;
			}
		}
	}
}

void Bank::add_client(std::string first_name, std::string last_name, std::string street_address, std::string city, std::string state, int zip, int ssn)
{
	clients.push_back(Client(first_name, last_name, street_address, city, state, zip, ssn));
}

Account* Bank::get_account(int account_number)
{
	Account* account;
	for(auto it = accounts.begin(); it != accounts.end(); it++)
	{
		if(it->get_account_number() == account_number)
		{
			account = &(*it);
			 
		}
	}
	return account;
}

Client* Bank::get_client(int ssn)
{
	Client* client;
	for(auto it = clients.begin(); it != clients.end(); it++)
	{
		if(it->get_ssn() == ssn)
		{
			client = &(*it);
		}
	}
	return client;
}

double Bank::deposit(double amount, int account_number, int client_ssn)
{
	Account* account = get_account(account_number);
	if(account->get_owner() != client_ssn)
	{
		std::cout << "Client does not have access to this account." << std::endl;
		return -999;
	}
	return account->deposit(amount);	
}

double Bank::withdraw(double amount, int account_number, int client_ssn)
{
	Account* account = get_account(account_number);
	if(account->get_owner() != client_ssn)
	{
		std::cout << "Client does not have access to this account." << std::endl;
		return -999;
	}
	return account->withdrawl(amount);	
}

void Bank::end_of_month()
{
	for(auto it = accounts.begin(); it != accounts.end(); it++)
	{
		it->end_of_month();
	}
}

double Bank::merge(int account_number1, int account_number2, int client_ssn)
{
	Account* account1 = get_account(account_number1);
	Account* account2 = get_account(account_number2);
	if((account1->get_owner() != client_ssn) && (account2->get_owner() != client_ssn))
	{
		std::cout << "Client does not have access to one of these accounts." << std::endl;
		return -999;
	}
	double amount = account2->withdrawl(account2->get_balance());
	close_account(account_number2, client_ssn);
	return account1->deposit(amount);
}

std::ostream& operator<<(std::ostream& ost, const Bank& bank)
{
	ost << bank.name << ", " << bank.fdic_number << std::endl;
	
	ost << "-------" << std::endl;
	
	for(auto client_it = bank.clients.begin(); client_it != bank.clients.end(); client_it++)
	{
		ost << *client_it << std::endl;
		for(auto account_it = bank.accounts.begin(); account_it != bank.accounts.end(); account_it++)
		{
			if(account_it->get_owner() == client_it->get_ssn())
			{
				ost << *account_it << std::endl;
			}
		}
		
		ost << "-------" << std::endl;
	}
	
	return ost;
}
