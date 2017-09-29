#ifndef TBINARYTREEITEM
#define TBINARYTREEITEM

#include "Rectangle.h"


class TBinaryTree;

class TBinaryTreeItem
{
public:
    TBinaryTreeItem();
    TBinaryTreeItem(Rectangle& rectangle);

    int Square();
    Rectangle GetRectangle();
    ~TBinaryTreeItem();
    friend TBinaryTree;
private:
    Rectangle rectangle;
    TBinaryTreeItem* left;
    TBinaryTreeItem* right;
};

#endif