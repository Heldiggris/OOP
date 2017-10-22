#include "TBinaryTreeItem.h"
#include <memory>

TBinaryTreeItem::TBinaryTreeItem()
{
    left = nullptr;
    right = nullptr;
}
TBinaryTreeItem::TBinaryTreeItem(std::shared_ptr<Figure> figure)
{
    this->figure = figure;
    left = nullptr;
    right = nullptr;
}


int TBinaryTreeItem::Square()
{
    return figure->Square();
}

TBinaryTreeItem::~TBinaryTreeItem()
{
    // delete left;
    // delete right;
}

std::shared_ptr<Figure> TBinaryTreeItem::GetFigure() {
    return figure;
}