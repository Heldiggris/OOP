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