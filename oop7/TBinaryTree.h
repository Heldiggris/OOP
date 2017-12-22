#ifndef TBINARYTREE
#define TBINARYTREE

#include "TBinaryTreeItem.h"
#include "TIterator.h"
#include <memory>
#include <stdlib.h>
#include <iostream>


template <class T, class TT>
class TBinaryTree
{
public:
    template <class A, class AA>
    friend std::ostream& operator<<(std::ostream& os, TBinaryTree<A, AA>& tree);

    TBinaryTree();
    std::shared_ptr<TBinaryTreeItem<T, TT> > find(size_t square);
    void remove(size_t square);
    void insert(std::shared_ptr<TT> figure);
    void print();
    void print(std::ostream& os);
    bool empty();
    TIterator<TBinaryTreeItem<T, TT>, T > begin();
    TIterator<TBinaryTreeItem<T, TT>, T > end();
    virtual ~TBinaryTree();

private:
    std::shared_ptr<TBinaryTreeItem<T, TT> > head;
    std::shared_ptr<TBinaryTreeItem<T, TT> > minValueNode(std::shared_ptr<TBinaryTreeItem<T, TT> > root);
    std::shared_ptr<TBinaryTreeItem<T, TT> > deleteNode(std::shared_ptr<TBinaryTreeItem<T, TT> > root, size_t square, size_t);
    void print_tree(std::shared_ptr<TBinaryTreeItem<T, TT> > item, size_t a, std::ostream& os);
};

#endif