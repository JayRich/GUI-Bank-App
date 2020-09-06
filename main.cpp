#include "Main_Window.h"

int main(int argc, char* argv[])
{
	Gtk::Main kit(int argc, char* argv[]);
	
	auto app = Gtk::Application::create(argc, argv, "example.bank");
	
	Main_Window win;

	win.set_title("Bank App");

	return app->run(win);
	
	Bank bank;
	
	return 0;
}
