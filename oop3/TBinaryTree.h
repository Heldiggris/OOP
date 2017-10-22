#ifndef TBINARYTREE
#define TBINARYTREE

#include "TBinaryTreeItem.h"
#include <memory>

class TBinaryTree
{
public:
    friend std::ostream& operator<<(std::ostream& os, TBinaryTree& tree);
    TBinaryTree();
    std::shared_ptr<TBinaryTreeItem> find(size_t square);
    void remove(size_t square);
    void insert(std::shared_ptr<Figure> figure);
    void print();
    void print(std::ostream& os);
    bool empty();
    virtual ~TBinaryTree();

private:
    std::shared_ptr<TBinaryTreeItem> head;
    std::shared_ptr<TBinaryTreeItem> minValueNode(std::shared_ptr<TBinaryTreeItem> root);
    std::shared_ptr<TBinaryTreeItem> deleteNode(std::shared_ptr<TBinaryTreeItem> root, size_t square);
    void print_tree(std::shared_ptr<TBinaryTreeItem> item, size_t a, std::ostream& os);
};

#endif