#include <string>
#include <iostream>

#include "Quadrate.h"
#include "Trapeze.h"
#include "Rectangle.h"
#include "TBinaryTree.h"
#include <memory>


int main(int argc, char** argv)
{   

    std::shared_ptr<TBinaryTree> tree = std::shared_ptr<TBinaryTree>(new TBinaryTree());
    std::string action;

    std::cout << "Введите 'h' или 'help' для получения справки." << std::endl;
    while (!std::cin.eof()) {
        std::cin.clear();
        std::cin.sync();
        std::cin >> action;

        if (action == "q" || action == "quit") {
            break;
        }
        else if (action == "insertR" || action == "ins_r") {
            size_t size_a, size_b;
            if (!(std::cin >> size_a >> size_b)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->insert(std::shared_ptr<Figure>(new Rectangle(size_a, size_b)));
        }
        else if (action == "insertQ" || action == "ins_q") {
            size_t size_a;
            if (!(std::cin >> size_a)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->insert(std::shared_ptr<Figure>(new Quadrate(size_a)));
        }
        else if (action == "insertT" || action == "ins_t") {
            size_t size_b, size_s, size_l, size_r;
            if (!(std::cin >> size_b >> size_s >> size_l >> size_r)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->insert(std::shared_ptr<Figure>(new Trapeze(size_b, size_s, size_l, size_r)));
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
            std::shared_ptr<TBinaryTreeItem> rect = tree->find(square);
            if (rect != nullptr) {
                rect->GetFigure()->Print();
            } else {
                std::cout << "Фигура не найдена." << std::endl;
            }
            
        }
        else if (action == "destroy" || action == "d") {
            tree = std::shared_ptr<TBinaryTree>(new TBinaryTree());
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
            std::cout << "'q'     или 'quit'            - выйти из программы."                 << std::endl;
            std::cout << "'r'     или 'remove s'        - удалить фигуру с площадью s." << std::endl;
            std::cout << "'f'     или 'find s'          - найти фигуру с площадью s."   << std::endl;
            std::cout << "'d'     или 'destroy'         - удалить дерево."                     << std::endl;
            std::cout << "'p'     или 'print'           - вывести дерево."                     << std::endl;
            std::cout << "'ins_r' или 'insertR a b'     - вставить прямоугольник в дерево."    << std::endl;
            std::cout << "'ins_q' или 'insertQ a'       - вставить квадрат в дерево."          << std::endl;
            std::cout << "'ins_t' или 'insertT b s l r' - вставить трапецию в дерево."         << std::endl;
            std::cout << "'h'     или 'help'            - вывести справку."                    << std::endl;
        }
        action = " ";
    }

    return 0;
}