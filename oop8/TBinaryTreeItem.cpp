#include "TBinaryTreeItem.h"
#include <memory>

template class TBinaryTreeItem<Figure>;

template <class T>
TBinaryTreeItem<T>::TBinaryTreeItem()
{
    left = nullptr;
    right = nullptr;
}

template <class T>
TBinaryTreeItem<T>::TBinaryTreeItem(std::shared_ptr<T> figure)
{
    this->figure = figure;
    left = nullptr;
    right = nullptr;
}

template <class T>
int TBinaryTreeItem<T>::Square()
{
    return figure->Square();
}

template <class T>
TBinaryTreeItem<T>::~TBinaryTreeItem()
{
    // delete left;
    // delete right;
}

template <class T>
std::shared_ptr<T> TBinaryTreeItem<T>::GetFigure()
{
    return figure;
}

template <class T>
std::shared_ptr<TBinaryTreeItem<T> > TBinaryTreeItem<T>::GetLeft()
{
    return left;
}

template <class T>
std::shared_ptr<TBinaryTreeItem<T> > TBinaryTreeItem<T>::GetRight()
{
    return right;
}




template <class T>
TAllocationBlock TBinaryTreeItem<T>::tbinarytreeitem_allocator(sizeof(TBinaryTreeItem<T>), 100);

template <class T> void * TBinaryTreeItem<T>::operator new (size_t size) {
    return tbinarytreeitem_allocator.allocate();
}

template <class T> void TBinaryTreeItem<T>::operator delete(void *p) {
    tbinarytreeitem_allocator.deallocate(p);
}