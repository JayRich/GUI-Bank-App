#include "Main_Window.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Main_Window::Main_Window()
{
	set_default_size(400,200);
	
	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);
    
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_quit_click));
    filemenu->append(*menuitem_quit);


	 Gtk::MenuItem *menuitem_client = Gtk::manage(new Gtk::MenuItem("_Client", true));
    menubar->append(*menuitem_client);
    Gtk::Menu *clientmenu = Gtk::manage(new Gtk::Menu());
    menuitem_client->set_submenu(*clientmenu);
    
   Gtk::MenuItem *menuitem_add_client = Gtk::manage(new Gtk::MenuItem("_Add_Client", true));
    menuitem_add_client->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_add_client_click));
    clientmenu->append(*menuitem_add_client);

	   Gtk::MenuItem *menuitem_get_client = Gtk::manage(new Gtk::MenuItem("_Get_Client", true));
    menuitem_get_client->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_get_client_click));
    clientmenu->append(*menuitem_get_client);


	 Gtk::MenuItem *menuitem_accounts = Gtk::manage(new Gtk::MenuItem("_Accounts", true));
    menubar->append(*menuitem_accounts);
    Gtk::Menu *accountsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_accounts->set_submenu(*accountsmenu);

 Gtk::MenuItem *menuitem_add_account = Gtk::manage(new Gtk::MenuItem("_Add_Account", true));
    menuitem_add_account->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_add_account_click));
    accountsmenu->append(*menuitem_add_account);

	 Gtk::MenuItem *menuitem_get_account = Gtk::manage(new Gtk::MenuItem("_Get_Account", true));
    menuitem_get_account->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_get_account_click));
    accountsmenu->append(*menuitem_get_account);


	Gtk::MenuItem *menuitem_operations = Gtk::manage(new Gtk::MenuItem("_Operations", true));
    menubar->append(*menuitem_operations);
    Gtk::Menu *operationsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_operations->set_submenu(*operationsmenu);

	 Gtk::MenuItem *menuitem_deposit = Gtk::manage(new Gtk::MenuItem("_Deposit", true));
    menuitem_deposit->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_deposit_click));
    operationsmenu->append(*menuitem_deposit);

	 Gtk::MenuItem *menuitem_withdraw = Gtk::manage(new Gtk::MenuItem("_Withdraw", true));
    menuitem_withdraw->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_withdraw_click));
    operationsmenu->append(*menuitem_withdraw);

	 Gtk::MenuItem *menuitem_end_of_month = Gtk::manage(new Gtk::MenuItem("_End_of_Month", true));
    menuitem_end_of_month->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_end_of_month_click));
    operationsmenu->append(*menuitem_end_of_month);

	 Gtk::MenuItem *menuitem_auto_populate = Gtk::manage(new Gtk::MenuItem("_Auto_Populate", true));
    menuitem_auto_populate->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_auto_populate_click));
    filemenu->append(*menuitem_auto_populate);

	 Gtk::MenuItem *menuitem_close_account = Gtk::manage(new Gtk::MenuItem("_Close_Account", true));
    menuitem_close_account->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_close_account_click));
    operationsmenu->append(*menuitem_close_account);

		 Gtk::MenuItem *menuitem_merge_accounts = Gtk::manage(new Gtk::MenuItem("_Merge_Accounts", true));
    menuitem_merge_accounts->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_merge_click));
    operationsmenu->append(*menuitem_merge_accounts);

	Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menuitem_view->signal_activate().connect(sigc::mem_fun(*this, &Main_Window::on_view_click));
    operationsmenu->append(*menuitem_view);




   
    
    vbox->show_all();
}

Main_Window::~Main_Window()
{
}

void Main_Window::on_quit_click()
{
	hide();
}

void Main_Window::on_add_client_click()
{
	
	std::string fname, lname, address, city, state, zip_temp, ssn_temp;
	
	int zip, ssn;
	
	fname = Dialogs::input("Client's First Name", "Input", "");

	lname = Dialogs::input("Client's Last Name", "Input", "");
	
	address = Dialogs::input("Client's Street Address", "Input", "");
	
	city = Dialogs::input("Client's City", "Input", "");
	
	state = Dialogs::input("Client's State (2 Letter Abbreviation)", "Input", "");

	zip_temp = Dialogs::input("Client's Zip Code (5 digit)", "Input", "");

	ssn_temp = Dialogs::input("Client's SSN", "Input", "");

	zip = std::stoi(zip_temp);

	ssn = std::stoi(ssn_temp);
	
	bank.add_client(fname, lname, address, city, state, zip, ssn);
}


void Main_Window::on_get_client_click()
{
	Client c1;
	
	int owner;
	std::string owner_temp;

	owner_temp = Dialogs::input("Owner SSN", "Input", "");

	owner = std::stoi(owner_temp);

	
	c1 = *bank.get_client(owner);
	Dialogs::message(c1.get_first_name(), "first name");
	Dialogs::message(c1.get_last_name(), "last name");
	Dialogs::message(c1.get_street_address(), "address");
	Dialogs::message(c1.get_city(), "city");
	Dialogs::message(c1.get_state(), "state");
	Dialogs::message(to_string(c1.get_zip()), "zip");
	Dialogs::message(to_string(c1.get_ssn()), "ssn");
}


void Main_Window::on_add_account_click()
{
	std::string number_temp, owner_temp, balance_temp, rate_temp, fee_temp;
	
	number_temp = Dialogs::input("Account Number", "Input", "");

	owner_temp = Dialogs::input("Owner SSN", "Input", "");
	
	balance_temp = Dialogs::input("Balance", "Input", "");
	
	rate_temp = Dialogs::input("Rate", "Input", "");
	
	fee_temp = Dialogs::input("Fee", "Input", "");

	int number, owner;
	double balance, rate, fee;

	number = std::stoi(number_temp);
	owner = std::stoi(owner_temp);
	balance = std::stod(balance_temp);
	rate = std::stod(rate_temp);
	fee = std::stod(fee_temp);

	
	bank.add_account(number, balance, rate, fee, owner);
}


void Main_Window::on_get_account_click()
{
	Account a1;
	int account;
	std::string account_temp;

	account_temp = Dialogs::input("Account Number", "Input", "");
	account = std::stoi(account_temp);
	
	 a1 = *bank.get_account(account);

	Dialogs::message(to_string(a1.get_account_number()), "account number");
	Dialogs::message(to_string(a1.get_balance()), "balance");
	Dialogs::message(to_string(a1.get_rate()), "rate");
	Dialogs::message(to_string(a1.get_fee()), "fee");
	Dialogs::message(to_string(a1.get_owner()), "owner SSN");
	
}


void Main_Window::on_deposit_click()
{
	double amount;
	int account, owner;
	
	std::string amount_temp, account_temp, owner_temp;	

	amount_temp = Dialogs::input("Deposit Amount", "Input", "");
	
	account_temp = Dialogs::input("Account Number", "Input", "");
	
	owner_temp = Dialogs::input("Owner SSN", "Input", "");
	
	amount = std::stod(amount_temp);
	account = std::stoi(account_temp);
	owner = std::stoi(owner_temp);
	
	
	Dialogs::message(to_string(bank.deposit(amount, account, owner)), "New Amount");
}

void Main_Window::on_withdraw_click()
{
	double amount;
	int account, owner;
	std::string amount_temp, account_temp, owner_temp;
	
	amount_temp = Dialogs::input("Withdraw Amount", "Input", "");

	account_temp = Dialogs::input("Account Number", "Input", "");
	
	owner_temp = Dialogs::input("Owner SSN", "Input", "");

	amount = std::stod(amount_temp);
	account = std::stoi(account_temp);
	owner = std::stoi(owner_temp);
	
	Dialogs::message(to_string(bank.withdraw(amount, account, owner)), "New Amount");
}


void Main_Window::on_end_of_month_click()
{
	bank.end_of_month();
}

void Main_Window::on_auto_populate_click()
{
	bank.add_client("John", "Doe", "123 Anystreet", "Anytown", "TX", 12345, 111223333);
	bank.add_client("Jane", "Doe", "123 Anystreet Dr.", "Anytown", "TX", 12345, 222334444);
	
	bank.add_account(123, 500, 1, 5, 111223333);
	bank.add_account(456, 1000, 1, 5, 111223333);
	bank.add_account(789, 1500, 1, 5, 222334444);
}

void Main_Window::on_close_account_click()
{
	int account, owner;
	std::string account_temp, owner_temp;

	account_temp = Dialogs::input("Account Number", "Input", "");
	
	owner_temp = Dialogs::input("Owner SSN", "Input", "");

	account = std::stoi(account_temp);
	owner = std::stoi(owner_temp);

	bank.close_account(account, owner);
}


void Main_Window::on_merge_click()
{
	int account1, account2, owner;
	
	std::string account1_temp, account2_temp, owner_temp;

	account1_temp = Dialogs::input("First Account Number", "Input", "");

	account2_temp = Dialogs::input("Second Account Number", "Input", "");

	owner_temp = Dialogs::input("Owner SSN", "Input", "");

	account1 = std::stoi(account1_temp);
	account2 = std::stoi(account2_temp);
	owner = std::stoi(owner_temp);
	
	bank.merge(account1, account2, owner);
}

void Main_Window::on_view_click()
{
	
	cout << bank << endl;
}




