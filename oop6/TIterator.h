#ifndef TITERATOR_H
#define TITERATOR_H
#include <memory>
#include <iostream>
#include "TStack.h"



template <class node, class T>
class TIterator {
public:
    TIterator(std::shared_ptr<node> n) {
        node_ptr = n;
        stack = std::shared_ptr<TStack<std::shared_ptr<node> > >(new TStack<std::shared_ptr<node> >());
        val = 1;
    }
    ~TIterator() {
        // delete stack;
    }
    std::shared_ptr<T> operator * () {
        return node_ptr->GetFigure();
    }
    
    std::shared_ptr<T> operator -> () {
        return node_ptr->GetFigure();
    }

    void operator ++ () {
        while (true) {
            if (node_ptr->GetLeft() != nullptr && val != 0) {
                stack->Set(node_ptr);
                node_ptr = node_ptr->GetLeft();
                return;
            }
            if (node_ptr->GetRight() != nullptr) {
                node_ptr = node_ptr->GetRight();
                val = 1;
                return;
            }

            if (!stack->Empty()) {
                val = 0;
                node_ptr = stack->Get();
            } else {
                node_ptr = nullptr;
                break;
            }
        }
    }
    
    TIterator operator ++ (int) {
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator == (TIterator const& i) {
        return node_ptr == i.node_ptr;
    }

    bool operator != (TIterator const& i){
        return !(*this == i);
    }
private:
    std::shared_ptr<node > node_ptr;
    
    std::shared_ptr<TStack<std::shared_ptr<node> > > stack;
    int val;
};

#endif