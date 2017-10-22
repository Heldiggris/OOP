#include "TBinaryTree.h"
#include "TBinaryTreeItem.h"
#include <stdlib.h>
#include <iostream>
#include <memory>

TBinaryTree::TBinaryTree() {
    head = nullptr;
}

std::shared_ptr<TBinaryTreeItem> TBinaryTree::find(size_t a)
{
    std::shared_ptr<TBinaryTreeItem> item = head;
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


std::shared_ptr<TBinaryTreeItem> TBinaryTree::minValueNode(std::shared_ptr<TBinaryTreeItem> root)
{
    std::shared_ptr<TBinaryTreeItem> min = root;
 
    while (min->left != nullptr)
        min = min->left;
 
    return min;
}

std::shared_ptr<TBinaryTreeItem> TBinaryTree::deleteNode(std::shared_ptr<TBinaryTreeItem> root, size_t square)
{
    if (root == nullptr) return root;
 
    if (square < root->Square())
        root->left = deleteNode(root->left, square);
    else if (square > root->Square())
        root->right = deleteNode(root->right, square);
    else {
        if (root->left == nullptr) {
            std::shared_ptr<TBinaryTreeItem> temp = root->right;
            root->left = nullptr;
            root->right = nullptr;
            return temp;
        }
        else if (root->right == nullptr) {
            std::shared_ptr<TBinaryTreeItem> temp = root->left;
            root->left = nullptr;
            root->right = nullptr;
            return temp;
        }
 
        std::shared_ptr<TBinaryTreeItem> temp = minValueNode(root->right);
        root->figure = temp->figure;
        root->right = deleteNode(root->right, temp->Square());
    }
    return root;
}


void TBinaryTree::remove(size_t a)
{
    head = TBinaryTree::deleteNode(head, a);

}

void TBinaryTree::insert(std::shared_ptr<Figure> figure)
{
    if (head == nullptr) {
        head = std::shared_ptr<TBinaryTreeItem>(new TBinaryTreeItem(figure));
        return;
    }


    std::shared_ptr<TBinaryTreeItem> item = head;
    while (true) {
        if (figure->Square() <= item->Square()) {
            if (item->left == nullptr) {
                item->left = std::shared_ptr<TBinaryTreeItem>(new TBinaryTreeItem(figure));
                break;
            }
            else {
                item = item->left;
            }
        }
        else {
            if (item->right == nullptr) {
                item->right = std::shared_ptr<TBinaryTreeItem>(new TBinaryTreeItem(figure));
                break;
            }
            else {
                item = item->right;
            }
        }
    }
}

void TBinaryTree::print_tree(std::shared_ptr<TBinaryTreeItem> item, size_t a, std::ostream& os)
{
    for (size_t i = 0; i < a; i++) {
        os << "  ";
    }
    os << item->Square() << std::endl;
    if (item->left != nullptr) {
        TBinaryTree::print_tree(item->left, a + 1, os);
    }
    else if (item->right != nullptr) {
        for (size_t i = 0; i <= a; i++) {
            os << "  ";
        }
        os << "null" << std::endl;
    }
    if (item->right != nullptr) {
        TBinaryTree::print_tree(item->right, a + 1, os);
    }
    else if (item->left != nullptr) {
        for (size_t i = 0; i <= a; i++) {
            os << "  ";
        }
        os << "null" << std::endl;
    }
}



void TBinaryTree::print()
{
    if (head != nullptr) {
        TBinaryTree::print_tree(head, 0, std::cout);
    }
}

void TBinaryTree::print(std::ostream& os)
{
    if (head != nullptr) {
        TBinaryTree::print_tree(head, 0, os);
    }
}


bool TBinaryTree::empty()
{
    return head == nullptr;
}

TBinaryTree::~TBinaryTree() 
{
}


std::ostream& operator<<(std::ostream& os, TBinaryTree& tree) {
    tree.print(os);
    return os;
}
