#include "TBinaryTree.h"

template <class T>
TBinaryTree<T>::TBinaryTree() {
    head = nullptr;
}

template <class T>
std::shared_ptr<TBinaryTreeItem<T> > TBinaryTree<T>::find(size_t a)
{
    std::shared_ptr<TBinaryTreeItem<T> > item = head;
    while (item != nullptr) {
        if (item->Square() == a) {
            return item;
        }
        else if (item->Square() > a) {
            item = item->left;
        }
        else if (item->Square() < a) {
            item = item->right;
        }
    }
    return nullptr;
}


template <class T>
std::shared_ptr<TBinaryTreeItem<T> > TBinaryTree<T>::minValueNode(std::shared_ptr<TBinaryTreeItem<T> > root)
{
    std::shared_ptr<TBinaryTreeItem<T> > min = root;
 
    while (min->left != nullptr)
        min = min->left;
 
    return min;
}

template <class T>
std::shared_ptr<TBinaryTreeItem<T> > TBinaryTree<T>::deleteNode(std::shared_ptr<TBinaryTreeItem<T> > root, size_t square)
{
    if (root == nullptr) return root;
 
    if (square < root->Square())
        root->left = deleteNode(root->left, square);
    else if (square > root->Square())
        root->right = deleteNode(root->right, square);
    else {
        if (root->left == nullptr) {
            std::shared_ptr<TBinaryTreeItem<T> > temp = root->right;
            root->left = nullptr;
            root->right = nullptr;
            return temp;
        }
        else if (root->right == nullptr) {
            std::shared_ptr<TBinaryTreeItem<T> > temp = root->left;
            root->left = nullptr;
            root->right = nullptr;
            return temp;
        }
 
        std::shared_ptr<TBinaryTreeItem<T> > temp = minValueNode(root->right);
        root->figure = temp->figure;
        root->right = deleteNode(root->right, temp->Square());
    }
    return root;
}


template <class T>
void TBinaryTree<T>::remove(size_t a)
{
    head = TBinaryTree<T>::deleteNode(head, a);
}


template <class T>
void TBinaryTree<T>::insert(std::shared_ptr<T> figure)
{
    if (head == nullptr) {
        head = std::shared_ptr<TBinaryTreeItem<T> >(new TBinaryTreeItem<T>(figure));
        return;
    }


    std::shared_ptr<TBinaryTreeItem<T> > item = head;
    while (true) {
        if (figure->Square() < item->Square()) {
            if (item->left == nullptr) {
                item->left = std::shared_ptr<TBinaryTreeItem<T> >(new TBinaryTreeItem<T>(figure));
                break;
            }
            else {
                item = item->left;
            }
        }
        else {
            if (item->right == nullptr) {
                item->right = std::shared_ptr<TBinaryTreeItem<T> >(new TBinaryTreeItem<T>(figure));
                break;
            }
            else {
                item = item->right;
            }
        }
    }
}

template <class T>
void TBinaryTree<T>::print_tree(std::shared_ptr<TBinaryTreeItem<T> > item, size_t a, std::ostream& os)
{
    for (size_t i = 0; i < a; i++) {
        os << "  ";
    }
    os << item->Square() << std::endl;
    if (item->left != nullptr) {
        TBinaryTree<T>::print_tree(item->left, a + 1, os);
    }
    else if (item->right != nullptr) {
        for (size_t i = 0; i <= a; i++) {
            os << "  ";
        }
        os << "null" << std::endl;
    }
    if (item->right != nullptr) {
        TBinaryTree<T>::print_tree(item->right, a + 1, os);
    }
    else if (item->left != nullptr) {
        for (size_t i = 0; i <= a; i++) {
            os << "  ";
        }
        os << "null" << std::endl;
    }
}


template <class T>
void TBinaryTree<T>::print()
{
    if (head != nullptr) {
        TBinaryTree<T>::print_tree(head, 0, std::cout);
    }
}

template <class T>
void TBinaryTree<T>::print(std::ostream& os)
{
    if (head != nullptr) {
        TBinaryTree<T>::print_tree(head, 0, os);
    }
}

template <class T>
bool TBinaryTree<T>::empty()
{
    return head == nullptr;
}

template <class T>
TBinaryTree<T>::~TBinaryTree() 
{
}

template <class A>
std::ostream& operator<<(std::ostream& os, TBinaryTree<A>& tree) {
    tree.print(os);
    return os;
}

template class TBinaryTree<Figure>;
template std::ostream& operator<<(std::ostream& os, TBinaryTree<Figure>& tree);



template <class T>
TIterator<TBinaryTreeItem<T>,T> TBinaryTree<T>::begin()
{
    return TIterator<TBinaryTreeItem<T>,T>(head);
}

template <class T>
TIterator<TBinaryTreeItem<T>,T> TBinaryTree<T>::end()
{
    return TIterator<TBinaryTreeItem<T>,T>(nullptr);
}


template <class T>
void TBinaryTree<T>::qsort(TStack<std::shared_ptr<TBinaryTreeItem<T> > >& stack) {
    if (stack.Size() > 1) {
        std::shared_ptr<TBinaryTreeItem<T> > middle = stack.Get();
        TStack<std::shared_ptr<TBinaryTreeItem<T> > > left, right;
        while (!stack.Empty()) {

            std::shared_ptr<TBinaryTreeItem<T> > item = stack.Get();

            if (item->GetFigure()->Square() < middle->GetFigure()->Square()) {
                left.Set(item);
            } 
            else {
                right.Set(item);
            }
        }
        TBinaryTree<T>::qsort(left);
        TBinaryTree<T>::qsort(right);


        left.Reverse();
        while (!left.Empty()) {
            stack.Set(left.Get());
        }

        stack.Set(middle);

        right.Reverse();
        while (!right.Empty()) { 
            stack.Set(right.Get());
        }
    }

}






template<class T > std::future<void> TBinaryTree<T>::sort_in_background(TStack<std::shared_ptr<TBinaryTreeItem<T> > >& stack) {
    std::packaged_task<void(void) > task(std::bind(std::mem_fn(&TBinaryTree<T>::qsort_p), this, std::ref(stack) ));
    
    std::future<void> res(task.get_future());
    
    std::thread th(std::move(task));
    
    th.detach();
    
    return res;
}


template <class T>
void TBinaryTree<T>::qsort_p(TStack<std::shared_ptr<TBinaryTreeItem<T> > >& stack) {
    if (stack.Size() > 1) {
        std::shared_ptr<TBinaryTreeItem<T> > middle = stack.Get();
        TStack<std::shared_ptr<TBinaryTreeItem<T> > > left, right;
        while (!stack.Empty()) {

            std::shared_ptr<TBinaryTreeItem<T> > item = stack.Get();

            if (item->GetFigure()->Square() < middle->GetFigure()->Square()) {
                left.Set(item);
            } 
            else {
                right.Set(item);
            }
        }

        std::future<void> left_res = sort_in_background(left);
        std::future<void> right_res = sort_in_background(right);

        left_res.get();
        left.Reverse();
        while (!left.Empty()) {
            stack.Set(left.Get());
        }

        stack.Set(middle);

        right_res.get();
        right.Reverse();
        while (!right.Empty()) { 
            stack.Set(right.Get());
        }
    }

}



template <class T>
void TBinaryTree<T>::Sort()
{
    if (head == nullptr) {
        return;
    }
    TStack<std::shared_ptr<TBinaryTreeItem<T> > > stack;

    for (auto i : *this) {
        stack.Set(i);
    }
    qsort(stack);

    stack.Reverse();
    head = stack.Get();
    std::shared_ptr<TBinaryTreeItem<T> > item = head;
    item->left = nullptr;
    item->right = nullptr;
    while (stack.Size()) {
        std::shared_ptr<TBinaryTreeItem<T> > next = nullptr;
        next = stack.Get();
        next->left = nullptr;
        next->right = nullptr;

        item->right = next;
        item->left = nullptr;
        item = next;
            
    }
}



template <class T>
void TBinaryTree<T>::SortP()
{
    if (head == nullptr) {
        return;
    }
    TStack<std::shared_ptr<TBinaryTreeItem<T> > > stack;

    for (auto i : *this) {
        stack.Set(i);
    }
    qsort_p(stack);

    stack.Reverse();
    head = stack.Get();
    std::shared_ptr<TBinaryTreeItem<T> > item = head;
    item->left = nullptr;
    item->right = nullptr;
    while (stack.Size()) {
        std::shared_ptr<TBinaryTreeItem<T> > next = nullptr;
        next = stack.Get();
        next->left = nullptr;
        next->right = nullptr;

        item->right = next;
        item->left = nullptr;
        item = next;
            
    }
}


// ins_q 43
// ins_q 21
// ins_q 1
// ins_q 657
// ins_q 23
// ins_q 22
// ins_q 12
