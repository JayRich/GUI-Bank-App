#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include "Client.h"
#include <vector>

class Bank
{
	public:
		Bank();
		Bank(std::string n, int fdic) : name(n), fdic_number(fdic) {};
		std::string get_name();
		int get_fdic_number();
		void set_name(std::string);
		void set_fdic_number(int);
		void add_client(std::string, std::string, std::string, std::string, std::string, int, int);
		void add_account(int, double, double, double, int);
		void close_account(int, int);
		Account* get_account(int);
		Client* get_client(int);
		double deposit(double, int, int);
		double withdraw(double, int, int);
		void end_of_month();
		double merge(int, int, int);
		friend std::ostream& operator<< (std::ostream&, const Bank&);
	private:
		std::string name;
		int fdic_number;
		std::vector<Account> accounts;
		std::vector<Client> clients;
};

#endif
