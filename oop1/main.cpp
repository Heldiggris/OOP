#include <cstdlib>
#include <string>
#include "Trapeze.h" 
#include "Quadrate.h" 
#include "Rectangle.h"

void print_help() {
    std::cout << "'q'                or 'quit'  - Exit the program"  << std::endl;
    
    std::cout << "'create_quadrate'  or 'cr_qd' - Create quadrate"   << std::endl;
    std::cout << "'create_rectangle' or 'cr_rc' - Create rectangle"  << std::endl;
    std::cout << "'create_trapeze'   or 'cr_tr' - Create trapeze"    << std::endl;
    
    std::cout << "'print'            or 'pr'    - Output parameters" << std::endl;

    std::cout << "'square'           or 'sq'    - Output square"     << std::endl;

    std::cout << "'help'             or 'h'     - Get help"          << std::endl;
}


int main(int argc, char** argv)
{   

    print_help();


    Figure* figure = nullptr;
    std::string action_figure = "q";

    while (true) {
        if (std::cin.eof())
            break;
        std::cin.clear();
        std::cin.sync();
        std::cout << std::endl << "Select an action" << std::endl;
        std::cin >> action_figure;
        if (std::cin.eof())
            break;

        if (action_figure == "quit" || action_figure == "q") {
            break;
        }
        else if (action_figure == "create_quadrate" || action_figure == "cr_qd") {
            if (figure != nullptr)
                delete figure;
            std::cout << "Enter the side of the quadrate" << std::endl;
            figure = new Quadrate(std::cin);
        }
        else if (action_figure == "create_rectangle" || action_figure == "cr_rc") {
            if (figure != nullptr)
                delete figure;
            std::cout << "Enter the adjacent sides of the rectangle" << std::endl;
            figure = new Rectangle(std::cin);
        }
        else if (action_figure == "create_trapeze" || action_figure == "cr_tr") {
            if (figure != nullptr)
                delete figure;
            std::cout << "Enter the bigger, lower bases, left and right sides" << std::endl;
            figure = new Trapeze(std::cin);
        }
        else if (action_figure == "print" || action_figure == "pr") {
            if (figure == nullptr) {
                std::cout << "Figure not created";
            }
            else {
                figure->Print();
            }
        }
        else if (action_figure == "square" || action_figure == "sq") {
            if (figure == nullptr) {
                std::cout << "Figure not created";
            }
            else {
                std::cout << "S = " << figure->Square() << std::endl;
            }
        }
        else if (action_figure == "help" || action_figure == "h") {
            print_help();
        }
        else {
            // std::cout << "Action not found, enter 'h' for help" << std::endl;
        }
    }
    if (figure != nullptr) {
        delete figure;
    }
    return 0;
}