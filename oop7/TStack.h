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
        size = 0;
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
        size--;
        return tmp->node;
    }

    void Set(T el) {
        std::shared_ptr<TStackItem> item(new TStackItem());
        item->node = el;
        item->prev = head;
        head = item;
        size++;
    }

    bool Empty() {
        return head == nullptr;
    }

    size_t Size() {
        return size;
    }

    T GetElem() {
        return head->node;
    }

private:
    size_t size;
    std::shared_ptr<TStackItem> head;
};

#endif