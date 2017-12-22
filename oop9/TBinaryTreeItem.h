#ifndef TBINARYTREEITEM
#define TBINARYTREEITEM


#include "TAllocationBlock.h"
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

    void* operator new (size_t size);
    void operator delete(void *p);

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

    static TAllocationBlock tbinarytreeitem_allocator;
};

#endif