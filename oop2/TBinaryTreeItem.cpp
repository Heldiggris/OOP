#include "TBinaryTreeItem.h"


TBinaryTreeItem::TBinaryTreeItem()
{
    left = nullptr;
    right = nullptr;
}
TBinaryTreeItem::TBinaryTreeItem(Rectangle& rectangle)
{
    this->rectangle = rectangle;
    left = nullptr;
    right = nullptr;
}


int TBinaryTreeItem::Square()
{
    return rectangle.Square();
}

TBinaryTreeItem::~TBinaryTreeItem()
{
    delete left;
    delete right;
}

Rectangle TBinaryTreeItem::GetRectangle() {
    return rectangle;
}