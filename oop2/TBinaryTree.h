#ifndef TBINARYTREE
#define TBINARYTREE

#include "TBinaryTreeItem.h"

class TBinaryTree
{
public:
    friend std::ostream& operator<<(std::ostream& os, TBinaryTree& tree);
    TBinaryTree();
    TBinaryTreeItem* find(size_t square);
    void remove(size_t square);
    void insert(Rectangle &&rectangle);
    void print();
    void print(std::ostream& os);
    bool empty();
    virtual ~TBinaryTree();

private:
    TBinaryTreeItem* head;
    TBinaryTreeItem* minValueNode(TBinaryTreeItem* root);
    TBinaryTreeItem* deleteNode(TBinaryTreeItem* root, size_t square);
    void print_tree(TBinaryTreeItem* item, size_t a, std::ostream& os);
};

#endif