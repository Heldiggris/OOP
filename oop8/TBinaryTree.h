#ifndef TBINARYTREE
#define TBINARYTREE

#include "TBinaryTreeItem.h"
#include "TIterator.h"
#include <memory>
#include <mutex>
#include <future>
#include <exception>
#include <functional>

template <class T>
class TBinaryTree
{
public:
    template <class A>
    friend std::ostream& operator<<(std::ostream& os, TBinaryTree<A>& tree);

    TBinaryTree();
    std::shared_ptr<TBinaryTreeItem<T> > find(size_t square);
    void remove(size_t square);
    void insert(std::shared_ptr<T> figure);
    void print();
    void print(std::ostream& os);
    bool empty();
    TIterator<TBinaryTreeItem<T>,T> begin();
    TIterator<TBinaryTreeItem<T>,T> end();
    virtual ~TBinaryTree();
    void Sort();
    void SortP();

private:
    std::future<void> sort_in_background(TStack<std::shared_ptr<TBinaryTreeItem<T> > >& stack);
    void qsort_p(TStack<std::shared_ptr<TBinaryTreeItem<T> > >& stack);
    void qsort(TStack<std::shared_ptr<TBinaryTreeItem<T> > >& stack);
    std::shared_ptr<TBinaryTreeItem<T> > head;
    std::shared_ptr<TBinaryTreeItem<T> > minValueNode(std::shared_ptr<TBinaryTreeItem<T> > root);
    std::shared_ptr<TBinaryTreeItem<T> > deleteNode(std::shared_ptr<TBinaryTreeItem<T> > root, size_t square);
    void print_tree(std::shared_ptr<TBinaryTreeItem<T> > item, size_t a, std::ostream& os);
};

#endif