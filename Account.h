#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account
{
	public:
		Account();
		Account(int n, double b, double r, double f, int o) : account_number(n), balance(b), rate(r), fee(f), owner(o) {};
		int get_account_number() const;
		double get_balance() const;
		double get_fee() const;
		double get_rate() const;
		int get_owner() const;
		void set_account_number(int);
		void set_balance(double);
		void set_fee(double);
		void set_rate(double);
		void set_owner(int);
		double deposit(double);
		double withdrawl(double);
		double end_of_month();
		std::string to_string() const;
		bool operator<(const Account&);
		friend std::ostream& operator<<(std::ostream&, const Account&);
		
	private:
		int account_number;
		double balance;
		double rate;
		double fee;
		int owner;
};

#endif
