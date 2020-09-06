#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

class Client
{
	public:
		Client();
		Client(std::string fn, std::string ln, std::string address, std::string c, std::string s, int z, int social) : first_name(fn), last_name(ln), street_address(address), city(c), state(s), zip(z), ssn(social) {};
		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_street_address() const;
		std::string get_city() const;
		std::string get_state() const;
		int get_zip() const;
		int get_ssn() const;
		void set_first_name(std::string);
		void set_last_name(std::string);
		void set_street_address(std::string);
		void set_city(std::string);
		void set_state(std::string);
		void set_zip(int);
		void set_ssn(int);
		std::string to_string() const;
		bool operator<(const Client&) const;
		friend std::ostream& operator<<(std::ostream&, const Client&);
				
	private:
		std::string first_name;
		std::string last_name;
		std::string street_address;
		std::string city;
		std::string state;
		int zip;
		int ssn;
};

#endif
