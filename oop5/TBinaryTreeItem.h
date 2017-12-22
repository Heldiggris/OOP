#ifndef TBINARYTREEITEM
#define TBINARYTREEITEM

#include "Rectangle.h"
#include "Quadrate.h"
#include "Trapeze.h"
#include <memory>

template <class T>
class TBinaryTree;

template <class T>
class TBinaryTreeItem
{
public:
    TBinaryTreeItem();
    TBinaryTreeItem(std::shared_ptr<T> figure);

    int Square();
    std::shared_ptr<T> GetFigure();
    std::shared_ptr<TBinaryTreeItem<T> > GetLeft();
    std::shared_ptr<TBinaryTreeItem<T> > GetRight();
    ~TBinaryTreeItem();
    friend TBinaryTree<T>;
private:
    std::shared_ptr<T> figure;
    std::shared_ptr<TBinaryTreeItem<T> > left;
    std::shared_ptr<TBinaryTreeItem<T> > right;
};

#endif