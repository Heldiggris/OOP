#ifndef TBINARYTREEITEM
#define TBINARYTREEITEM

#include "Rectangle.h"
#include "Quadrate.h"
#include "Trapeze.h"
#include <memory>

class TBinaryTree;

class TBinaryTreeItem
{
public:
    TBinaryTreeItem();
    TBinaryTreeItem(std::shared_ptr<Figure> figure);

    int Square();
    std::shared_ptr<Figure> GetFigure();
    ~TBinaryTreeItem();
    friend TBinaryTree;
private:
    std::shared_ptr<Figure> figure;
    std::shared_ptr<TBinaryTreeItem> left;
    std::shared_ptr<TBinaryTreeItem> right;
};

#endif