#include "TBinaryTree.h"


template <class T, class TT>
TBinaryTree<T, TT>::TBinaryTree() {
    head = nullptr;
}

template <class T, class TT>
std::shared_ptr<TBinaryTreeItem<T, TT> > TBinaryTree<T, TT>::find(size_t a)
{
    std::shared_ptr<TBinaryTreeItem<T, TT> > item = head;
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


template <class T, class TT>
std::shared_ptr<TBinaryTreeItem<T, TT> > TBinaryTree<T, TT>::minValueNode(std::shared_ptr<TBinaryTreeItem<T, TT> > root)
{
    std::shared_ptr<TBinaryTreeItem<T, TT> > min = root;
 
    while (min->left != nullptr)
        min = min->left;
 
    return min;
}

template <class T, class TT>
std::shared_ptr<TBinaryTreeItem<T, TT> > TBinaryTree<T, TT>::deleteNode(std::shared_ptr<TBinaryTreeItem<T, TT> > root, size_t square, size_t num)
{
    if (root == nullptr) return root;
 
    if (square < root->Square())
        root->left = deleteNode(root->left, square, num);
    else if (square > root->Square())
        root->right = deleteNode(root->right, square, num);
    else {
        if (root->figure && num == 0) {
            if (root->figure->Size() > 1) {
                root->figure->Get()->Print();
                return root;
            } else if (root->figure->Size() == 1) {
                root->figure->Get()->Print();
            }
        }
        num++;

        if (root->left == nullptr) {
            std::shared_ptr<TBinaryTreeItem<T, TT> > temp = root->right;
            root->left = nullptr;
            root->right = nullptr;
            // root->figure->Get()->Print();
            return temp;
        }
        else if (root->right == nullptr) {
            std::shared_ptr<TBinaryTreeItem<T, TT> > temp = root->left;
            root->left = nullptr;
            root->right = nullptr;
            // root->figure->Get()->Print();
            return temp;
        }
 
        std::shared_ptr<TBinaryTreeItem<T, TT> > temp = minValueNode(root->right);
        root->figure = temp->figure;
        root->right = deleteNode(root->right, temp->Square(), num);
    }
    return root;
}


template <class T, class TT>
void TBinaryTree<T, TT>::remove(size_t a)
{
    head = TBinaryTree<T, TT>::deleteNode(head, a, 0);
}


template <class T, class TT>
void TBinaryTree<T, TT>::insert(std::shared_ptr<TT> figure)
{
    if (head == nullptr) {
        head = std::shared_ptr<TBinaryTreeItem<T, TT> >(new TBinaryTreeItem<T, TT>(figure));
        return;
    }

    std::shared_ptr<TBinaryTreeItem<T, TT> > item = head;
    while (true) {
        if ((figure->Square() == item->Square()) && item->figure->Size() < 5) {
            item->figure->Set(std::shared_ptr<Figure>(figure));
            break;
        }
        else if (figure->Square() <= item->Square()) {
            if (item->left == nullptr) {
                item->left = std::shared_ptr<TBinaryTreeItem<T, TT> >(new TBinaryTreeItem<T, TT>(figure));
                break;
            }
            else {
                item = item->left;
            }
        }
        else {
            if (item->right == nullptr) {
                item->right = std::shared_ptr<TBinaryTreeItem<T, TT> >(new TBinaryTreeItem<T, TT>(figure));
                break;
            }
            else {
                item = item->right;
            }
        }
    }
}

template <class T, class TT>
void TBinaryTree<T, TT>::print_tree(std::shared_ptr<TBinaryTreeItem<T, TT> > item, size_t a, std::ostream& os)
{
    for (size_t i = 0; i < a; i++) {
        os << "  ";
    }
    os << item->Square() << "(" << item->GetFigure()->Size() << ")" << std::endl;
    if (item->GetLeft() != nullptr) {
        TBinaryTree<T, TT>::print_tree(item->GetLeft(), a + 1, os);
    }
    else if (item->GetRight() != nullptr) {
        for (size_t i = 0; i <= a; i++) {
            os << "  ";
        }
        os << "null" << std::endl;
    }
    if (item->right != nullptr) {
        TBinaryTree<T, TT>::print_tree(item->GetRight(), a + 1, os);
    }
    else if (item->GetLeft() != nullptr) {
        for (size_t i = 0; i <= a; i++) {
            os << "  ";
        }
        os << "null" << std::endl;
    }
}


template <class T, class TT>
 void TBinaryTree<T, TT>::print()
{
    if (head != nullptr) {
        TBinaryTree<T, TT>::print_tree(head, 0, std::cout);
    }
}

template <class T, class TT>
 void TBinaryTree<T, TT>::print(std::ostream& os)
{
    if (head != nullptr) {
        TBinaryTree<T, TT>::print_tree(head, 0, os);
    }
}

template <class T, class TT>
 bool TBinaryTree<T, TT>::empty()
{
    return head == nullptr;
}

template <class T, class TT>
 TBinaryTree<T, TT>::~TBinaryTree() 
{
}


template <class T, class TT>  TIterator<TBinaryTreeItem<T, TT>, T > TBinaryTree<T, TT>::begin()
{
    return TIterator<TBinaryTreeItem<T, TT>, T >(head);
}

template <class T, class TT>  TIterator<TBinaryTreeItem<T, TT>, T > TBinaryTree<T, TT>::end()
{
    return TIterator<TBinaryTreeItem<T, TT>, T >(nullptr);
}





template class TBinaryTree<TStack<std::shared_ptr<Figure> >, Figure>;

template <class A, class AA>
std::ostream& operator<<(std::ostream& os, TBinaryTree<A, AA>& tree) {
    tree.print(os);
    return os;
}


template std::ostream& operator<<(std::ostream& os, TBinaryTree<TStack<std::shared_ptr<Figure> >, Figure>& tree);
