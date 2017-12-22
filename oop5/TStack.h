#ifndef TSTACK_H
#define TSTACK_H

#include <memory>

template <class T>
class TStack {
public:
    class TStackItem {
    private:
        friend TStack;
        std::shared_ptr<TStackItem> prev;
        T node;
    public:
        TStackItem() {
            prev = nullptr;
        }
    };

    TStack() {
        head = nullptr;
    }
    ~TStack() {
    }
    T Get() {
        if (head == nullptr) {
            return nullptr;
        }
        head->node;
        std::shared_ptr<TStackItem> tmp = head;
        head = head->prev;
        return tmp->node;
    }

    void Set(T el) {
        std::shared_ptr<TStackItem> item(new TStackItem());
        item->node = el;
        item->prev = head;
        head = item;
    }

    bool Empty() {
        return head == nullptr;
    }

private:
    std::shared_ptr<TStackItem> head;
};

#endif