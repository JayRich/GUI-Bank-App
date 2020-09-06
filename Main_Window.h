#include <gtkmm.h>
#include "dialog.h"
#include "Bank.h"


class Main_Window : public Gtk::Window
{
	public:
		Main_Window();
		virtual ~Main_Window();
	private:
		void on_quit_click();
		void on_add_client_click();
		void on_add_account_click();
		void on_get_client_click();
		void on_view_click();
		void on_get_account_click();
		void on_deposit_click();
		void on_withdraw_click();
		void on_merge_click();
		void on_close_account_click();
		void on_end_of_month_click();
		void on_auto_populate_click();
		Bank bank;

};
