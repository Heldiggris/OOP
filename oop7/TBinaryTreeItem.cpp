#include "TBinaryTreeItem.h"
#include <memory>

// template class TBinaryTreeItem<Figure>;
template class TBinaryTreeItem<TStack<std::shared_ptr<Figure> >, Figure >;


template <class T, class TT>
TBinaryTreeItem<T, TT>::TBinaryTreeItem()
{
    this->figure = std::shared_ptr<T>(new T);
    left = nullptr;
    right = nullptr;
}

template <class T, class TT>
TBinaryTreeItem<T, TT>::TBinaryTreeItem(std::shared_ptr<TT> figure)
{
    if (this->figure == nullptr) {
        this->figure = std::shared_ptr<T>(new T);
    }
    this->figure->Set(figure);
    left = nullptr;
    right = nullptr;
}

template <class T, class TT>

size_t TBinaryTreeItem<T, TT>::Square()
{
    return figure->GetElem()->Square();
}

template <class T, class TT>
TBinaryTreeItem<T, TT>::~TBinaryTreeItem()
{
    // delete left;
    // delete right;
}

template <class T, class TT>
std::shared_ptr<T> TBinaryTreeItem<T, TT>::GetFigure()
{
    return figure;
}

template <class T, class TT>
std::shared_ptr<TBinaryTreeItem<T, TT> > TBinaryTreeItem<T, TT>::GetLeft()
{
    return left;
}

template <class T, class TT>
std::shared_ptr<TBinaryTreeItem<T, TT> > TBinaryTreeItem<T, TT>::GetRight()
{
    return right;
}

template <class T, class TT>
TAllocationBlock TBinaryTreeItem<T, TT>::tbinarytreeitem_allocator(sizeof(TBinaryTreeItem<T, TT>), 100);

template <class T, class TT> void * TBinaryTreeItem<T, TT>::operator new (size_t size) {
    return tbinarytreeitem_allocator.allocate();
}

template <class T, class TT> void TBinaryTreeItem<T, TT>::operator delete(void *p) {
    tbinarytreeitem_allocator.deallocate(p);
}