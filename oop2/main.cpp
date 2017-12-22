#include <string>
#include <iostream>

#include "Rectangle.h"
#include "TBinaryTree.h"


int main(int argc, char** argv) {   

    TBinaryTree *tree = new TBinaryTree();
    std::string action;

    std::cout << "Введите 'h' или 'help' для получения справки." << std::endl;
    while (!std::cin.eof()) {
        std::cin.clear();
        std::cin.sync();
        std::cin >> action;

        if (action == "q" || action == "quit") {
            break;
        }
        else if (action == "insert" || action == "ins") {
            size_t size_a, size_b;
            if (!(std::cin >> size_a >> size_b)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->insert(Rectangle(size_a, size_b));
        }
        else if (action == "remove" || action == "r") {
            size_t square;
            if (!(std::cin >> square)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->remove(square);
        }
        else if (action == "find" || action == "f") {
            if (tree->empty()) {
                std::cout << "Дерево пустое." << std::endl;
                continue;
            }
            size_t square;
            if (!(std::cin >> square)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            TBinaryTreeItem* rect = tree->find(square);
            if (rect != nullptr) {
                rect->GetRectangle().Print();
            } else {
                std::cout << "Прямоугольник не найден." << std::endl;
            }
            
        }
        else if (action == "destroy" || action == "d") {
            delete tree;
            tree = new TBinaryTree();
            std::cout << "Дерево удалено." << std::endl;
        }
        else if (action == "print" || action == "p") {
            if (!tree->empty()) {
                std::cout << *tree << std::endl;
            } else {
                std::cout << "Дерево пустое." << std::endl;
            }
        }
        else if (action == "help" || action == "h") {
            std::cout << "'q'   или 'quit'       - выйти из программы." << std::endl;
            std::cout << "'r'   или 'remove s'   - удалить прямоугольник с площадью s." << std::endl;
            std::cout << "'f'   или 'find s'     - найти прямоугольник с площадью s." << std::endl;
            std::cout << "'d'   или 'destroy'    - удалить дерево." << std::endl;
            std::cout << "'p'   или 'print'      - вывести дерево." << std::endl;
            std::cout << "'ins' или 'insert a b' - вставить прямоугольник в дерево." << std::endl;
            std::cout << "'h'   или 'help'       - вывести справку." << std::endl;
        }
        action = " ";
    }

    delete tree;
    return 0;
}