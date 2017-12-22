#include <string>
#include <iostream>

#include "Quadrate.h"
#include "Trapeze.h"
#include "Rectangle.h"
#include "TBinaryTree.h"
#include <memory>
#include <algorithm>

int main(int argc, char** argv)
{   


    std::shared_ptr<TBinaryTree<Figure> > tree = std::shared_ptr<TBinaryTree<Figure> >(new TBinaryTree<Figure>());
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
            size_t side_a, side_b;
            if (!(std::cin >> side_a >> side_b)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->insert(std::shared_ptr<Figure>(new Rectangle(side_a, side_b)));
        }
        else if (action == "insertQ" || action == "ins_q") {
            size_t side_a;
            if (!(std::cin >> side_a)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->insert(std::shared_ptr<Figure>(new Quadrate(side_a)));
        }
        else if (action == "insertT" || action == "ins_t") {
            size_t side_b, size_s, side_l, side_r;
            if (!(std::cin >> side_b >> size_s >> side_l >> side_r)) {
                std::cout << "Неверное значение." << std::endl;
                continue;
            }
            tree->insert(std::shared_ptr<Figure>(new Trapeze(side_b, size_s, side_l, side_r)));
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
            std::shared_ptr<TBinaryTreeItem<Figure> > rect = tree->find(square);
            if (rect != nullptr) {
                rect->GetFigure()->Print();
            } else {
                std::cout << "Фигура не найдена." << std::endl;
            }
            
        }
        else if (action == "destroy" || action == "d") {
            tree = std::shared_ptr<TBinaryTree<Figure> >(new TBinaryTree<Figure>());
            std::cout << "Дерево удалено." << std::endl;
        }
        else if (action == "print" || action == "p") {
            if (!tree->empty()) {
                std::cout << *tree << std::endl;
            } else {
                std::cout << "Дерево пустое." << std::endl;
            }
        }
        else if (action == "iter" || action == "it") {
            if (!tree->empty()) {
                for (auto i : *tree) {
                    i->GetFigure()->Print();
                }
            } else {
                std::cout << "Дерево пустое." << std::endl;
            }
        }
        else if (action == "sort" || action == "s") {
            if (tree->empty()) {
                std::cout << "Дерево пустое." << std::endl;
                continue;
            }
            tree->Sort();
        }
        else if (action == "sort_p" || action == "sp") {
            if (tree->empty()) {
                std::cout << "Дерево пустое." << std::endl;
                continue;
            }
            tree->SortP();
        }

        else if (action == "help" || action == "h") {
            std::cout << "'q'       или 'quit'            - выйти из программы."                 << std::endl;
            std::cout << "'r'       или 'remove s'        - удалить фигуру с площадью s."        << std::endl;
            std::cout << "'f'       или 'find s'          - найти фигуру с площадью s."          << std::endl;
            std::cout << "'d'       или 'destroy'         - удалить дерево."                     << std::endl;
            std::cout << "'p'       или 'print'           - вывести дерево."                     << std::endl;
            std::cout << "'ins_r'   или 'insertR a b'     - вставить прямоугольник в дерево."    << std::endl;
            std::cout << "'ins_q'   или 'insertQ a'       - вставить квадрат в дерево."          << std::endl;
            std::cout << "'ins_t'   или 'insertT b s l r' - вставить трапецию в дерево."         << std::endl;
            std::cout << "'iter'    или 'it'              - выполнить итерацию по дереву"        << std::endl;
            std::cout << "'sort'    или 's'               - отсортировать дерево"                << std::endl;
            std::cout << "'sort_p'  или 'sp'              - параллельно отсортировать дерево"    << std::endl;
            std::cout << "'h'       или 'help'            - вывести справку."                    << std::endl;
        }
        action = " ";
    }

    return 0;
}