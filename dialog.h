#include <vector>
#include <iostream>
#include <gtkmm.h>


class Dialogs
{
public:
    static void message(std::string msg, std::string title);
    static std::string input(std::string msg, 
                        std::string title, 
                        std::string default_text = "",
                        std::string cancel_text = "CANCEL");
   static int question(std::string msg, 
                        std::string title, 
                        std::vector<std::string> buttons);
    static void image(std::string filename, std::string title, std::string msg);
private:
};
