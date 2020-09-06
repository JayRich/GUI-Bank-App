#include "Client.h"

Client::Client()
{
	first_name = "";
	last_name = "";
	street_address = "";
	city = "";
	state = "";
	zip = 0;
	ssn = 0;
}

std::string Client::get_first_name() const
{
	return first_name;
}

std::string Client::get_last_name() const
{
	return last_name;
}

std::string Client::get_street_address() const
{
	return street_address;
}

std::string Client::get_city() const
{
	return city;
}

std::string Client::get_state() const
{
	return state;
}

int Client::get_zip() const
{
	return zip;
}

int Client::get_ssn() const
{
	return ssn;
}

void Client::set_first_name(std::string fn)
{
	first_name = fn;
}

void Client::set_last_name(std::string ln)
{
	last_name = ln;
}

void Client::set_street_address(std::string address)
{
	street_address = address;
}

void Client::set_city(std::string c)
{
	city = c;
}

void Client::set_state(std::string s)
{
	state = s;
}

void Client::set_zip(int z)
{
	zip = z;
}

void Client::set_ssn(int s)
{
	ssn = s;
}

std::string Client::to_string() const
{
	return first_name + "," + last_name + "," + street_address + "," + city + "," + state + "," + std::to_string(zip) + "," + std::to_string(ssn);
}

bool Client::operator<(const Client& rhs) const
{
	return (this->ssn < rhs.get_ssn());
}

std::ostream& operator<<(std::ostream& ost, const Client& client)
{
	ost << client.first_name << ", " << client.last_name << ", " << client.street_address << ", " << client.city << ", " << client.state << ", " << std::to_string(client.zip) << ", " << std::to_string(client.ssn);
	
	return ost;
}
