#ifndef TBINARYTREEITEM
#define TBINARYTREEITEM


#include "TAllocationBlock.h"
#include "Rectangle.h"
#include "Quadrate.h"
#include "Trapeze.h"
#include <memory>

template <class T, class TT>
class TBinaryTree;

template <class T, class TT>
class TBinaryTreeItem
{
public:
    TBinaryTreeItem();
    TBinaryTreeItem(std::shared_ptr<TT> figure);

    void* operator new (size_t size);
    void operator delete(void *p);

    size_t Square();
    std::shared_ptr<T> GetFigure();
    std::shared_ptr<TBinaryTreeItem<T, TT> > GetLeft();
    std::shared_ptr<TBinaryTreeItem<T, TT> > GetRight();
    ~TBinaryTreeItem();
    friend TBinaryTree<T, TT>;
private:
    std::shared_ptr<T> figure;
    std::shared_ptr<TBinaryTreeItem<T, TT> > left;
    std::shared_ptr<TBinaryTreeItem<T, TT> > right;

    static TAllocationBlock tbinarytreeitem_allocator;
};

#endif